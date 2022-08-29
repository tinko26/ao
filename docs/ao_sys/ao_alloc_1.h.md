---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_alloc_1.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alloc_1.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_alloc_1.h</code>"
toc: true
---

typedef struct  ao_alloc_pool_t         ao_alloc_pool_t;

typedef struct  ao_alloc_pool_node_t    ao_alloc_pool_node_t;

typedef struct  ao_acquired_t           ao_acquired_t;

typedef struct  ao_released_t           ao_released_t;

typedef struct  ao_retained_t           ao_retained_t;

#ifndef AO_ALLOC_1

#define AO_ALLOC_1

#endif

#ifndef AO_ALLOC_ALLOCATED

#define AO_ALLOC_ALLOCATED              (false)

#endif

#ifndef AO_ALLOC_ALLOCATED_MAX

#define AO_ALLOC_ALLOCATED_MAX          (false)

#endif

#ifndef AO_ALLOC_FREE

#define AO_ALLOC_FREE                   (false)

#endif

#ifndef AO_ALLOC_FREE_MIN

#define AO_ALLOC_FREE_MIN               (false)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_0

#define AO_ALLOC_POOL_BLOCK_COUNT_0     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_0

#define AO_ALLOC_POOL_BLOCK_SIZE_0      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_1

#define AO_ALLOC_POOL_BLOCK_COUNT_1     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_1

#define AO_ALLOC_POOL_BLOCK_SIZE_1      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_2

#define AO_ALLOC_POOL_BLOCK_COUNT_2     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_2

#define AO_ALLOC_POOL_BLOCK_SIZE_2      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_3

#define AO_ALLOC_POOL_BLOCK_COUNT_3     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_3

#define AO_ALLOC_POOL_BLOCK_SIZE_3      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_4

#define AO_ALLOC_POOL_BLOCK_COUNT_4     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_4

#define AO_ALLOC_POOL_BLOCK_SIZE_4      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_5

#define AO_ALLOC_POOL_BLOCK_COUNT_5     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_5

#define AO_ALLOC_POOL_BLOCK_SIZE_5      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_6

#define AO_ALLOC_POOL_BLOCK_COUNT_6     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_6

#define AO_ALLOC_POOL_BLOCK_SIZE_6      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_7

#define AO_ALLOC_POOL_BLOCK_COUNT_7     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_7

#define AO_ALLOC_POOL_BLOCK_SIZE_7      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_8

#define AO_ALLOC_POOL_BLOCK_COUNT_8     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_8

#define AO_ALLOC_POOL_BLOCK_SIZE_8      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_9

#define AO_ALLOC_POOL_BLOCK_COUNT_9     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_9

#define AO_ALLOC_POOL_BLOCK_SIZE_9      (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_10

#define AO_ALLOC_POOL_BLOCK_COUNT_10    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_10

#define AO_ALLOC_POOL_BLOCK_SIZE_10     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_11

#define AO_ALLOC_POOL_BLOCK_COUNT_11    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_11

#define AO_ALLOC_POOL_BLOCK_SIZE_11     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_12

#define AO_ALLOC_POOL_BLOCK_COUNT_12    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_12

#define AO_ALLOC_POOL_BLOCK_SIZE_12     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_13

#define AO_ALLOC_POOL_BLOCK_COUNT_13    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_13

#define AO_ALLOC_POOL_BLOCK_SIZE_13     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_14

#define AO_ALLOC_POOL_BLOCK_COUNT_14    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_14

#define AO_ALLOC_POOL_BLOCK_SIZE_14     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_15

#define AO_ALLOC_POOL_BLOCK_COUNT_15    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_15

#define AO_ALLOC_POOL_BLOCK_SIZE_15     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_16

#define AO_ALLOC_POOL_BLOCK_COUNT_16    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_16

#define AO_ALLOC_POOL_BLOCK_SIZE_16     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_17

#define AO_ALLOC_POOL_BLOCK_COUNT_17    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_17

#define AO_ALLOC_POOL_BLOCK_SIZE_17     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_18

#define AO_ALLOC_POOL_BLOCK_COUNT_18    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_18

#define AO_ALLOC_POOL_BLOCK_SIZE_18     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_19

#define AO_ALLOC_POOL_BLOCK_COUNT_19    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_19

#define AO_ALLOC_POOL_BLOCK_SIZE_19     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_20

#define AO_ALLOC_POOL_BLOCK_COUNT_20    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_20

#define AO_ALLOC_POOL_BLOCK_SIZE_20     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_21

