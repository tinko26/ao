// ----------------------------------------------------------------------------

// MIT License

// Copyright (c) 2022 Stefan Wagner

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// ----------------------------------------------------------------------------

// LED Driver 3 Click.

// ----------------------------------------------------------------------------

#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_2950

#define AO_MIKROE_2950                              (false)

#endif

// ----------------------------------------------------------------------------

void    ao_mikroe_2950_color(                       size_t i, uint8_t r, uint8_t g, uint8_t b);

// ----------------------------------------------------------------------------

void    ao_mikroe_2950_luminance(                   size_t i, uint8_t l);

// ----------------------------------------------------------------------------

void    ao_mikroe_2950_luminance_down(              size_t i, uint8_t l, ao_time_t t);

void    ao_mikroe_2950_luminance_up(                size_t i, uint8_t l, ao_time_t t);

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_alice_blue

#define ao_mikroe_2950_alice_blue(i)                ao_mikroe_2950_color(i, 0xF0, 0xF8, 0xFF)

#endif

#ifndef ao_mikroe_2950_antique_white

#define ao_mikroe_2950_antique_white(i)             ao_mikroe_2950_color(i, 0xFA, 0xEB, 0xD7)

#endif

#ifndef ao_mikroe_2950_aqua

#define ao_mikroe_2950_aqua(i)                      ao_mikroe_2950_color(i, 0x00, 0xFF, 0xFF)

#endif

#ifndef ao_mikroe_2950_aquamarine

#define ao_mikroe_2950_aquamarine(i)                ao_mikroe_2950_color(i, 0x7F, 0xFF, 0xD4)

#endif

#ifndef ao_mikroe_2950_azure

#define ao_mikroe_2950_azure(i)                     ao_mikroe_2950_color(i, 0xF0, 0xFF, 0xFF)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_beige

#define ao_mikroe_2950_beige(i)                     ao_mikroe_2950_color(i, 0xF5, 0xF5, 0xDC)

#endif

#ifndef ao_mikroe_2950_bisque

#define ao_mikroe_2950_bisque(i)                    ao_mikroe_2950_color(i, 0xFF, 0xE4, 0xC4)

#endif

#ifndef ao_mikroe_2950_black

#define ao_mikroe_2950_black(i)                     ao_mikroe_2950_color(i, 0x00, 0x00, 0x00)

#endif

#ifndef ao_mikroe_2950_blanched_almond

#define ao_mikroe_2950_blanched_almond(i)           ao_mikroe_2950_color(i, 0xFF, 0xEB, 0xCD)

#endif

#ifndef ao_mikroe_2950_blue

#define ao_mikroe_2950_blue(i)                      ao_mikroe_2950_color(i, 0x00, 0x00, 0xFF)

#endif

#ifndef ao_mikroe_2950_blue_violet

#define ao_mikroe_2950_blue_violet(i)               ao_mikroe_2950_color(i, 0x8A, 0x2B, 0xE2)

#endif

#ifndef ao_mikroe_2950_brown

#define ao_mikroe_2950_brown(i)                     ao_mikroe_2950_color(i, 0xA5, 0x2A, 0x2A)

#endif

#ifndef ao_mikroe_2950_burly_wood

#define ao_mikroe_2950_burly_wood(i)                ao_mikroe_2950_color(i, 0xDE, 0xB8, 0x87)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_cadet_blue

#define ao_mikroe_2950_cadet_blue(i)                ao_mikroe_2950_color(i, 0x5F, 0x9E, 0xA0)

#endif

#ifndef ao_mikroe_2950_chartreuse

#define ao_mikroe_2950_chartreuse(i)                ao_mikroe_2950_color(i, 0x7F, 0xFF, 0x00)

#endif

#ifndef ao_mikroe_2950_chocolate

#define ao_mikroe_2950_chocolate(i)                 ao_mikroe_2950_color(i, 0xD2, 0x69, 0x1E)

#endif

#ifndef ao_mikroe_2950_coral

#define ao_mikroe_2950_coral(i)                     ao_mikroe_2950_color(i, 0xFF, 0x7F, 0x50)

#endif

#ifndef ao_mikroe_2950_cornflower_blue

#define ao_mikroe_2950_cornflower_blue(i)           ao_mikroe_2950_color(i, 0x64, 0x95, 0xED)

