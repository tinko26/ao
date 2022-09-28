---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
external:
- https://www.mikroe.com/led-driver-3-click : "LED Driver 3 Click"
- https://www.onsemi.com/products/power-management/led-drivers/dc-dc-led-drivers/ncp5623b : "NCP5623B LED Driver"
permalink: /api/demos/ao_mikroe/ao_mikroe_2950.h/
toc: true
---

# Include

| [`ao_time.h`](../../src/ao_sys/ao_time.h.md) |
| `stdbool.h` |
| `stddef.h` |
| `stdint.h` |

# Configuration

```c
#define AO_MIKROE_2950 (false)
```

Defines whether the clickboard is used.

# Functions

## `ao_mikroe_2950_color`

```c
void ao_mikroe_2950_color(size_t i, uint8_t r, uint8_t g, uint8_t b);
```

## `ao_mikroe_2950_luminance`

```c
void ao_mikroe_2950_luminance(size_t i, uint8_t l);
```

## `ao_mikroe_2950_luminance_down`

```c
void ao_mikroe_2950_luminance_down(size_t i, uint8_t l, ao_time_t t);
```

## `ao_mikroe_2950_luminance_up`

```c
void ao_mikroe_2950_luminance_up(size_t i, uint8_t l, ao_time_t t);
```

## `ao_mikroe_2950_*`