#define AO_ALLOC_POOL_BLOCK_COUNT_21    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_21

#define AO_ALLOC_POOL_BLOCK_SIZE_21     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_22

#define AO_ALLOC_POOL_BLOCK_COUNT_22    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_22

#define AO_ALLOC_POOL_BLOCK_SIZE_22     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_23

#define AO_ALLOC_POOL_BLOCK_COUNT_23    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_23

#define AO_ALLOC_POOL_BLOCK_SIZE_23     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_24

#define AO_ALLOC_POOL_BLOCK_COUNT_24    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_24

#define AO_ALLOC_POOL_BLOCK_SIZE_24     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_25

#define AO_ALLOC_POOL_BLOCK_COUNT_25    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_25

#define AO_ALLOC_POOL_BLOCK_SIZE_25     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_26

#define AO_ALLOC_POOL_BLOCK_COUNT_26    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_26

#define AO_ALLOC_POOL_BLOCK_SIZE_26     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_27

#define AO_ALLOC_POOL_BLOCK_COUNT_27    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_27

#define AO_ALLOC_POOL_BLOCK_SIZE_27     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_28

#define AO_ALLOC_POOL_BLOCK_COUNT_28    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_28

#define AO_ALLOC_POOL_BLOCK_SIZE_28     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_29

#define AO_ALLOC_POOL_BLOCK_COUNT_29    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_29

#define AO_ALLOC_POOL_BLOCK_SIZE_29     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_30

#define AO_ALLOC_POOL_BLOCK_COUNT_30    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_30

#define AO_ALLOC_POOL_BLOCK_SIZE_30     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_31

#define AO_ALLOC_POOL_BLOCK_COUNT_31    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_31

#define AO_ALLOC_POOL_BLOCK_SIZE_31     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_32

#define AO_ALLOC_POOL_BLOCK_COUNT_32    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_32

#define AO_ALLOC_POOL_BLOCK_SIZE_32     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_33

#define AO_ALLOC_POOL_BLOCK_COUNT_33    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_33

#define AO_ALLOC_POOL_BLOCK_SIZE_33     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_34

#define AO_ALLOC_POOL_BLOCK_COUNT_34    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_34

#define AO_ALLOC_POOL_BLOCK_SIZE_34     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_35

#define AO_ALLOC_POOL_BLOCK_COUNT_35    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_35

#define AO_ALLOC_POOL_BLOCK_SIZE_35     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_36

#define AO_ALLOC_POOL_BLOCK_COUNT_36    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_36

#define AO_ALLOC_POOL_BLOCK_SIZE_36     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_37

#define AO_ALLOC_POOL_BLOCK_COUNT_37    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_37

#define AO_ALLOC_POOL_BLOCK_SIZE_37     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_38

#define AO_ALLOC_POOL_BLOCK_COUNT_38    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_38

#define AO_ALLOC_POOL_BLOCK_SIZE_38     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_39

#define AO_ALLOC_POOL_BLOCK_COUNT_39    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_39

#define AO_ALLOC_POOL_BLOCK_SIZE_39     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_40

#define AO_ALLOC_POOL_BLOCK_COUNT_40    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_40

#define AO_ALLOC_POOL_BLOCK_SIZE_40     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_41

#define AO_ALLOC_POOL_BLOCK_COUNT_41    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_41

#define AO_ALLOC_POOL_BLOCK_SIZE_41     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_42

#define AO_ALLOC_POOL_BLOCK_COUNT_42    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_42

#define AO_ALLOC_POOL_BLOCK_SIZE_42     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_43

#define AO_ALLOC_POOL_BLOCK_COUNT_43    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_43

#define AO_ALLOC_POOL_BLOCK_SIZE_43     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_44

#define AO_ALLOC_POOL_BLOCK_COUNT_44    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_44

#define AO_ALLOC_POOL_BLOCK_SIZE_44     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_45

#define AO_ALLOC_POOL_BLOCK_COUNT_45    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_45

#define AO_ALLOC_POOL_BLOCK_SIZE_45     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_46

#define AO_ALLOC_POOL_BLOCK_COUNT_46    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_46

#define AO_ALLOC_POOL_BLOCK_SIZE_46     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_47

#define AO_ALLOC_POOL_BLOCK_COUNT_47    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_47

#define AO_ALLOC_POOL_BLOCK_SIZE_47     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_48

#define AO_ALLOC_POOL_BLOCK_COUNT_48    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_48

#define AO_ALLOC_POOL_BLOCK_SIZE_48     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_49