#endif

#ifndef ao_mikroe_2950_cornsilk

#define ao_mikroe_2950_cornsilk(i)                  ao_mikroe_2950_color(i, 0xFF, 0xF8, 0xDC)

#endif

#ifndef ao_mikroe_2950_crimson

#define ao_mikroe_2950_crimson(i)                   ao_mikroe_2950_color(i, 0xDC, 0x14, 0x3C)

#endif

#ifndef ao_mikroe_2950_cyan

#define ao_mikroe_2950_cyan(i)                      ao_mikroe_2950_color(i, 0x00, 0xFF, 0xFF)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_dark_blue

#define ao_mikroe_2950_dark_blue(i)                 ao_mikroe_2950_color(i, 0x00, 0x00, 0x8B)

#endif

#ifndef ao_mikroe_2950_dark_cyan

#define ao_mikroe_2950_dark_cyan(i)                 ao_mikroe_2950_color(i, 0x00, 0x8B, 0x8B)

#endif

#ifndef ao_mikroe_2950_dark_golden_rod

#define ao_mikroe_2950_dark_golden_rod(i)           ao_mikroe_2950_color(i, 0xB8, 0x86, 0x0B)

#endif

#ifndef ao_mikroe_2950_dark_gray

#define ao_mikroe_2950_dark_gray(i)                 ao_mikroe_2950_color(i, 0xA9, 0xA9, 0xA9)

#endif

#ifndef ao_mikroe_2950_dark_grey

#define ao_mikroe_2950_dark_grey(i)                 ao_mikroe_2950_color(i, 0xA9, 0xA9, 0xA9)

#endif

#ifndef ao_mikroe_2950_dark_green

#define ao_mikroe_2950_dark_green(i)                ao_mikroe_2950_color(i, 0x00, 0x64, 0x00)

#endif

#ifndef ao_mikroe_2950_dark_khaki

#define ao_mikroe_2950_dark_khaki(i)                ao_mikroe_2950_color(i, 0xBD, 0xB7, 0x6B)

#endif

#ifndef ao_mikroe_2950_dark_magenta

#define ao_mikroe_2950_dark_magenta(i)              ao_mikroe_2950_color(i, 0x8B, 0x00, 0x8B)

#endif

#ifndef ao_mikroe_2950_dark_olive_green

#define ao_mikroe_2950_dark_olive_green(i)          ao_mikroe_2950_color(i, 0x55, 0x6B, 0x2F)

#endif

#ifndef ao_mikroe_2950_dark_orange

#define ao_mikroe_2950_dark_orange(i)               ao_mikroe_2950_color(i, 0xFF, 0x8C, 0x00)

#endif

#ifndef ao_mikroe_2950_dark_orchid

#define ao_mikroe_2950_dark_orchid(i)               ao_mikroe_2950_color(i, 0x99, 0x32, 0xCC)

#endif

#ifndef ao_mikroe_2950_dark_red

#define ao_mikroe_2950_dark_red(i)                  ao_mikroe_2950_color(i, 0x8B, 0x00, 0x00)

#endif

#ifndef ao_mikroe_2950_dark_salmon

#define ao_mikroe_2950_dark_salmon(i)               ao_mikroe_2950_color(i, 0xE9, 0x96, 0x7A)

#endif

#ifndef ao_mikroe_2950_dark_sea_green

#define ao_mikroe_2950_dark_sea_green(i)            ao_mikroe_2950_color(i, 0x8F, 0xBC, 0x8F)

#endif

#ifndef ao_mikroe_2950_dark_slate_blue

#define ao_mikroe_2950_dark_slate_blue(i)           ao_mikroe_2950_color(i, 0x48, 0x3D, 0x8B)

#endif

#ifndef ao_mikroe_2950_dark_slate_gray

#define ao_mikroe_2950_dark_slate_gray(i)           ao_mikroe_2950_color(i, 0x2F, 0x4F, 0x4F)

#endif

#ifndef ao_mikroe_2950_dark_slate_grey

#define ao_mikroe_2950_dark_slate_grey(i)           ao_mikroe_2950_color(i, 0x2F, 0x4F, 0x4F)

#endif

#ifndef ao_mikroe_2950_dark_turquoise