```c
#define ao_mikroe_2950_alice_blue(i)              ao_mikroe_2950_color(i, 0xF0, 0xF8, 0xFF)
#define ao_mikroe_2950_antique_white(i)           ao_mikroe_2950_color(i, 0xFA, 0xEB, 0xD7)
#define ao_mikroe_2950_aqua(i)                    ao_mikroe_2950_color(i, 0x00, 0xFF, 0xFF)
#define ao_mikroe_2950_aquamarine(i)              ao_mikroe_2950_color(i, 0x7F, 0xFF, 0xD4)
#define ao_mikroe_2950_azure(i)                   ao_mikroe_2950_color(i, 0xF0, 0xFF, 0xFF)
#define ao_mikroe_2950_beige(i)                   ao_mikroe_2950_color(i, 0xF5, 0xF5, 0xDC)
#define ao_mikroe_2950_bisque(i)                  ao_mikroe_2950_color(i, 0xFF, 0xE4, 0xC4)
#define ao_mikroe_2950_black(i)                   ao_mikroe_2950_color(i, 0x00, 0x00, 0x00)
#define ao_mikroe_2950_blanched_almond(i)         ao_mikroe_2950_color(i, 0xFF, 0xEB, 0xCD)
#define ao_mikroe_2950_blue(i)                    ao_mikroe_2950_color(i, 0x00, 0x00, 0xFF)
#define ao_mikroe_2950_blue_violet(i)             ao_mikroe_2950_color(i, 0x8A, 0x2B, 0xE2)
#define ao_mikroe_2950_brown(i)                   ao_mikroe_2950_color(i, 0xA5, 0x2A, 0x2A)
#define ao_mikroe_2950_burly_wood(i)              ao_mikroe_2950_color(i, 0xDE, 0xB8, 0x87)
#define ao_mikroe_2950_cadet_blue(i)              ao_mikroe_2950_color(i, 0x5F, 0x9E, 0xA0)
#define ao_mikroe_2950_chartreuse(i)              ao_mikroe_2950_color(i, 0x7F, 0xFF, 0x00)
#define ao_mikroe_2950_chocolate(i)               ao_mikroe_2950_color(i, 0xD2, 0x69, 0x1E)
#define ao_mikroe_2950_coral(i)                   ao_mikroe_2950_color(i, 0xFF, 0x7F, 0x50)
#define ao_mikroe_2950_cornflower_blue(i)         ao_mikroe_2950_color(i, 0x64, 0x95, 0xED)
#define ao_mikroe_2950_cornsilk(i)                ao_mikroe_2950_color(i, 0xFF, 0xF8, 0xDC)
#define ao_mikroe_2950_crimson(i)                 ao_mikroe_2950_color(i, 0xDC, 0x14, 0x3C)
#define ao_mikroe_2950_cyan(i)                    ao_mikroe_2950_color(i, 0x00, 0xFF, 0xFF)
#define ao_mikroe_2950_dark_blue(i)               ao_mikroe_2950_color(i, 0x00, 0x00, 0x8B)
#define ao_mikroe_2950_dark_cyan(i)               ao_mikroe_2950_color(i, 0x00, 0x8B, 0x8B)
#define ao_mikroe_2950_dark_golden_rod(i)         ao_mikroe_2950_color(i, 0xB8, 0x86, 0x0B)
#define ao_mikroe_2950_dark_gray(i)               ao_mikroe_2950_color(i, 0xA9, 0xA9, 0xA9)
#define ao_mikroe_2950_dark_grey(i)               ao_mikroe_2950_color(i, 0xA9, 0xA9, 0xA9)
#define ao_mikroe_2950_dark_green(i)              ao_mikroe_2950_color(i, 0x00, 0x64, 0x00)
#define ao_mikroe_2950_dark_khaki(i)              ao_mikroe_2950_color(i, 0xBD, 0xB7, 0x6B)
#define ao_mikroe_2950_dark_magenta(i)            ao_mikroe_2950_color(i, 0x8B, 0x00, 0x8B)
#define ao_mikroe_2950_dark_olive_green(i)        ao_mikroe_2950_color(i, 0x55, 0x6B, 0x2F)
#define ao_mikroe_2950_dark_orange(i)             ao_mikroe_2950_color(i, 0xFF, 0x8C, 0x00)
#define ao_mikroe_2950_dark_orchid(i)             ao_mikroe_2950_color(i, 0x99, 0x32, 0xCC)
#define ao_mikroe_2950_dark_red(i)                ao_mikroe_2950_color(i, 0x8B, 0x00, 0x00)
#define ao_mikroe_2950_dark_salmon(i)             ao_mikroe_2950_color(i, 0xE9, 0x96, 0x7A)
#define ao_mikroe_2950_dark_sea_green(i)          ao_mikroe_2950_color(i, 0x8F, 0xBC, 0x8F)
#define ao_mikroe_2950_dark_slate_blue(i)         ao_mikroe_2950_color(i, 0x48, 0x3D, 0x8B)
#define ao_mikroe_2950_dark_slate_gray(i)         ao_mikroe_2950_color(i, 0x2F, 0x4F, 0x4F)
#define ao_mikroe_2950_dark_slate_grey(i)         ao_mikroe_2950_color(i, 0x2F, 0x4F, 0x4F)
#define ao_mikroe_2950_dark_turquoise(i)          ao_mikroe_2950_color(i, 0x00, 0xCE, 0xD1)
#define ao_mikroe_2950_dark_violet(i)             ao_mikroe_2950_color(i, 0x94, 0x00, 0xD3)
#define ao_mikroe_2950_deep_pink(i)               ao_mikroe_2950_color(i, 0xFF, 0x14, 0x93)
#define ao_mikroe_2950_deep_sky_blue(i)           ao_mikroe_2950_color(i, 0x00, 0xBF, 0xFF)
#define ao_mikroe_2950_dim_gray(i)                ao_mikroe_2950_color(i, 0x69, 0x69, 0x69)
#define ao_mikroe_2950_dim_grey(i)                ao_mikroe_2950_color(i, 0x69, 0x69, 0x69)
#define ao_mikroe_2950_dodger_blue(i)             ao_mikroe_2950_color(i, 0x1E, 0x90, 0xFF)
#define ao_mikroe_2950_fire_brick(i)              ao_mikroe_2950_color(i, 0xB2, 0x22, 0x22)
#define ao_mikroe_2950_floral_white(i)            ao_mikroe_2950_color(i, 0xFF, 0xFA, 0xF0)
#define ao_mikroe_2950_forest_green(i)            ao_mikroe_2950_color(i, 0x22, 0x8B, 0x22)
#define ao_mikroe_2950_fuchsia(i)                 ao_mikroe_2950_color(i, 0xFF, 0x00, 0xFF)
#define ao_mikroe_2950_gainsboro(i)               ao_mikroe_2950_color(i, 0xDC, 0xDC, 0xDC)
#define ao_mikroe_2950_ghost_white(i)             ao_mikroe_2950_color(i, 0xF8, 0xF8, 0xFF)
#define ao_mikroe_2950_gold(i)                    ao_mikroe_2950_color(i, 0xFF, 0xD7, 0x00)
#define ao_mikroe_2950_golden_rod(i)              ao_mikroe_2950_color(i, 0xDA, 0xA5, 0x20)
#define ao_mikroe_2950_gray(i)                    ao_mikroe_2950_color(i, 0x80, 0x80, 0x80)
#define ao_mikroe_2950_grey(i)                    ao_mikroe_2950_color(i, 0x80, 0x80, 0x80)
#define ao_mikroe_2950_green(i)                   ao_mikroe_2950_color(i, 0x00, 0x80, 0x00)
#define ao_mikroe_2950_green_yellow(i)            ao_mikroe_2950_color(i, 0xAD, 0xFF, 0x2F)
#define ao_mikroe_2950_honey_dew(i)               ao_mikroe_2950_color(i, 0xF0, 0xFF, 0xF0)
#define ao_mikroe_2950_hot_pink(i)                ao_mikroe_2950_color(i, 0xFF, 0x69, 0xB4)
#define ao_mikroe_2950_indian_red(i)              ao_mikroe_2950_color(i, 0xCD, 0x5C, 0x5C)
#define ao_mikroe_2950_indigo(i)                  ao_mikroe_2950_color(i, 0x4B, 0x00, 0x82)
#define ao_mikroe_2950_ivory(i)                   ao_mikroe_2950_color(i, 0xFF, 0xFF, 0xF0)
#define ao_mikroe_2950_khaki(i)                   ao_mikroe_2950_color(i, 0xF0, 0xE6, 0x8C)
#define ao_mikroe_2950_lavender(i)                ao_mikroe_2950_color(i, 0xE6, 0xE6, 0xFA)
#define ao_mikroe_2950_lavender_blush(i)          ao_mikroe_2950_color(i, 0xFF, 0xF0, 0xF5)
#define ao_mikroe_2950_lawn_green(i)              ao_mikroe_2950_color(i, 0x7C, 0xFC, 0x00)
#define ao_mikroe_2950_lemon_chiffon(i)           ao_mikroe_2950_color(i, 0xFF, 0xFA, 0xCD)
#define ao_mikroe_2950_light_blue(i)              ao_mikroe_2950_color(i, 0xAD, 0xD8, 0xE6)
#define ao_mikroe_2950_light_coral(i)             ao_mikroe_2950_color(i, 0xF0, 0x80, 0x80)
#define ao_mikroe_2950_light_cyan(i)              ao_mikroe_2950_color(i, 0xE0, 0xFF, 0xFF)
#define ao_mikroe_2950_light_golden_rod_yellow(i) ao_mikroe_2950_color(i, 0xFA, 0xFA, 0xD2)
#define ao_mikroe_2950_light_gray(i)              ao_mikroe_2950_color(i, 0xD3, 0xD3, 0xD3)
#define ao_mikroe_2950_light_grey(i)              ao_mikroe_2950_color(i, 0xD3, 0xD3, 0xD3)
#define ao_mikroe_2950_light_green(i)             ao_mikroe_2950_color(i, 0x90, 0xEE, 0x90)
#define ao_mikroe_2950_light_pink(i)              ao_mikroe_2950_color(i, 0xFF, 0xB6, 0xC1)
#define ao_mikroe_2950_light_salmon(i)            ao_mikroe_2950_color(i, 0xFF, 0xA0, 0x7A)
#define ao_mikroe_2950_light_sea_green(i)         ao_mikroe_2950_color(i, 0x20, 0xB2, 0xAA)
#define ao_mikroe_2950_light_sky_blue(i)          ao_mikroe_2950_color(i, 0x87, 0xCE, 0xFA)
#define ao_mikroe_2950_light_slate_gray(i)        ao_mikroe_2950_color(i, 0x77, 0x88, 0x99)
#define ao_mikroe_2950_light_slate_grey(i)        ao_mikroe_2950_color(i, 0x77, 0x88, 0x99)
#define ao_mikroe_2950_light_steel_blue(i)        ao_mikroe_2950_color(i, 0xB0, 0xC4, 0xDE)
#define ao_mikroe_2950_light_yellow(i)            ao_mikroe_2950_color(i, 0xFF, 0xFF, 0xE0)
#define ao_mikroe_2950_lime(i)                    ao_mikroe_2950_color(i, 0x00, 0xFF, 0x00)
#define ao_mikroe_2950_lime_green(i)              ao_mikroe_2950_color(i, 0x32, 0xCD, 0x32)
#define ao_mikroe_2950_linen(i)                   ao_mikroe_2950_color(i, 0xFA, 0xF0, 0xE6)
#define ao_mikroe_2950_magenta(i)                 ao_mikroe_2950_color(i, 0xFF, 0x00, 0xFF)
#define ao_mikroe_2950_maroon(i)                  ao_mikroe_2950_color(i, 0x80, 0x00, 0x00)
#define ao_mikroe_2950_medium_aqua_marine(i)      ao_mikroe_2950_color(i, 0x66, 0xCD, 0xAA)
#define ao_mikroe_2950_medium_blue(i)             ao_mikroe_2950_color(i, 0x00, 0x00, 0xCD)
#define ao_mikroe_2950_medium_orchid(i)           ao_mikroe_2950_color(i, 0xBA, 0x55, 0xD3)
#define ao_mikroe_2950_medium_purple(i)           ao_mikroe_2950_color(i, 0x93, 0x70, 0xDB)
#define ao_mikroe_2950_medium_sea_green(i)        ao_mikroe_2950_color(i, 0x3C, 0xB3, 0x71)
#define ao_mikroe_2950_medium_slate_blue(i)       ao_mikroe_2950_color(i, 0x7B, 0x68, 0xEE)
#define ao_mikroe_2950_medium_spring_green(i)     ao_mikroe_2950_color(i, 0x00, 0xFA, 0x9A)
#define ao_mikroe_2950_medium_turquoise(i)        ao_mikroe_2950_color(i, 0x48, 0xD1, 0xCC)
#define ao_mikroe_2950_medium_violet_red(i)       ao_mikroe_2950_color(i, 0xC7, 0x15, 0x85)
#define ao_mikroe_2950_midnight_blue(i)           ao_mikroe_2950_color(i, 0x19, 0x19, 0x70)
#define ao_mikroe_2950_mint_cream(i)              ao_mikroe_2950_color(i, 0xF5, 0xFF, 0xFA)
#define ao_mikroe_2950_misty_rose(i)              ao_mikroe_2950_color(i, 0xFF, 0xE4, 0xE1)
#define ao_mikroe_2950_moccasin(i)                ao_mikroe_2950_color(i, 0xFF, 0xE4, 0xB5)
#define ao_mikroe_2950_navajo_white(i)            ao_mikroe_2950_color(i, 0xFF, 0xDE, 0xAD)
#define ao_mikroe_2950_navy(i)                    ao_mikroe_2950_color(i, 0x00, 0x00, 0x80)
#define ao_mikroe_2950_old_lace(i)                ao_mikroe_2950_color(i, 0xFD, 0xF5, 0xE6)
#define ao_mikroe_2950_olive(i)                   ao_mikroe_2950_color(i, 0x80, 0x80, 0x00)
#define ao_mikroe_2950_olive_drab(i)              ao_mikroe_2950_color(i, 0x6B, 0x8E, 0x23)
#define ao_mikroe_2950_orange(i)                  ao_mikroe_2950_color(i, 0xFF, 0xA5, 0x00)
#define ao_mikroe_2950_orange_red(i)              ao_mikroe_2950_color(i, 0xFF, 0x45, 0x00)
#define ao_mikroe_2950_orchid(i)                  ao_mikroe_2950_color(i, 0xDA, 0x70, 0xD6)
#define ao_mikroe_2950_pale_golden_rod(i)         ao_mikroe_2950_color(i, 0xEE, 0xE8, 0xAA)
#define ao_mikroe_2950_pale_green(i)              ao_mikroe_2950_color(i, 0x98, 0xFB, 0x98)
#define ao_mikroe_2950_pale_turquoise(i)          ao_mikroe_2950_color(i, 0xAF, 0xEE, 0xEE)
#define ao_mikroe_2950_pale_violet_red(i)         ao_mikroe_2950_color(i, 0xDB, 0x70, 0x93)
#define ao_mikroe_2950_papaya_whip(i)             ao_mikroe_2950_color(i, 0xFF, 0xEF, 0xD5)
#define ao_mikroe_2950_peach_puff(i)              ao_mikroe_2950_color(i, 0xFF, 0xDA, 0xB9)
#define ao_mikroe_2950_peru(i)                    ao_mikroe_2950_color(i, 0xCD, 0x85, 0x3F)
#define ao_mikroe_2950_pink(i)                    ao_mikroe_2950_color(i, 0xFF, 0xC0, 0xCB)
#define ao_mikroe_2950_plum(i)                    ao_mikroe_2950_color(i, 0xDD, 0xA0, 0xDD)
#define ao_mikroe_2950_powder_blue(i)             ao_mikroe_2950_color(i, 0xB0, 0xE0, 0xE6)
#define ao_mikroe_2950_purple(i)                  ao_mikroe_2950_color(i, 0x80, 0x00, 0x80)
#define ao_mikroe_2950_rebecca_purple(i)          ao_mikroe_2950_color(i, 0x66, 0x33, 0x99)
#define ao_mikroe_2950_red(i)                     ao_mikroe_2950_color(i, 0xFF, 0x00, 0x00)
#define ao_mikroe_2950_rosy_brown(i)              ao_mikroe_2950_color(i, 0xBC, 0x8F, 0x8F)
#define ao_mikroe_2950_royal_blue(i)              ao_mikroe_2950_color(i, 0x41, 0x69, 0xE1)
#define ao_mikroe_2950_saddle_brown(i)            ao_mikroe_2950_color(i, 0x8B, 0x45, 0x13)
#define ao_mikroe_2950_salmon(i)                  ao_mikroe_2950_color(i, 0xFA, 0x80, 0x72)
#define ao_mikroe_2950_sandy_brown(i)             ao_mikroe_2950_color(i, 0xF4, 0xA4, 0x60)
#define ao_mikroe_2950_sea_green(i)               ao_mikroe_2950_color(i, 0x2E, 0x8B, 0x57)
#define ao_mikroe_2950_sea_shell(i)               ao_mikroe_2950_color(i, 0xFF, 0xF5, 0xEE)
#define ao_mikroe_2950_sienna(i)                  ao_mikroe_2950_color(i, 0xA0, 0x52, 0x2D)
#define ao_mikroe_2950_silver(i)                  ao_mikroe_2950_color(i, 0xC0, 0xC0, 0xC0)
#define ao_mikroe_2950_sky_blue(i)                ao_mikroe_2950_color(i, 0x87, 0xCE, 0xEB)
#define ao_mikroe_2950_slate_blue(i)              ao_mikroe_2950_color(i, 0x6A, 0x5A, 0xCD)
#define ao_mikroe_2950_slate_gray(i)              ao_mikroe_2950_color(i, 0x70, 0x80, 0x90)
#define ao_mikroe_2950_slate_grey(i)              ao_mikroe_2950_color(i, 0x70, 0x80, 0x90)
#define ao_mikroe_2950_snow(i)                    ao_mikroe_2950_color(i, 0xFF, 0xFA, 0xFA)
#define ao_mikroe_2950_spring_green(i)            ao_mikroe_2950_color(i, 0x00, 0xFF, 0x7F)
#define ao_mikroe_2950_steel_blue(i)              ao_mikroe_2950_color(i, 0x46, 0x82, 0xB4)
#define ao_mikroe_2950_tan(i)                     ao_mikroe_2950_color(i, 0xD2, 0xB4, 0x8C)
#define ao_mikroe_2950_teal(i)                    ao_mikroe_2950_color(i, 0x00, 0x80, 0x80)
#define ao_mikroe_2950_thistle(i)                 ao_mikroe_2950_color(i, 0xD8, 0xBF, 0xD8)
#define ao_mikroe_2950_tomato(i)                  ao_mikroe_2950_color(i, 0xFF, 0x63, 0x47)
#define ao_mikroe_2950_turquoise(i)               ao_mikroe_2950_color(i, 0x40, 0xE0, 0xD0)
#define ao_mikroe_2950_violet(i)                  ao_mikroe_2950_color(i, 0xEE, 0x82, 0xEE)
#define ao_mikroe_2950_wheat(i)                   ao_mikroe_2950_color(i, 0xF5, 0xDE, 0xB3)
#define ao_mikroe_2950_white(i)                   ao_mikroe_2950_color(i, 0xFF, 0xFF, 0xFF)
#define ao_mikroe_2950_white_smoke(i)             ao_mikroe_2950_color(i, 0xF5, 0xF5, 0xF5)
#define ao_mikroe_2950_yellow(i)                  ao_mikroe_2950_color(i, 0xFF, 0xFF, 0x00)
#define ao_mikroe_2950_yellow_green(i)            ao_mikroe_2950_color(i, 0x9A, 0xCD, 0x32)
```