#define AO_ALLOC_POOL_BLOCK_COUNT_49    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_49

#define AO_ALLOC_POOL_BLOCK_SIZE_49     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_50

#define AO_ALLOC_POOL_BLOCK_COUNT_50    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_50

#define AO_ALLOC_POOL_BLOCK_SIZE_50     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_51

#define AO_ALLOC_POOL_BLOCK_COUNT_51    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_51

#define AO_ALLOC_POOL_BLOCK_SIZE_51     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_52

#define AO_ALLOC_POOL_BLOCK_COUNT_52    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_52

#define AO_ALLOC_POOL_BLOCK_SIZE_52     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_53

#define AO_ALLOC_POOL_BLOCK_COUNT_53    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_53

#define AO_ALLOC_POOL_BLOCK_SIZE_53     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_54

#define AO_ALLOC_POOL_BLOCK_COUNT_54    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_54

#define AO_ALLOC_POOL_BLOCK_SIZE_54     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_55

#define AO_ALLOC_POOL_BLOCK_COUNT_55    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_55

#define AO_ALLOC_POOL_BLOCK_SIZE_55     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_56

#define AO_ALLOC_POOL_BLOCK_COUNT_56    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_56

#define AO_ALLOC_POOL_BLOCK_SIZE_56     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_57

#define AO_ALLOC_POOL_BLOCK_COUNT_57    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_57

#define AO_ALLOC_POOL_BLOCK_SIZE_57     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_58

#define AO_ALLOC_POOL_BLOCK_COUNT_58    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_58

#define AO_ALLOC_POOL_BLOCK_SIZE_58     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_59

#define AO_ALLOC_POOL_BLOCK_COUNT_59    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_59

#define AO_ALLOC_POOL_BLOCK_SIZE_59     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_60

#define AO_ALLOC_POOL_BLOCK_COUNT_60    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_60

#define AO_ALLOC_POOL_BLOCK_SIZE_60     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_61

#define AO_ALLOC_POOL_BLOCK_COUNT_61    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_61

#define AO_ALLOC_POOL_BLOCK_SIZE_61     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_62

#define AO_ALLOC_POOL_BLOCK_COUNT_62    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_62

#define AO_ALLOC_POOL_BLOCK_SIZE_62     (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_COUNT_63

#define AO_ALLOC_POOL_BLOCK_COUNT_63    (0)

#endif

#ifndef AO_ALLOC_POOL_BLOCK_SIZE_63

#define AO_ALLOC_POOL_BLOCK_SIZE_63     (0)

#endif

#ifndef AO_ALLOC_POOL

#define AO_ALLOC_POOL

struct  ao_alloc_pool_t
{

#if     AO_ALLOC_ALLOCATED_MAX || AO_ALLOC_ALLOCATED

        size_t              volatile    allocated;

#endif

#if     AO_ALLOC_ALLOCATED_MAX

        size_t              volatile    allocated_max;

#endif

        size_t                          block_size;

#if     AO_ALLOC_FREE_MIN || AO_ALLOC_FREE

        size_t              volatile    free;

#endif

#if     AO_ALLOC_FREE_MIN

        size_t              volatile    free_min;

#endif

        ao_alloc_pool_node_t *          front;
};

#endif

#ifndef AO_ACQUIRED_T

#define AO_ACQUIRED_T

struct  ao_acquired_t
{
        size_t                          pool;

        void *                          ptr;

        bool                            result;

        size_t                          size_body;

        size_t                          size_body_requested;

        size_t                          size_head;
};

#endif

#ifndef AO_RELEASED_T

#define AO_RELEASED_T

struct  ao_released_t
{
        size_t                          pool;

        void *                          ptr;

        size_t                          ref;

        bool                            result;

        size_t                          size_body;

        size_t                          size_head;
};

#endif

#ifndef AO_RETAINED_T

#define AO_RETAINED_T

struct  ao_retained_t
{
        size_t                          pool;

        void *                          ptr;

        size_t                          ref;

        bool                            result;

        size_t                          size_body;

        size_t                          size_head;
};

#endif

extern  ao_alloc_pool_t                 ao_alloc_pool_0;

extern  ao_alloc_pool_t                 ao_alloc_pool_1;

extern  ao_alloc_pool_t                 ao_alloc_pool_2;

extern  ao_alloc_pool_t                 ao_alloc_pool_3;

extern  ao_alloc_pool_t                 ao_alloc_pool_4;

extern  ao_alloc_pool_t                 ao_alloc_pool_5;