#define ao_mikroe_2950_dark_turquoise(i)            ao_mikroe_2950_color(i, 0x00, 0xCE, 0xD1)

#endif

#ifndef ao_mikroe_2950_dark_violet

#define ao_mikroe_2950_dark_violet(i)               ao_mikroe_2950_color(i, 0x94, 0x00, 0xD3)

#endif

#ifndef ao_mikroe_2950_deep_pink

#define ao_mikroe_2950_deep_pink(i)                 ao_mikroe_2950_color(i, 0xFF, 0x14, 0x93)

#endif

#ifndef ao_mikroe_2950_deep_sky_blue

#define ao_mikroe_2950_deep_sky_blue(i)             ao_mikroe_2950_color(i, 0x00, 0xBF, 0xFF)

#endif

#ifndef ao_mikroe_2950_dim_gray

#define ao_mikroe_2950_dim_gray(i)                  ao_mikroe_2950_color(i, 0x69, 0x69, 0x69)

#endif

#ifndef ao_mikroe_2950_dim_grey

#define ao_mikroe_2950_dim_grey(i)                  ao_mikroe_2950_color(i, 0x69, 0x69, 0x69)

#endif

#ifndef ao_mikroe_2950_dodger_blue

#define ao_mikroe_2950_dodger_blue(i)               ao_mikroe_2950_color(i, 0x1E, 0x90, 0xFF)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_fire_brick

#define ao_mikroe_2950_fire_brick(i)                ao_mikroe_2950_color(i, 0xB2, 0x22, 0x22)

#endif

#ifndef ao_mikroe_2950_floral_white

#define ao_mikroe_2950_floral_white(i)              ao_mikroe_2950_color(i, 0xFF, 0xFA, 0xF0)

#endif

#ifndef ao_mikroe_2950_forest_green

#define ao_mikroe_2950_forest_green(i)              ao_mikroe_2950_color(i, 0x22, 0x8B, 0x22)

#endif

#ifndef ao_mikroe_2950_fuchsia

#define ao_mikroe_2950_fuchsia(i)                   ao_mikroe_2950_color(i, 0xFF, 0x00, 0xFF)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_gainsboro

#define ao_mikroe_2950_gainsboro(i)                 ao_mikroe_2950_color(i, 0xDC, 0xDC, 0xDC)

#endif

#ifndef ao_mikroe_2950_ghost_white

#define ao_mikroe_2950_ghost_white(i)               ao_mikroe_2950_color(i, 0xF8, 0xF8, 0xFF)

#endif

#ifndef ao_mikroe_2950_gold

#define ao_mikroe_2950_gold(i)                      ao_mikroe_2950_color(i, 0xFF, 0xD7, 0x00)

#endif

#ifndef ao_mikroe_2950_golden_rod

#define ao_mikroe_2950_golden_rod(i)                ao_mikroe_2950_color(i, 0xDA, 0xA5, 0x20)

#endif

#ifndef ao_mikroe_2950_gray

#define ao_mikroe_2950_gray(i)                      ao_mikroe_2950_color(i, 0x80, 0x80, 0x80)

#endif

#ifndef ao_mikroe_2950_grey

#define ao_mikroe_2950_grey(i)                      ao_mikroe_2950_color(i, 0x80, 0x80, 0x80)

#endif

#ifndef ao_mikroe_2950_green

#define ao_mikroe_2950_green(i)                     ao_mikroe_2950_color(i, 0x00, 0x80, 0x00)

#endif

#ifndef ao_mikroe_2950_green_yellow

#define ao_mikroe_2950_green_yellow(i)              ao_mikroe_2950_color(i, 0xAD, 0xFF, 0x2F)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_honey_dew

#define ao_mikroe_2950_honey_dew(i)                 ao_mikroe_2950_color(i, 0xF0, 0xFF, 0xF0)

#endif

#ifndef ao_mikroe_2950_hot_pink

#define ao_mikroe_2950_hot_pink(i)                  ao_mikroe_2950_color(i, 0xFF, 0x69, 0xB4)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_indian_red

#define ao_mikroe_2950_indian_red(i)                ao_mikroe_2950_color(i, 0xCD, 0x5C, 0x5C)

#endif

#ifndef ao_mikroe_2950_indigo

#define ao_mikroe_2950_indigo(i)                    ao_mikroe_2950_color(i, 0x4B, 0x00, 0x82)

