#include QMK_KEYBOARD_H

#define __________ _______

#define MATTHIAS_SPLIT_35( \
    _q, _w, _e, _r, _t, _y, _u, _i, _o, _p, \
    _a, _s, _d, _f, _g, _h, _j, _k,  _l, _ae, \
    _z, _x, _c, _v, _b, _n, _m, _comma, _dot, _dash, \
    _left_1, _left_2, _left_3, _right_1, _right_2) \
    LAYOUT( \
    _q, _w, _e, _r, _t, _y, _u, _i, _o, _p, \
    _a, _s, _d, _f, _g, _h, _j, _k,  _l, _ae, \
    _z, _x, _c, _v, _b, _n, _m, _comma, _dot, _dash, \
    _left_1, _left_2, _left_3, _right_1, _right_2) \

#include "../../../../../matthias/keymap.c"