extern  ao_alloc_pool_t                 ao_alloc_pool_6;

extern  ao_alloc_pool_t                 ao_alloc_pool_7;

extern  ao_alloc_pool_t                 ao_alloc_pool_8;

extern  ao_alloc_pool_t                 ao_alloc_pool_9;

extern  ao_alloc_pool_t                 ao_alloc_pool_10;

extern  ao_alloc_pool_t                 ao_alloc_pool_11;

extern  ao_alloc_pool_t                 ao_alloc_pool_12;

extern  ao_alloc_pool_t                 ao_alloc_pool_13;

extern  ao_alloc_pool_t                 ao_alloc_pool_14;

extern  ao_alloc_pool_t                 ao_alloc_pool_15;

extern  ao_alloc_pool_t                 ao_alloc_pool_16;

extern  ao_alloc_pool_t                 ao_alloc_pool_17;

extern  ao_alloc_pool_t                 ao_alloc_pool_18;

extern  ao_alloc_pool_t                 ao_alloc_pool_19;

extern  ao_alloc_pool_t                 ao_alloc_pool_20;

extern  ao_alloc_pool_t                 ao_alloc_pool_21;

extern  ao_alloc_pool_t                 ao_alloc_pool_22;

extern  ao_alloc_pool_t                 ao_alloc_pool_23;

extern  ao_alloc_pool_t                 ao_alloc_pool_24;

extern  ao_alloc_pool_t                 ao_alloc_pool_25;

extern  ao_alloc_pool_t                 ao_alloc_pool_26;

extern  ao_alloc_pool_t                 ao_alloc_pool_27;

extern  ao_alloc_pool_t                 ao_alloc_pool_28;

extern  ao_alloc_pool_t                 ao_alloc_pool_29;

extern  ao_alloc_pool_t                 ao_alloc_pool_30;

extern  ao_alloc_pool_t                 ao_alloc_pool_31;

extern  ao_alloc_pool_t                 ao_alloc_pool_32;

extern  ao_alloc_pool_t                 ao_alloc_pool_33;

extern  ao_alloc_pool_t                 ao_alloc_pool_34;

extern  ao_alloc_pool_t                 ao_alloc_pool_35;

extern  ao_alloc_pool_t                 ao_alloc_pool_36;

extern  ao_alloc_pool_t                 ao_alloc_pool_37;

extern  ao_alloc_pool_t                 ao_alloc_pool_38;

extern  ao_alloc_pool_t                 ao_alloc_pool_39;

extern  ao_alloc_pool_t                 ao_alloc_pool_40;

extern  ao_alloc_pool_t                 ao_alloc_pool_41;

extern  ao_alloc_pool_t                 ao_alloc_pool_42;

extern  ao_alloc_pool_t                 ao_alloc_pool_43;

extern  ao_alloc_pool_t                 ao_alloc_pool_44;

extern  ao_alloc_pool_t                 ao_alloc_pool_45;

extern  ao_alloc_pool_t                 ao_alloc_pool_46;

extern  ao_alloc_pool_t                 ao_alloc_pool_47;

extern  ao_alloc_pool_t                 ao_alloc_pool_48;

extern  ao_alloc_pool_t                 ao_alloc_pool_49;

extern  ao_alloc_pool_t                 ao_alloc_pool_50;

extern  ao_alloc_pool_t                 ao_alloc_pool_51;

extern  ao_alloc_pool_t                 ao_alloc_pool_52;

extern  ao_alloc_pool_t                 ao_alloc_pool_53;

extern  ao_alloc_pool_t                 ao_alloc_pool_54;

extern  ao_alloc_pool_t                 ao_alloc_pool_55;

extern  ao_alloc_pool_t                 ao_alloc_pool_56;

extern  ao_alloc_pool_t                 ao_alloc_pool_57;

extern  ao_alloc_pool_t                 ao_alloc_pool_58;

extern  ao_alloc_pool_t                 ao_alloc_pool_59;

extern  ao_alloc_pool_t                 ao_alloc_pool_60;

extern  ao_alloc_pool_t                 ao_alloc_pool_61;

extern  ao_alloc_pool_t                 ao_alloc_pool_62;

extern  ao_alloc_pool_t                 ao_alloc_pool_63;

extern  size_t              volatile    ao_alloc_allocated;

extern  size_t              volatile    ao_alloc_allocated_max;

extern  size_t              volatile    ao_alloc_free;

extern  size_t              volatile    ao_alloc_free_min;