#endif

#ifndef ao_mikroe_2950_ivory

#define ao_mikroe_2950_ivory(i)                     ao_mikroe_2950_color(i, 0xFF, 0xFF, 0xF0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_khaki

#define ao_mikroe_2950_khaki(i)                     ao_mikroe_2950_color(i, 0xF0, 0xE6, 0x8C)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_lavender

#define ao_mikroe_2950_lavender(i)                  ao_mikroe_2950_color(i, 0xE6, 0xE6, 0xFA)

#endif

#ifndef ao_mikroe_2950_lavender_blush

#define ao_mikroe_2950_lavender_blush(i)            ao_mikroe_2950_color(i, 0xFF, 0xF0, 0xF5)

#endif

#ifndef ao_mikroe_2950_lawn_green

#define ao_mikroe_2950_lawn_green(i)                ao_mikroe_2950_color(i, 0x7C, 0xFC, 0x00)

#endif

#ifndef ao_mikroe_2950_lemon_chiffon

#define ao_mikroe_2950_lemon_chiffon(i)             ao_mikroe_2950_color(i, 0xFF, 0xFA, 0xCD)

#endif

#ifndef ao_mikroe_2950_light_blue

#define ao_mikroe_2950_light_blue(i)                ao_mikroe_2950_color(i, 0xAD, 0xD8, 0xE6)

#endif

#ifndef ao_mikroe_2950_light_coral

#define ao_mikroe_2950_light_coral(i)               ao_mikroe_2950_color(i, 0xF0, 0x80, 0x80)

#endif

#ifndef ao_mikroe_2950_light_cyan

#define ao_mikroe_2950_light_cyan(i)                ao_mikroe_2950_color(i, 0xE0, 0xFF, 0xFF)

#endif

#ifndef ao_mikroe_2950_light_golden_rod_yellow

#define ao_mikroe_2950_light_golden_rod_yellow(i)   ao_mikroe_2950_color(i, 0xFA, 0xFA, 0xD2)

#endif

#ifndef ao_mikroe_2950_light_gray

#define ao_mikroe_2950_light_gray(i)                ao_mikroe_2950_color(i, 0xD3, 0xD3, 0xD3)

#endif

#ifndef ao_mikroe_2950_light_grey

#define ao_mikroe_2950_light_grey(i)                ao_mikroe_2950_color(i, 0xD3, 0xD3, 0xD3)

#endif

#ifndef ao_mikroe_2950_light_green

#define ao_mikroe_2950_light_green(i)               ao_mikroe_2950_color(i, 0x90, 0xEE, 0x90)

#endif

#ifndef ao_mikroe_2950_light_pink

#define ao_mikroe_2950_light_pink(i)                ao_mikroe_2950_color(i, 0xFF, 0xB6, 0xC1)

#endif

#ifndef ao_mikroe_2950_light_salmon

#define ao_mikroe_2950_light_salmon(i)              ao_mikroe_2950_color(i, 0xFF, 0xA0, 0x7A)

#endif

#ifndef ao_mikroe_2950_light_sea_green

#define ao_mikroe_2950_light_sea_green(i)           ao_mikroe_2950_color(i, 0x20, 0xB2, 0xAA)

#endif

#ifndef ao_mikroe_2950_light_sky_blue

#define ao_mikroe_2950_light_sky_blue(i)            ao_mikroe_2950_color(i, 0x87, 0xCE, 0xFA)

#endif

#ifndef ao_mikroe_2950_light_slate_gray

#define ao_mikroe_2950_light_slate_gray(i)          ao_mikroe_2950_color(i, 0x77, 0x88, 0x99)

#endif

#ifndef ao_mikroe_2950_light_slate_grey

#define ao_mikroe_2950_light_slate_grey(i)          ao_mikroe_2950_color(i, 0x77, 0x88, 0x99)

#endif

#ifndef ao_mikroe_2950_light_steel_blue

#define ao_mikroe_2950_light_steel_blue(i)          ao_mikroe_2950_color(i, 0xB0, 0xC4, 0xDE)

#endif

#ifndef ao_mikroe_2950_light_yellow

#define ao_mikroe_2950_light_yellow(i)              ao_mikroe_2950_color(i, 0xFF, 0xFF, 0xE0)

#endif

