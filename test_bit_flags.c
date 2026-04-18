#include <stdio.h>

typedef struct vec3_t
{
	float x, y, z;
} VEC3;
typedef unsigned int RM_FLAG;

#define ABS(x) (((x) < 0) ? -(x) : (x))

#define RM_FLAG_DOUBLE (1 << 0)
#define RM_FLAG_NEGATE (1 << 1)
#define RM_FLAG_SWAP (1 << 2)
#define RM_FLAG_ABS (1 << 3)

void vec3_transform(VEC3 *vec, RM_FLAG flags)
{
	if (flags & RM_FLAG_DOUBLE)
	{
		vec->x = vec->x * 2;
		vec->y = vec->y * 2;
		vec->z = vec->z * 2;
	}
	if (flags & RM_FLAG_NEGATE)
	{
		vec->x = -vec->x;
		vec->y = -vec->y;
		vec->z = -vec->z;
	}
	if (flags & RM_FLAG_SWAP)
	{
		float tmp = vec->x;
		vec->x = vec->z;
		vec->z = tmp;
	}
	if (flags & RM_FLAG_ABS)
	{
		vec->x = ABS(vec->x);
		vec->y = ABS(vec->y);
		vec->z = ABS(vec->z);
	}
}

void print_vec3(VEC3 *vec)
{
	printf("%.2f %.2f %.2f\n", vec->x, vec->y, vec->z);
}

int main(void)
{
	VEC3 a = {1.0f, -2.0f, 3.0f};
	vec3_transform(&a, RM_FLAG_NEGATE);
	print_vec3(&a);

	VEC3 b = {2.0f, 4.0f, 6.0f};
	vec3_transform(&b, RM_FLAG_DOUBLE | RM_FLAG_NEGATE);
	print_vec3(&b);

	VEC3 c = {-5.0f, 3.0f, 1.0f};
	vec3_transform(&c, RM_FLAG_SWAP | RM_FLAG_ABS);
	print_vec3(&c);

	VEC3 d = {-3.0f, 1.0f, -2.0f};
	vec3_transform(&d, RM_FLAG_DOUBLE | RM_FLAG_NEGATE | RM_FLAG_ABS);
	print_vec3(&d);

	return 0;
}
