#include "physics.h"

intersection_state g_state = NOT_INTERSECTING;


void
physics_timer_callback(int value)
{
    glutTimerFunc(1000 / FPS, physics_timer_callback, 0);   // Set up next timer 

    move_ball();

    extern float ball_speed;
    extern tree_t g_forest[NUMBER_OF_TREES];
    
    extern intersection_state g_state;
    extern int intersected_tree;

    for (int i = 0; i < NUMBER_OF_TREES; ++i)
    {
		g_forest[i].y += ball_speed;
        
        g_state = check_ball_tree_collision(g_forest[i]);

        if (g_state == INTERSECTING) intersected_tree = i;

        //! @todo: move tree-planting outside
        if (g_forest[i].y - (TREE_HEIGHT2 + TRUNK_HEIGHT) * g_forest[i].size > ORTHO_TOP)
        {
            g_forest[i] = plant_tree(ORTHO_BOTTOM);
        }
	}

	ball_speed += BALL_SPEED_ADD;
}


float
cross2d_product(vector2 a, vector2 b, vector2 p, vector2 q)
{
    return (b.x - a.x) * (q.y - p.y) - (b.y - a.y) * (q.x - p.x);
}


intersection_state
check_segments_intersection(float ab_ap, float ab_aq, float pq_pa, float pq_pb)
{
    // P, Q on opposite sides of AB and A, B on opposite sides of PQ
    if (SIGN(ab_ap) != SIGN(ab_aq) && SIGN(pq_pa) != SIGN(pq_pb))
    {
        return INTERSECTING;
    }
    
    return NOT_INTERSECTING;
}


bool
find_inner(float ab_ap, float ab_aq, float ab_ac, int *inner_count)
{
    //  P, Q on same side of AB and out of triangle
    if (SIGN(ab_ap) == SIGN(ab_aq) && SIGN(ab_ap) != SIGN(ab_ac))
    {
        return FALSE;
    }
    else if (SIGN(ab_ap) != SIGN(ab_ac))    // P or Q on inner side
    {
        inner_count += 1;
    }

    return TRUE;
}


intersection_state
check_segment_triangle_intersection(vector2 p, vector2 q, vector2 a, vector2 b, vector2 c)
{
    // Triangle orientation
    float ab_ac = cross2d_product(a, b, a, c);
    
    bool inner_found;
    int  inner_count = 0;   // Assuming that segment not inside the triangle
    
    intersection_state state;
 
    // Intersection with AB
    float ab_pq = cross2d_product(a, b, p, q);
    float ab_ap = cross2d_product(a, b, a, p);
    float pq_pa = cross2d_product(p, q, p, a);
    
    float ab_aq = ab_ap + ab_pq;
    float pq_pb = pq_pa - ab_pq;    // pq_pa - ab_pq = pq_pa + pq_ab

    inner_found = find_inner(ab_ap, ab_aq, ab_ac, &inner_count);
    if (inner_found == FALSE) return NOT_INTERSECTING;
    else
    {
        state = check_segments_intersection(ab_ap, ab_aq, pq_pa, pq_pb);
        if (state == INTERSECTING) return INTERSECTING;
    }

    // Intersection with BC
    float bc_pq = cross2d_product(b, c, p, q);
    float bc_bp = cross2d_product(b, c, b, p);
    
    float bc_bq = bc_bp + bc_pq;
    float pq_pc = bc_pq - pq_pb;    // {bc_pq = pq_cb} - pq_pb = pq_((b-c)-(b-p)) = pq_(-cp) = pq_pc

    inner_found = find_inner(bc_bp, bc_bq, ab_ac, &inner_count);
    if (inner_found == FALSE) return NOT_INTERSECTING;
    else
    {
        state = check_segments_intersection(bc_bp, bc_bq, pq_pb, pq_pc);
        if (state == INTERSECTING) return INTERSECTING;
    }
    
    // Intersection with BC
    float ca_cp = cross2d_product(c, a, c, p);

    float ca_cq = ca_cp - (pq_pc - pq_pa); // ca_cp - {pq_pc - pq_pa = pq_ca = -ca_pq} = ca_cq

    inner_found = find_inner(ca_cp, ca_cq, ab_ac, &inner_count);
    if (inner_found == FALSE) return NOT_INTERSECTING;
    else
    {
        state = check_segments_intersection(ca_cp, ca_cq, pq_pc, pq_pb);
        if (state == INTERSECTING) return INTERSECTING;
    }
    
    if (inner_count == 3) return INTERSECTING;
    return NOT_INTERSECTING;
}


intersection_state
check_ball_tree_collision(tree_t tree)
{
    extern float ball_x;

    extern int g_SCREEN_WIDTH;
    extern int g_SCREEN_HEIGHT;

    float aspect = (float) g_SCREEN_WIDTH / g_SCREEN_HEIGHT;
    
    //! @todo Segment orientation
    // Ball segment point
    vector2 p = {ball_x, BALL_Y};
    vector2 q = {ball_x - BALL_RADIUS / aspect, BALL_Y};

    // Tree collider points
	vector2 a = {tree.x * aspect, tree.y - tree.size};
    vector2 b = {(tree.x - TREE_WIDTH3 * tree.size) * aspect, tree.y - TREE_HEIGHT2 * tree.size / COLLIDER_SIZE_REDUCTION};
    vector2 c = {(tree.x + TREE_WIDTH3 * tree.size) * aspect, tree.y - TREE_HEIGHT2 * tree.size / COLLIDER_SIZE_REDUCTION};

    return check_segment_triangle_intersection(p, q, a, b, c);
}