#ifndef ao_mikroe_2950_lime

#define ao_mikroe_2950_lime(i)                      ao_mikroe_2950_color(i, 0x00, 0xFF, 0x00)

#endif

#ifndef ao_mikroe_2950_lime_green

#define ao_mikroe_2950_lime_green(i)                ao_mikroe_2950_color(i, 0x32, 0xCD, 0x32)

#endif

#ifndef ao_mikroe_2950_linen

#define ao_mikroe_2950_linen(i)                     ao_mikroe_2950_color(i, 0xFA, 0xF0, 0xE6)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_magenta

#define ao_mikroe_2950_magenta(i)                   ao_mikroe_2950_color(i, 0xFF, 0x00, 0xFF)

#endif

#ifndef ao_mikroe_2950_maroon

#define ao_mikroe_2950_maroon(i)                    ao_mikroe_2950_color(i, 0x80, 0x00, 0x00)

#endif

#ifndef ao_mikroe_2950_medium_aqua_marine

#define ao_mikroe_2950_medium_aqua_marine(i)        ao_mikroe_2950_color(i, 0x66, 0xCD, 0xAA)

#endif

#ifndef ao_mikroe_2950_medium_blue

#define ao_mikroe_2950_medium_blue(i)               ao_mikroe_2950_color(i, 0x00, 0x00, 0xCD)

#endif

#ifndef ao_mikroe_2950_medium_orchid

#define ao_mikroe_2950_medium_orchid(i)             ao_mikroe_2950_color(i, 0xBA, 0x55, 0xD3)

#endif

#ifndef ao_mikroe_2950_medium_purple

#define ao_mikroe_2950_medium_purple(i)             ao_mikroe_2950_color(i, 0x93, 0x70, 0xDB)

#endif

#ifndef ao_mikroe_2950_medium_sea_green

#define ao_mikroe_2950_medium_sea_green(i)          ao_mikroe_2950_color(i, 0x3C, 0xB3, 0x71)

#endif

#ifndef ao_mikroe_2950_medium_slate_blue

#define ao_mikroe_2950_medium_slate_blue(i)         ao_mikroe_2950_color(i, 0x7B, 0x68, 0xEE)

#endif

#ifndef ao_mikroe_2950_medium_spring_green

#define ao_mikroe_2950_medium_spring_green(i)       ao_mikroe_2950_color(i, 0x00, 0xFA, 0x9A)

#endif

#ifndef ao_mikroe_2950_medium_turquoise

#define ao_mikroe_2950_medium_turquoise(i)          ao_mikroe_2950_color(i, 0x48, 0xD1, 0xCC)

#endif

#ifndef ao_mikroe_2950_medium_violet_red

#define ao_mikroe_2950_medium_violet_red(i)         ao_mikroe_2950_color(i, 0xC7, 0x15, 0x85)

#endif

#ifndef ao_mikroe_2950_midnight_blue

#define ao_mikroe_2950_midnight_blue(i)             ao_mikroe_2950_color(i, 0x19, 0x19, 0x70)

#endif

#ifndef ao_mikroe_2950_mint_cream

#define ao_mikroe_2950_mint_cream(i)                ao_mikroe_2950_color(i, 0xF5, 0xFF, 0xFA)

#endif

#ifndef ao_mikroe_2950_misty_rose

#define ao_mikroe_2950_misty_rose(i)                ao_mikroe_2950_color(i, 0xFF, 0xE4, 0xE1)

#endif

#ifndef ao_mikroe_2950_moccasin

#define ao_mikroe_2950_moccasin(i)                  ao_mikroe_2950_color(i, 0xFF, 0xE4, 0xB5)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_navajo_white

#define ao_mikroe_2950_navajo_white(i)              ao_mikroe_2950_color(i, 0xFF, 0xDE, 0xAD)

#endif

#ifndef ao_mikroe_2950_navy

#define ao_mikroe_2950_navy(i)                      ao_mikroe_2950_color(i, 0x00, 0x00, 0x80)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_old_lace

#define ao_mikroe_2950_old_lace(i)                  ao_mikroe_2950_color(i, 0xFD, 0xF5, 0xE6)

#endif

#ifndef ao_mikroe_2950_olive

#define ao_mikroe_2950_olive(i)                     ao_mikroe_2950_color(i, 0x80, 0x80, 0x00)

