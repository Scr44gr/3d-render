#include <math.h>
#include "vector.h"

vec3_t vec3_rotate_x(
    vec3_t v,
    float angle)
{
    vec3_t rotated_vector = {
        v.x,
        v.y * cos(angle) - v.z * sin(angle),
        v.y * sin(angle) + v.z * cos(angle)};
    return rotated_vector;
}

vec3_t vec3_rotate_y(
    vec3_t v,
    float angle)
{
    vec3_t rotated_vector = {
        v.x * cos(angle) + v.z * sin(angle),
        v.y,
        -v.x * sin(angle) + v.z * cos(angle)};
    return rotated_vector;
}

vec3_t vec3_rotate_z(
    vec3_t v,
    float angle)
{
    vec3_t rotated_vector = {
        v.x * cos(angle) - v.y * sin(angle),
        v.x * sin(angle) + v.y * cos(angle),
        v.z};
    return rotated_vector;
}

vec3_t vec3_expand(
    vec3_t v,
    float scalar)
{
    vec3_t expanded_vector = {
        v.x * scalar,
        v.y * scalar,
        v.z * scalar};
    return expanded_vector;
}