#endif

#ifndef ao_mikroe_2950_olive_drab

#define ao_mikroe_2950_olive_drab(i)                ao_mikroe_2950_color(i, 0x6B, 0x8E, 0x23)

#endif

#ifndef ao_mikroe_2950_orange

#define ao_mikroe_2950_orange(i)                    ao_mikroe_2950_color(i, 0xFF, 0xA5, 0x00)

#endif

#ifndef ao_mikroe_2950_orange_red

#define ao_mikroe_2950_orange_red(i)                ao_mikroe_2950_color(i, 0xFF, 0x45, 0x00)

#endif

#ifndef ao_mikroe_2950_orchid

#define ao_mikroe_2950_orchid(i)                    ao_mikroe_2950_color(i, 0xDA, 0x70, 0xD6)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_pale_golden_rod

#define ao_mikroe_2950_pale_golden_rod(i)           ao_mikroe_2950_color(i, 0xEE, 0xE8, 0xAA)

#endif

#ifndef ao_mikroe_2950_pale_green

#define ao_mikroe_2950_pale_green(i)                ao_mikroe_2950_color(i, 0x98, 0xFB, 0x98)

#endif

#ifndef ao_mikroe_2950_pale_turquoise

#define ao_mikroe_2950_pale_turquoise(i)            ao_mikroe_2950_color(i, 0xAF, 0xEE, 0xEE)

#endif

#ifndef ao_mikroe_2950_pale_violet_red

#define ao_mikroe_2950_pale_violet_red(i)           ao_mikroe_2950_color(i, 0xDB, 0x70, 0x93)

#endif

#ifndef ao_mikroe_2950_papaya_whip

#define ao_mikroe_2950_papaya_whip(i)               ao_mikroe_2950_color(i, 0xFF, 0xEF, 0xD5)

#endif

#ifndef ao_mikroe_2950_peach_puff

#define ao_mikroe_2950_peach_puff(i)                ao_mikroe_2950_color(i, 0xFF, 0xDA, 0xB9)

#endif

#ifndef ao_mikroe_2950_peru

#define ao_mikroe_2950_peru(i)                      ao_mikroe_2950_color(i, 0xCD, 0x85, 0x3F)

#endif

#ifndef ao_mikroe_2950_pink

#define ao_mikroe_2950_pink(i)                      ao_mikroe_2950_color(i, 0xFF, 0xC0, 0xCB)

#endif

#ifndef ao_mikroe_2950_plum

#define ao_mikroe_2950_plum(i)                      ao_mikroe_2950_color(i, 0xDD, 0xA0, 0xDD)

#endif

#ifndef ao_mikroe_2950_powder_blue

#define ao_mikroe_2950_powder_blue(i)               ao_mikroe_2950_color(i, 0xB0, 0xE0, 0xE6)

#endif

#ifndef ao_mikroe_2950_purple

#define ao_mikroe_2950_purple(i)                    ao_mikroe_2950_color(i, 0x80, 0x00, 0x80)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_rebecca_purple

#define ao_mikroe_2950_rebecca_purple(i)            ao_mikroe_2950_color(i, 0x66, 0x33, 0x99)

#endif

#ifndef ao_mikroe_2950_red

#define ao_mikroe_2950_red(i)                       ao_mikroe_2950_color(i, 0xFF, 0x00, 0x00)

#endif

#ifndef ao_mikroe_2950_rosy_brown

#define ao_mikroe_2950_rosy_brown(i)                ao_mikroe_2950_color(i, 0xBC, 0x8F, 0x8F)

#endif

#ifndef ao_mikroe_2950_royal_blue

#define ao_mikroe_2950_royal_blue(i)                ao_mikroe_2950_color(i, 0x41, 0x69, 0xE1)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_saddle_brown

#define ao_mikroe_2950_saddle_brown(i)              ao_mikroe_2950_color(i, 0x8B, 0x45, 0x13)

#endif

#ifndef ao_mikroe_2950_salmon

#define ao_mikroe_2950_salmon(i)                    ao_mikroe_2950_color(i, 0xFA, 0x80, 0x72)

#endif

#ifndef ao_mikroe_2950_sandy_brown

#define ao_mikroe_2950_sandy_brown(i)               ao_mikroe_2950_color(i, 0xF4, 0xA4, 0x60)

#endif

#ifndef ao_mikroe_2950_sea_green

#define ao_mikroe_2950_sea_green(i)                 ao_mikroe_2950_color(i, 0x2E, 0x8B, 0x57)

#endif

#ifndef ao_mikroe_2950_sea_shell

#define ao_mikroe_2950_sea_shell(i)                 ao_mikroe_2950_color(i, 0xFF, 0xF5, 0xEE)

#endif

#ifndef ao_mikroe_2950_sienna

#define ao_mikroe_2950_sienna(i)                    ao_mikroe_2950_color(i, 0xA0, 0x52, 0x2D)

#endif

#ifndef ao_mikroe_2950_silver

#define ao_mikroe_2950_silver(i)                    ao_mikroe_2950_color(i, 0xC0, 0xC0, 0xC0)

#endif

#ifndef ao_mikroe_2950_sky_blue

#define ao_mikroe_2950_sky_blue(i)                  ao_mikroe_2950_color(i, 0x87, 0xCE, 0xEB)

#endif

#ifndef ao_mikroe_2950_slate_blue

#define ao_mikroe_2950_slate_blue(i)                ao_mikroe_2950_color(i, 0x6A, 0x5A, 0xCD)

#endif

#ifndef ao_mikroe_2950_slate_gray

#define ao_mikroe_2950_slate_gray(i)                ao_mikroe_2950_color(i, 0x70, 0x80, 0x90)

#endif

#ifndef ao_mikroe_2950_slate_grey

#define ao_mikroe_2950_slate_grey(i)                ao_mikroe_2950_color(i, 0x70, 0x80, 0x90)

#endif

#ifndef ao_mikroe_2950_snow

#define ao_mikroe_2950_snow(i)                      ao_mikroe_2950_color(i, 0xFF, 0xFA, 0xFA)

#endif

#ifndef ao_mikroe_2950_spring_green

#define ao_mikroe_2950_spring_green(i)              ao_mikroe_2950_color(i, 0x00, 0xFF, 0x7F)

#endif

#ifndef ao_mikroe_2950_steel_blue

#define ao_mikroe_2950_steel_blue(i)                ao_mikroe_2950_color(i, 0x46, 0x82, 0xB4)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_tan

#define ao_mikroe_2950_tan(i)                       ao_mikroe_2950_color(i, 0xD2, 0xB4, 0x8C)

#endif

#ifndef ao_mikroe_2950_teal

#define ao_mikroe_2950_teal(i)                      ao_mikroe_2950_color(i, 0x00, 0x80, 0x80)

#endif

#ifndef ao_mikroe_2950_thistle

#define ao_mikroe_2950_thistle(i)                   ao_mikroe_2950_color(i, 0xD8, 0xBF, 0xD8)

#endif

#ifndef ao_mikroe_2950_tomato

#define ao_mikroe_2950_tomato(i)                    ao_mikroe_2950_color(i, 0xFF, 0x63, 0x47)

#endif

#ifndef ao_mikroe_2950_turquoise

#define ao_mikroe_2950_turquoise(i)                 ao_mikroe_2950_color(i, 0x40, 0xE0, 0xD0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_violet

#define ao_mikroe_2950_violet(i)                    ao_mikroe_2950_color(i, 0xEE, 0x82, 0xEE)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_wheat

#define ao_mikroe_2950_wheat(i)                     ao_mikroe_2950_color(i, 0xF5, 0xDE, 0xB3)

#endif

#ifndef ao_mikroe_2950_white

#define ao_mikroe_2950_white(i)                     ao_mikroe_2950_color(i, 0xFF, 0xFF, 0xFF)

#endif

#ifndef ao_mikroe_2950_white_smoke

#define ao_mikroe_2950_white_smoke(i)               ao_mikroe_2950_color(i, 0xF5, 0xF5, 0xF5)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_mikroe_2950_yellow

#define ao_mikroe_2950_yellow(i)                    ao_mikroe_2950_color(i, 0xFF, 0xFF, 0x00)

#endif

#ifndef ao_mikroe_2950_yellow_green

#define ao_mikroe_2950_yellow_green(i)              ao_mikroe_2950_color(i, 0x9A, 0xCD, 0x32)

#endif

// ----------------------------------------------------------------------------
