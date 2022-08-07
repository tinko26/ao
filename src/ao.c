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

#include <ao.h>
#include <float.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

#if defined AO_AVL

// ----------------------------------------------------------------------------

static  ao_int_t        ao_avl_assert_node( ao_avl_t * X, ao_avl_node_t * N);

// ----------------------------------------------------------------------------

static  ao_int_t        ao_avl_balance(     ao_avl_node_t * N);

// ----------------------------------------------------------------------------

static  ao_int_t        ao_avl_height(      ao_avl_node_t * N);

// ----------------------------------------------------------------------------

static  ao_int_t        ao_avl_rotate_left( ao_avl_t * X, ao_avl_node_t * N);

static  ao_int_t        ao_avl_rotate_right(ao_avl_t * X, ao_avl_node_t * N);

// ----------------------------------------------------------------------------

static  ao_avl_node_t * ao_avl_successor(   ao_avl_node_t * N);

// ----------------------------------------------------------------------------

static  void            ao_avl_swap(        ao_avl_t * X, ao_avl_node_t * N1, ao_avl_node_t * N2);

// ----------------------------------------------------------------------------

static  ao_int_t        ao_avl_update(      ao_avl_node_t * N);

// ----------------------------------------------------------------------------

void ao_avl_assert(ao_avl_t * X)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->less);


    // Variables.

    ao_avl_node_t * N;


    // Ready.

    N = X->root;

    if (N)
    {
        ao_assert(!N->parent);

        ao_avl_assert_node(X, N);
    }
}

ao_int_t ao_avl_assert_node(ao_avl_t * X, ao_avl_node_t * N)
{
    // Variables.

    ao_int_t HL;

    ao_int_t HN;

    ao_int_t HR;

    ao_avl_node_t * L;

    ao_avl_less_t Less;

    void * LessParameter;

    ao_avl_node_t * R;


    // Ready.

    L = N->left;

    R = N->right;

    if (L)
    {
        Less = X->less;

        LessParameter = X->less_parameter;

        ao_assert(Less(L, N, LessParameter));

        ao_assert(L->parent == N);

        if (R)
        {
            ao_assert(Less(N, R, LessParameter));

            ao_assert(R->parent == N);

            HL = ao_avl_assert_node(X, L);

            HR = ao_avl_assert_node(X, R);

            if (HL > HR)
            {
                ao_assert(HL == HR + 1);

                HN = HL + 1;
            }

            else if (HL == HR)
            {
                HN = HL + 1;
            }

            else
            {
                ao_assert(HL == HR - 1);

                HN = HR + 1;
            }

            ao_assert(N->height == HN);

            return HN;
        }

        else
        {
            ao_assert(L->left == NULL);

            ao_assert(L->right == NULL);

            ao_assert(L->height == 1);

            ao_assert(N->height == 2);

            return 2;
        }
    }

    else if (R)
    {
        Less = X->less;

        LessParameter = X->less_parameter;

        ao_assert(Less(N, R, LessParameter));

        ao_assert(R->parent == N);

        ao_assert(R->left == NULL);

        ao_assert(R->right == NULL);

        ao_assert(R->height == 1);

        ao_assert(N->height == 2);

        return 2;
    }

    else
    {
        ao_assert(N->height == 1);

        return 1;
    }
}

ao_int_t ao_avl_balance(ao_avl_node_t * N)
{
    // Assert.

    ao_assert(N);


    // Variables.

    ao_int_t HL;

    ao_int_t HR;


    // Ready.

    HL = ao_avl_height(N->left);

    HR = ao_avl_height(N->right);

    return HR - HL;
}

ao_int_t ao_avl_height(ao_avl_node_t * N)
{
    return N ? N->height : 0;
}

void ao_avl_insert(ao_avl_t * X, ao_avl_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->less);

    ao_assert(N);

    ao_assert(!N->parent);

    ao_assert(!N->left);

    ao_assert(!N->right);


    // Variables.

    ao_int_t BN;

    ao_int_t BP;

    ao_avl_node_t * C;

    bool IsLeft;

    ao_avl_less_t Less = X->less;

    void * LessParameter = X->less_parameter;

    ao_avl_node_t * P;


    // Ready.

    // Traverse.

    P = NULL;

    C = X->root;

    while (C)
    {
        P = C;

        IsLeft = Less(N, P, LessParameter);

        C = IsLeft ? P->left : P->right;
    }


    // Parent exists.

    if (P)
    {
        // Node.

        N->height = 1;

        N->parent = P;


        // Parent.

        if (IsLeft)
        {
            P->left = N;
        }

        else
        {
            P->right = N;
        }

        BP = ao_avl_update(P);

        ao_assert
        (
            BP >= -1 &&
            BP <= +1
        );


        // Parent was left-heavy  and is now balanced, or

        // Parent was right-heavy and is now balanced.

        // However, parent's height has not changed.

        // Therefore, we do not need to fix.

        if (BP == 0) { }


        // Parent was balanced and is now left-heavy, or

        // Parent was balanced and is now right-heavy.

        // However, parent's height has changed.

        // Therefore, we must fix.

        else
        {
            BN = BP;

            N = P;

            P = P->parent;

            while (P)
            {
                // Node exists.

                // Node is left-heavy or right-heavy.

                ao_assert(N);

                ao_assert
                (
                    BN == -1 ||
                    BN == +1
                );


                // Parent.

                BP = ao_avl_update(P);


                // Node is left child.

                if (N == P->left)
                {
                    // Parent.

                    ao_assert
                    (
                        BP ==  0 ||
                        BP == -1 ||
                        BP == -2
                    );


                    // Parent was right-heavy and is now balanced.

                    // Parent's height has not changed.

                    // Therefore, we can stop fixing.

                    if (BP == 0)
                    {
                        P = NULL;
                    }


                    // Parent was balanced and is now left-heavy.

                    // Parent's height has changed, which could have an effect on grandparent's balance.

                    // Therefore, we must continue fixing.

                    else if (BP == -1)
                    {
                        BN = BP;

                        N = P;

                        P = N->parent;
                    }


                    // Parent was left-heavy, already.

                    else
                    {
                        // Node is left-heavy.

                        if (BN < 0)
                        {
                            ao_avl_rotate_right(X, P);
                        }


                        // Node is right-heavy.

                        else
                        {
                            // Rotate left around node.

                            // Rotate right around parent.

                            ao_avl_rotate_left(X, N);

                            ao_avl_rotate_right(X, P);
                        }


                        // After the rotations, the subtree we're currently fixing has regained its previous height.

                        // Therefore, we can stop fixing.

                        P = NULL;
                    }
                }


                // Node is right child.

                else
                {
                    // Parent.

                    ao_assert
                    (
                        BP ==  0 ||
                        BP == +1 ||
                        BP == +2
                    );


                    // Parent was left-heavy and is now balanced.

                    // Parent's height has not changed.

                    // Therefore, we can stop fixing.

                    if (BP == 0)
                    {
                        P = NULL;
                    }


                    // Parent was balanced and is now right-heavy.

                    // Parent's height has changed, which could have an effect on grandparent's balance.

                    // Therefore, we must continue fixing.

                    else if (BP == +1)
                    {
                        BN = BP;

                        N = P;

                        P = N->parent;
                    }


                    // Parent was right-heavy, already.

                    else
                    {
                        // Node is right-heavy.

                        if (BN > 0)
                        {
                            // Rotate left around parent.

                            ao_avl_rotate_left(X, P);
                        }


                        // Node is left-heavy.

                        else
                        {
                            // Rotate right around node.

                            // Rotate left around parent.

                            ao_avl_rotate_right(X, N);

                            ao_avl_rotate_left(X, P);
                        }


                        // After the rotations, the subtree we're currently fixing has regained its previous height.

                        // Therefore, we can stop fixing.

                        P = NULL;
                    }
                }
            }
        }
    }


    // Parent exists not.

    // The tree is empty.

    else
    {
        X->root = N;

        N->height = 1;
    }
}

ao_avl_node_t * ao_avl_max(ao_avl_t * X)
{
    // Assert.

    ao_assert(X);


    // Variables.

    ao_avl_node_t * N = X->root;


    // Ready.

    if (N)
    {
        while (N->right)
        {
            N = N->right;
        }
    }

    return N;
}

ao_avl_node_t * ao_avl_min(ao_avl_t * X)
{
    // Assert.

    ao_assert(X);


    // Variables.

    ao_avl_node_t * N = X->root;


    // Ready.

    if (N)
    {
        while (N->left)
        {
            N = N->left;
        }
    }

    return N;
}

void ao_avl_remove(ao_avl_t * X, ao_avl_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->root);

    ao_assert(N);


    // Variables.

    ao_int_t BP;

    ao_int_t BS;

    bool IsLeft;

    ao_avl_node_t * L;

    ao_avl_node_t * P;

    ao_avl_node_t ** P2N;

    ao_avl_node_t * R;

    ao_avl_node_t * S;

    ao_avl_node_t * SL;

    ao_avl_node_t * SR;


    // Ready.

    // Node has two children.

    // Swap node with its in-order successor.

    L = N->left;

    R = N->right;

    if (L && R)
    {
        R = ao_avl_successor(N);

        ao_avl_swap(X, N, R);

        L = N->left;

        R = N->right;
    }


    // Node has at most one child.

    ao_assert(!L || !R);


    // Parent exists.

    P = N->parent;

    if (P)
    {
        IsLeft = P->left == N;

        P2N = IsLeft ? &P->left : &P->right;


        // Node has left child.

        if (L)
        {
            // Replace node by its left child.

            // This changes the height of parent's left subtree.

            // Therefore, we must fix.

            N->parent = NULL;

            N->left = NULL;

            N = L;

            *P2N = N;

            N->parent = P;
        }


        // Node has right child.

        else if (R)
        {
            // Replace node by its right child.

            // This changes the height of parent's right subtree.

            // Therefore, we must fix.

            N->parent = NULL;

            N->right  = NULL;

            N = R;

            *P2N = N;

            N->parent = P;
        }


        // Node has no children.

        else
        {
            // Remove node.

            // This changes the height of parent's node-rooted subtree.

            *P2N = NULL;

            N->parent = NULL;


            // Sibling.

            S = IsLeft ? P->right : P->left;


            // Sibling exists.

            // The need for fixing depends on sibling's height.

            if (S)
            {
                // Sibling's height is 1 or 2.

                ao_assert
                (
                    S->height == 1 ||
                    S->height == 2
                );


                // Sibling's height is 1.

                // Sibling has no children, just like node.

                // Parent's height has not changed.

                // Therefore, there is no need to fix.

                if (S->height == 1)
                {
                    P = NULL;
                }


                // Sibling's height is 2.

                // The parent-rooted subtree is not an AVL tree anymore.

                // Therefore, it must be reorganized by rotations.

                // If that changes its height, fixing must follow.

                else
                {
                    // Sibling's children.

                    SL = S->left;

                    SR = S->right;

                    ao_assert(SL || SR);


                    // Sibling is parent's right child.

                    if (IsLeft)
                    {
                        if (SR)
                        {
                            ao_avl_rotate_left(X, P);

                            if (SL)
                            {
                                ao_avl_rotate_left(X, P);

                                P = NULL;
                            }

                            else
                            {
                                N = P;

                                P = S;
                            }
                        }

                        else
                        {
                            ao_avl_rotate_right(X, S);

                            ao_avl_rotate_left(X, P);

                            N = P;

                            P = SL;
                        }
                    }


                    // Sibling is parent's left child.

                    else
                    {
                        if (SL)
                        {
                            ao_avl_rotate_right(X, P);

                            if (SR)
                            {
                                ao_avl_rotate_right(X, P);

                                P = NULL;
                            }

                            else
                            {
                                N = P;

                                P = S;
                            }
                        }

                        else
                        {
                            ao_avl_rotate_left(X, S);

                            ao_avl_rotate_right(X, P);

                            N = P;

                            P = SR;
                        }
                    }
                }
            }


            // Sibling exists not.

            // Parent has lost its only child, so its height has changed.

            // Therefore, we must fix.

            else
            {
                N = P;

                N->height = 1;

                P = N->parent;
            }
        }


        // Fix.

        while (P)
        {
            // Parent.

            BP = ao_avl_update(P);


            // Node exists.

            // Node is balanced.

            ao_assert(N);

            ao_assert(N->parent == P);

            ao_assert(ao_avl_balance(N) == 0);


            // Node is parent's left child.

            if (N == P->left)
            {
                // Parent's balance is valid.

                ao_assert
                (
                    BP ==  0 ||
                    BP == +1 ||
                    BP == +2
                );


                // Parent was left-heavy and is now balanced.

                // Parent's height has changed.

                // Therefore, we must continue fixing.

                if (BP == 0)
                {
                    N = P;

                    P = P->parent;
                }


                // Parent was balanced and is now right-heavy.

                // Parent's height has not changed.

                // Therefore, we can stop fixing.

                else if (BP == 1)
                {
                    P = NULL;
                }


                // Parent was right-heavy, already.

                // The parent-rooted subtree is not an AVL tree anymore.

                // Therefore, it must be reorganized by rotations.

                // If that changes its height, fixing must continue.

                else
                {
                    // Sibling.

                    S = P->right;


                    // Sibling's balance.

                    BS = ao_avl_balance(S);

                    ao_assert
                    (
                        BS >= -1 &&
                        BS <= +1
                    );


                    // Sibling is balanced.

                    if (BS == 0)
                    {
                        ao_avl_rotate_left(X, P);

                        P = NULL;
                    }


                    // Sibling is left-heavy.

                    else if (BS < 0)
                    {
                        SL = S->left;

                        ao_assert(SL);

                        ao_avl_rotate_right(X, S);

                        ao_avl_rotate_left(X, P);

                        N = SL;

                        P = N->parent;
                    }


                    // Sibling is right-heavy.

                    else
                    {
                        ao_avl_rotate_left(X, P);

                        N = P;

                        P = S;
                    }
                }
            }


            // Node is parent's right child.

            else
            {
                // Parent's balance is valid.

                ao_assert
                (
                    BP ==  0 ||
                    BP == -1 ||
                    BP == -2
                );


                // Parent was right-heavy and is now balanced.

                // Parent's height has changed.

                // Therefore, we must continue fixing.

                if (BP == 0)
                {
                    N = P;

                    P = P->parent;
                }


                // Parent was balanced and is now left-heavy.

                // Parent's height has not changed.

                // Therefore, we can stop fixing.

                else if (BP == -1)
                {
                    P = NULL;
                }


                // Parent was left-heavy, already.

                // The parent-rooted subtree is not an AVL tree anymore.

                // Therefore, it must be reorganized by rotations.

                // If that changes its height, fixing must continue.

                else
                {
                    // Sibling.

                    S = P->left;


                    // Sibling's balance.

                    BS = ao_avl_balance(S);

                    ao_assert
                    (
                        BS >= -1 &&
                        BS <= +1
                    );


                    // Sibling is balanced.

                    if (BS == 0)
                    {
                        ao_avl_rotate_right(X, P);

                        P = NULL;
                    }


                    // Sibling is right-heavy.

                    else if (BS > 0)
                    {
                        SR = S->right;

                        ao_assert(SR);

                        ao_avl_rotate_left(X, S);

                        ao_avl_rotate_right(X, P);

                        N = SR;

                        P = N->parent;
                    }


                    // Sibling is left-heavy.

                    else
                    {
                        ao_avl_rotate_right(X, P);

                        N = P;

                        P = S;
                    }
                }
            }
        }
    }


    // Parent exists not.

    // The root is to be removed.

    else
    {
        ao_assert(N == X->root);

        if (L)
        {
            X->root = L;

            L->parent = NULL;

            N->left = NULL;
        }

        else if (R)
        {
            X->root = R;

            R->parent = NULL;

            N->right  = NULL;
        }

        else
        {
            X->root = NULL;
        }
    }
}

ao_int_t ao_avl_rotate_left(ao_avl_t * X, ao_avl_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(N);

    ao_assert(N->right);


    // Variables.

    ao_int_t B;

    ao_int_t HL;

    ao_int_t HR;

    ao_avl_node_t * P;

    ao_avl_node_t ** P2N;

    ao_avl_node_t * R;

    ao_avl_node_t * RL;


    // Ready.

    // Rotate.

    P = N->parent;

    if (P)
    {
        if (P->left == N)
        {
            P2N = &P->left;
        }

        else
        {
            P2N = &P->right;
        }
    }

    else
    {
        P2N = &X->root;
    }

    R = N->right;

    RL = R->left;

    if (RL)
    {
        RL->parent = N;

        HR = RL->height;
    }

    else
    {
        HR = 0;
    }

    N->right = RL;

    N->parent = R;

    R->left = N;

    R->parent = P;

    *P2N = R;


    // Update N.

    HL = ao_avl_height(N->left);

    B = HR - HL;

    if (B < 0)
    {
        HL = HL + 1;
    }

    else
    {
        HL = HR + 1;
    }

    N->height = HL;


    // Update R.

    HR = ao_avl_height(R->right);

    B = HR - HL;

    if (B < 0)
    {
        R->height = 1 + HL;
    }

    else
    {
        R->height = 1 + HR;
    }

    return B;
}

ao_int_t ao_avl_rotate_right(ao_avl_t * X, ao_avl_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(N);

    ao_assert(N->left);


    // Variables.

    ao_int_t B;

    ao_int_t HL;

    ao_int_t HR;

    ao_avl_node_t * L;

    ao_avl_node_t * LR;

    ao_avl_node_t * P;

    ao_avl_node_t ** P2N;


    // Ready.

    // Rotate.

    P = N->parent;

    if (P)
    {
        if (P->left == N)
        {
            P2N = &P->left;
        }

        else
        {
            P2N = &P->right;
        }
    }

    else
    {
        P2N = &X->root;
    }

    L = N->left;

    LR = L->right;

    if (LR)
    {
        LR->parent = N;

        HL = LR->height;
    }

    else
    {
        HL = 0;
    }

    N->left = LR;

    N->parent = L;

    L->right = N;

    L->parent = P;

    *P2N = L;


    // Update N.

    HR = ao_avl_height(N->right);

    B = HR - HL;

    if (B < 0)
    {
        HR = HL + 1;
    }

    else
    {
        HR = HR + 1;
    }

    N->height = HR;


    // Update L.

    HL = ao_avl_height(L->left);

    B = HR - HL;

    if (B < 0)
    {
        L->height = HL + 1;
    }

    else
    {
        L->height = HR + 1;
    }

    return B;
}

ao_avl_node_t * ao_avl_successor(ao_avl_node_t * N)
{
    ao_assert(N);

    N = N->right;

    if (N)
    {
        while (N->left)
        {
            N = N->left;
        }
    }

    return N;
}

void ao_avl_swap(ao_avl_t * X, ao_avl_node_t * N1, ao_avl_node_t * N2)
{
    // Assert.

    ao_assert(X);

    ao_assert(N1);

    ao_assert(N2);


    // Variables.

    ao_int_t H;

    ao_avl_node_t * C1;

    ao_avl_node_t * C2;

    ao_avl_node_t * P1;

    ao_avl_node_t * P2;

    ao_avl_node_t ** P2N1;

    ao_avl_node_t ** P2N2;


    // Ready.

    // Parent.

    P1 = N1->parent;

    P2 = N2->parent;

    N1->parent = P2;

    N2->parent = P1;

    if (P1)
    {
        if (P1->left == N1)
        {
            P2N1 = &P1->left;
        }

        else
        {
            P2N1 = &P1->right;
        }
    }

    else
    {
        P2N1 = &X->root;
    }

    if (P2)
    {
        if (P2->left == N2)
        {
            P2N2 = &P2->left;
        }

        else
        {
            P2N2 = &P2->right;
        }
    }

    else
    {
        P2N2 = &X->root;
    }

    *P2N1 = N2;

    *P2N2 = N1;


    // Left.

    C1 = N1->left;

    C2 = N2->left;

    N1->left = C2;

    N2->left = C1;

    if (C1)
    {
        C1->parent = N2;
    }

    if (C2)
    {
        C2->parent = N1;
    }


    // Right.

    C1 = N1->right;

    C2 = N2->right;

    N1->right = C2;

    N2->right = C1;

    if (C1)
    {
        C1->parent = N2;
    }

    if (C2)
    {
        C2->parent = N1;
    }


    // Height.

    H = N1->height;

    N1->height = N2->height;

    N2->height = H;
}

ao_int_t ao_avl_update(ao_avl_node_t * N)
{
    // Assert.

    ao_assert(N);


    // Variables.

    ao_int_t B;

    ao_int_t HL;

    ao_int_t HR;


    // Ready.

    HL = ao_avl_height(N->left);

    HR = ao_avl_height(N->right);

    B = HR - HL;

    if (B < 0)
    {
        N->height = HL + 1;
    }

    else
    {
        N->height = HR + 1;
    }

    return B;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_BUFFER

// ----------------------------------------------------------------------------

bool ao_buffer_peek_back(ao_buffer_t const * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    uint8_t *   pi;
    uint8_t *   po;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C = x->capacity;        ao_assert(c <= C);

    i = x->front;           ao_assert(i <  C);

    i = (i + c - 1) % C;

    pi = x->store;          ao_assert(pi);

    po = p;                 ao_assert(po);

    *po = *(pi + i);

    return true;
}

bool ao_buffer_peek_front(ao_buffer_t const * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    uint8_t *   pi;
    uint8_t *   po;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C = x->capacity;        ao_assert(c <= C);

    i = x->front;           ao_assert(i <  C);

    pi = x->store;          ao_assert(pi);

    po = p;                 ao_assert(po);

    *po = *(pi + i);

    return true;
}

// ----------------------------------------------------------------------------

size_t ao_buffer_peek_range_back(ao_buffer_t const * x, void * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    size_t      n;

    size_t      n1;
    size_t      n2;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        i = (i + c - n) % C;

        t = C - i;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        ao_memcpy(po,      pi + i, n1);

        ao_memcpy(po + n1, pi,     n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer_peek_range_front(ao_buffer_t const * x, void * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    size_t      n;

    size_t      n1;
    size_t      n2;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        t = C - i;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        ao_memcpy(po,      pi + i, n1);

        ao_memcpy(po + n1, pi,     n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

// ----------------------------------------------------------------------------

bool ao_buffer_pop_back(ao_buffer_t * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    uint8_t *   pi;
    uint8_t *   po;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C = x->capacity;        ao_assert(c <= C);

    i = x->front;           ao_assert(i <  C);

    i = (i + c - 1) % C;

    pi = x->store;          ao_assert(pi);

    po = p;                 ao_assert(po);

    x->count = c - 1;

    *po = *(pi + i);

    return true;
}

bool ao_buffer_pop_front(ao_buffer_t * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    uint8_t *   pi;
    uint8_t *   po;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C = x->capacity;        ao_assert(c <= C);

    i = x->front;           ao_assert(i <  C);

    pi = x->store;          ao_assert(pi);

    po = p;                 ao_assert(po);

    x->count = c - 1;

    x->front = (i + 1) % C;

    *po = *(pi + i);

    return true;
}

// ----------------------------------------------------------------------------

size_t ao_buffer_pop_range_back(ao_buffer_t * x, void * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    size_t      n;

    size_t      n1;
    size_t      n2;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        i = (i + c - n) % C;

        t = C - i;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        x->count = c - n;

        ao_memcpy(po,      pi + i, n1);

        ao_memcpy(po + n1, pi,     n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer_pop_range_front(ao_buffer_t * x, void * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    size_t      n;

    size_t      n1;
    size_t      n2;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        t = C - i;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        x->count = c - n;

        x->front = (i + n) % C;

        ao_memcpy(po,      pi + i, n1);

        ao_memcpy(po + n1, pi,     n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

// ----------------------------------------------------------------------------

bool ao_buffer_push_back(ao_buffer_t * x, void const * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    uint8_t const * pi;
    uint8_t       * po;

#if AO_BUFFER_COUNT_MAX

    size_t          t;

#endif


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    if (c == C) return false;


    // Ready.

    f = x->front;               ao_assert(f < C);

    f = (f + c) % C;

    pi = p;                     ao_assert(pi);

    po = x->store;              ao_assert(po);

#if AO_BUFFER_COUNT_MAX

    t = x->count_max;           ao_assert(c <= t && t <= C);

#endif

    c = c + 1;

#if AO_BUFFER_COUNT_MAX

    x->count_max = ao_max(t, c);

#endif

    x->count = c;

    *(po + f) = *pi;

    return true;
}

bool ao_buffer_push_back_override(ao_buffer_t * x, void const * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          i;

    uint8_t const * pi;
    uint8_t       * po;

#if AO_BUFFER_COUNT_MAX

    size_t          t;

#endif


    // Ready.

    C = x->capacity;

    if (C == 0) return false;


    // Ready.

    c = x->count;           ao_assert(c <= C);

    f = x->front;           ao_assert(f < C);

    i = (f + c) % C;

    pi = p;                 ao_assert(pi);

    po = x->store;          ao_assert(po);

#if AO_BUFFER_COUNT_MAX

    t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

    if (c == C)
    {
        x->front = (f + 1) % C;
    }

    else
    {
        c = c + 1;
    }

#if AO_BUFFER_COUNT_MAX

    x->count_max = ao_max(t, c);

#endif

    x->count = c;

    *(po + f) = *pi;

    return true;
}

bool ao_buffer_push_front(ao_buffer_t * x, void const * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    uint8_t const * pi;
    uint8_t       * po;

#if AO_BUFFER_COUNT_MAX

    size_t          t;

#endif


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    if (c == C) return false;


    // Ready.

    f = x->front;               ao_assert(f < C);

    f = (f + C - 1) % C;

    pi = p;                     ao_assert(pi);

    po = x->store;              ao_assert(po);

#if AO_BUFFER_COUNT_MAX

    t = x->count_max;           ao_assert(c <= t && t <= C);

#endif

    c = c + 1;

#if AO_BUFFER_COUNT_MAX

    x->count_max = ao_max(t, c);

#endif

    x->count = c;

    x->front = f;

    *(po + f) = *pi;

    return true;
}

bool ao_buffer_push_front_override(ao_buffer_t * x, void const * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    uint8_t const * pi;
    uint8_t       * po;

#if AO_BUFFER_COUNT_MAX

    size_t          t;

#endif


    // Ready.

    C = x->capacity;

    if (C == 0) return false;


    // Ready.

    c = x->count;           ao_assert(c <= C);

    f = x->front;           ao_assert(f < C);

    f = (f + C - 1) % C;

    pi = p;                 ao_assert(pi);

    po = x->store;          ao_assert(po);

#if AO_BUFFER_COUNT_MAX

    t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

    if (c == C) { }

    else
    {
        c = c + 1;
    }

#if AO_BUFFER_COUNT_MAX

    x->count_max = ao_max(t, c);

#endif

    x->count = c;

    x->front = f;

    *(po + f) = *pi;

    return true;
}

// ----------------------------------------------------------------------------

size_t ao_buffer_push_range_back(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          n;

    size_t          n1;
    size_t          n2;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          t;


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    t = C - c;

    if (t >= n_min)
    {
        n = ao_min(t, n_max);

        f = x->front;           ao_assert(f < C);

        f = (f + c) % C;

        t = C - f;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER_COUNT_MAX

        t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

        c = c + n;

#if AO_BUFFER_COUNT_MAX

        t = ao_max(t, c);

        x->count_max = t;

#endif

        x->count = c;

        ao_memcpy(po + f, pi,      n1);

        ao_memcpy(po,     pi + n1, n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer_push_range_back_override(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          i;

    size_t          n;

    size_t          n1;
    size_t          n2;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          t1;

#if AO_BUFFER_COUNT_MAX

    size_t          t2;

#endif


    // Ready.

    C = x->capacity;

    if (C >= n_min)
    {
        n = ao_min(C, n_max);

        c = x->count;           ao_assert(c <= C);

        f = x->front;           ao_assert(f < C);

        i = (f + c) % C;

        t1 = C - i;

        if (t1 >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t1;
            n2 = n - t1;
        }

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER_COUNT_MAX

        t2 = x->count_max;      ao_assert(c <= t2 && t2 <= C);

#endif

        t1 = C - c;

        if (t1 < n)
        {
            c = C;

            f = (f + n - t1) % C;

            x->front = f;
        }

        else
        {
            c = c + n;
        }

#if AO_BUFFER_COUNT_MAX

        t2 = ao_max(t2, c);

        x->count_max = t2;

#endif

        x->count = c;

        ao_memcpy(po + i, pi,      n1);

        ao_memcpy(po,     pi + n1, n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer_push_range_front(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          n;

    size_t          n1;
    size_t          n2;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          t;


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    t = C - c;

    if (t >= n_min)
    {
        n = ao_min(t, n_max);

        f = x->front;           ao_assert(f < C);

        f = (f + C - n) % C;

        t = C - f;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER_COUNT_MAX

        t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

        c = c + n;

#if AO_BUFFER_COUNT_MAX

        t = ao_max(t, c);

        x->count_max = t;

#endif

        x->count = c;

        x->front = f;

        ao_memcpy(po + f, pi,      n1);

        ao_memcpy(po,     pi + n1, n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer_push_range_front_override(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          n;

    size_t          n1;
    size_t          n2;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          t1;

#if AO_BUFFER_COUNT_MAX

    size_t          t2;

#endif


    // Ready.

    C = x->capacity;

    if (C >= n_min)
    {
        n = ao_min(C, n_max);

        c = x->count;           ao_assert(c <= C);

        f = x->front;           ao_assert(f < C);

        f = (f + C - n) % C;

        t1 = C - f;

        if (t1 >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t1;
            n2 = n - t1;
        }

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER_COUNT_MAX

        t2 = x->count_max;      ao_assert(c <= t2 && t2 <= C);

#endif

        t1 = C - c;

        if (t1 < n)
        {
            c = C;
        }

        else
        {
            c = c + n;
        }

#if AO_BUFFER_COUNT_MAX

        t2 = ao_max(t2, c);

        x->count_max = t2;

#endif

        x->count = c;

        x->front = f;

        ao_memcpy(po + f, pi,      n1);

        ao_memcpy(po,     pi + n1, n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_BUFFER4OBJ

// ----------------------------------------------------------------------------

bool ao_buffer4obj_peek_back(ao_buffer4obj_t const * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      s;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C = x->capacity;            ao_assert(c <= C);

    i = x->front;               ao_assert(i <  C);

    s = x->size;

    i = (i + c - 1) % C;

    pi = x->store;              ao_assert(pi);

    po = p;                     ao_assert(po);

    ao_memcpy(po, pi + s * i, s);

    return true;
}

bool ao_buffer4obj_peek_front(ao_buffer4obj_t const * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t      c;

    size_t      i;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      s;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    i = x->front;

    s = x->size;

    pi = x->store;              ao_assert(pi);

    po = p;                     ao_assert(po);

    ao_memcpy(po, pi + s * i, s);

    return true;
}

// ----------------------------------------------------------------------------

size_t ao_buffer4obj_peek_range_back(ao_buffer4obj_t const * x, void * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    size_t      n;

    size_t      n1;
    size_t      n2;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      s;

    size_t      t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        s = x->size;

        i = (i + c - n) % C;

        t = C - i;

        if (t >= n)
        {
            n1 = s * n;
            n2 = 0;
        }

        else
        {
            n1 = s * t;
            n2 = s * (n - t);
        }

        i = s * i;

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        ao_memcpy(po,      pi + i, n1);

        ao_memcpy(po + n1, pi,     n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4obj_peek_range_front(ao_buffer4obj_t const * x, void * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    size_t      n;

    size_t      n1;
    size_t      n2;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      s;

    size_t      t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        s = x->size;

        t = C - i;

        if (t >= n)
        {
            n1 = s * n;
            n2 = 0;
        }

        else
        {
            n1 = s * t;
            n2 = s * (n - t);
        }

        i = s * i;

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        ao_memcpy(po,      pi + i, n1);

        ao_memcpy(po + n1, pi,     n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

// ----------------------------------------------------------------------------

bool ao_buffer4obj_pop_back(ao_buffer4obj_t * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      s;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C = x->capacity;            ao_assert(c <= C);

    i = x->front;               ao_assert(i <  C);

    s = x->size;

    i = (i + c - 1) % C;

    pi = x->store;              ao_assert(pi);

    po = p;                     ao_assert(po);

    x->count = c - 1;

    ao_memcpy(po, pi + s * i, s);

    return true;
}

bool ao_buffer4obj_pop_front(ao_buffer4obj_t * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      f;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      s;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C = x->capacity;            ao_assert(c <= C);

    f = x->front;               ao_assert(f <  C);

    s = x->size;

    pi = x->store;              ao_assert(pi);

    po = p;                     ao_assert(po);

    x->count = c - 1;

    x->front = (f + 1) % C;

    ao_memcpy(po, pi + s * f, s);

    return true;
}

// ----------------------------------------------------------------------------

size_t ao_buffer4obj_pop_range_back(ao_buffer4obj_t * x, void * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      i;

    size_t      n;

    size_t      n1;
    size_t      n2;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      s;

    size_t      t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        s = x->size;

        i = (i + c - n) % C;

        t = C - i;

        if (t >= n)
        {
            n1 = s * n;
            n2 = 0;
        }

        else
        {
            n1 = s * t;
            n2 = s * (n - t);
        }

        i = s * i;

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        x->count = c - n;

        ao_memcpy(po,      pi + i, n1);

        ao_memcpy(po + n1, pi,     n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4obj_pop_range_front(ao_buffer4obj_t * x, void * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t      c;

    size_t      C;

    size_t      f;

    size_t      i;

    size_t      n;

    size_t      n1;
    size_t      n2;

    uint8_t *   pi;
    uint8_t *   po;

    size_t      s;

    size_t      t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        f = x->front;           ao_assert(f <  C);

        s = x->size;

        t = C - f;

        if (t >= n)
        {
            n1 = s * n;
            n2 = 0;
        }

        else
        {
            n1 = s * t;
            n2 = s * (n - t);
        }

        i = s * f;

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        x->count = c - n;

        x->front = (f + n) % C;

        ao_memcpy(po,      pi + i, n1);

        ao_memcpy(po + n1, pi,     n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

// ----------------------------------------------------------------------------

bool ao_buffer4obj_push_back(ao_buffer4obj_t * x, void const * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          n;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          s;

#if AO_BUFFER4OBJ_COUNT_MAX

    size_t          t;

#endif


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    if (c == C) return false;


    // Ready.

    f = x->front;               ao_assert(f < C);

    s = x->size;

    pi = p;                     ao_assert(pi);

    po = x->store;              ao_assert(po);

    f = (f + c) % C;

#if AO_BUFFER4OBJ_COUNT_MAX

    t = x->count_max;           ao_assert(c <= t && t <= C);

#endif

    c = c + 1;

    x->count = c;

#if AO_BUFFER4OBJ_COUNT_MAX

    x->count_max = ao_max(t, c);

#endif

    ao_memcpy(po + s * f, pi, s);

    return true;
}

bool ao_buffer4obj_push_back_override(ao_buffer4obj_t * x, void const * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          i;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          s;

#if AO_BUFFER4OBJ_COUNT_MAX

    size_t          t;

#endif


    // Ready.

    C = x->capacity;

    if (C == 0) return false;


    // Ready.

    c = x->count;               ao_assert(c <= C);

    f = x->front;               ao_assert(f < C);

    s = x->size;

    pi = p;                     ao_assert(pi);

    po = x->store;              ao_assert(po);

    if (c == C)
    {
        i = f;

        x->front = (f + 1) % C;
    }

    else
    {

#if AO_BUFFER4OBJ_COUNT_MAX

        t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

        i = (f + c) % C;

        c = c + 1;

        x->count = c;

#if AO_BUFFER4OBJ_COUNT_MAX

        x->count_max = ao_max(t, c);

#endif

    }

    ao_memcpy(po + s * i, pi, s);

    return true;
}

bool ao_buffer4obj_push_front(ao_buffer4obj_t * x, void const * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          s;

#if AO_BUFFER4OBJ_COUNT_MAX

    size_t          t;

#endif


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    if (c == C) return false;


    // Ready.

    f = x->front;               ao_assert(f < C);

    s = x->size;

    pi = p;                     ao_assert(pi);

    po = x->store;              ao_assert(po);

    f = (f + C - 1) % C;

#if AO_BUFFER4OBJ_COUNT_MAX

    t = x->count_max;           ao_assert(c <= t && t <= C);

#endif

    c = c + 1;

    x->count = c;

#if AO_BUFFER4OBJ_COUNT_MAX

    x->count_max = ao_max(t, c);

#endif

    x->front = f;

    ao_memcpy(po + s * f, pi, s);

    return true;
}

bool ao_buffer4obj_push_front_override(ao_buffer4obj_t * x, void const * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          s;

#if AO_BUFFER4OBJ_COUNT_MAX

    size_t          t;

#endif


    // Ready.

    C = x->capacity;

    if (C == 0) return false;


    // Ready.

    c = x->count;           ao_assert(c <= C);

    f = x->front;           ao_assert(f < C);

    s = x->size;

    pi = p;                 ao_assert(pi);

    po = x->store;          ao_assert(po);

    f = (f + C - 1) % C;

    if (c != C)
    {

#if AO_BUFFER4OBJ_COUNT_MAX

        t = x->count_max;   ao_assert(c <= t && t <= C);

#endif

        c = c + 1;

        x->count = c;

#if AO_BUFFER4OBJ_COUNT_MAX

        x->count_max = ao_max(t, c);

#endif

    }

    x->front = f;

    ao_memcpy(po + s * f, pi, s);

    return true;
}

// ----------------------------------------------------------------------------

size_t ao_buffer4obj_push_range_back(ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          i;

    size_t          n;

    size_t          n1;
    size_t          n2;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          s;

    size_t          t;


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    t = C - c;

    if (t >= n_min)
    {
        n = ao_min(t, n_max);

        f = x->front;           ao_assert(f < C);

        s = x->size;

        f = (f + c) % C;

        t = C - f;

        if (t >= n)
        {
            n1 = s * n;
            n2 = 0;
        }

        else
        {
            n1 = s * t;
            n2 = s * (n - t);
        }

        i = s * f;

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER4OBJ_COUNT_MAX

        t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

        c = c + n;

#if AO_BUFFER4OBJ_COUNT_MAX

        t = ao_max(t, c);

        x->count_max = t;

#endif

        x->count = c;

        ao_memcpy(po + i, pi,      n1);

        ao_memcpy(po,     pi + n1, n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4obj_push_range_back_override(ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          i;

    size_t          n;

    size_t          n1;
    size_t          n2;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          s;

    size_t          t1;

#if AO_BUFFER4OBJ_COUNT_MAX

    size_t          t2;

#endif


    // Ready.

    C = x->capacity;

    if (C >= n_min)
    {
        n = ao_min(C, n_max);

        c = x->count;           ao_assert(c <= C);

        f = x->front;           ao_assert(f < C);

        s = x->size;

        i = (f + c) % C;

        t1 = C - i;

        if (t1 >= n)
        {
            n1 = s * n;
            n2 = 0;
        }

        else
        {
            n1 = s * t1;
            n2 = s * (n - t1);
        }

        i = s * i;

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER4OBJ_COUNT_MAX

        t2 = x->count_max;      ao_assert(c <= t2 && t2 <= C);

#endif

        t1 = C - c;

        if (t1 < n)
        {
            c = C;

            f = (f + n - t1) % C;

            x->front = f;
        }

        else
        {
            c = c + n;
        }

#if AO_BUFFER4OBJ_COUNT_MAX

        t2 = ao_max(t2, c);

        x->count_max = t2;

#endif

        x->count = c;

        ao_memcpy(po + i, pi,      n1);

        ao_memcpy(po,     pi + n1, n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4obj_push_range_front(ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          i;

    size_t          n;

    size_t          n1;
    size_t          n2;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          s;

    size_t          t;


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    t = C - c;

    if (t >= n_min)
    {
        n = ao_min(t, n_max);

        f = x->front;           ao_assert(f < C);

        s = x->size;

        f = (f + C - n) % C;

        t = C - f;

        if (t >= n)
        {
            n1 = s * n;
            n2 = 0;
        }

        else
        {
            n1 = s * t;
            n2 = s * (n - t);
        }

        i = s * f;

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER4OBJ_COUNT_MAX

        t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

        c = c + n;

#if AO_BUFFER4OBJ_COUNT_MAX

        t = ao_max(t, c);

        x->count_max = t;

#endif

        x->count = c;

        x->front = f;

        ao_memcpy(po + i, pi,      n1);

        ao_memcpy(po,     pi + n1, n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4obj_push_range_front_override(ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          i;

    size_t          n;

    size_t          n1;
    size_t          n2;

    uint8_t const * pi;
    uint8_t       * po;

    size_t          s;

    size_t          t1;

#if AO_BUFFER4OBJ_COUNT_MAX

    size_t          t2;

#endif


    // Ready.

    C = x->capacity;

    if (C >= n_min)
    {
        n = ao_min(C, n_max);

        c = x->count;           ao_assert(c <= C);

        f = x->front;           ao_assert(f < C);

        s = x->size;

        f = (f + C - n) % C;

        t1 = C - f;

        if (t1 >= n)
        {
            n1 = s * n;
            n2 = 0;
        }

        else
        {
            n1 = s * t1;
            n2 = s * (n - t1);
        }

        i = s * f;

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER4OBJ_COUNT_MAX

        t2 = x->count_max;      ao_assert(c <= t2 && t2 <= C);

#endif

        t1 = C - c;

        if (t1 < n)
        {
            c = C;
        }

        else
        {
            c = c + n;
        }

#if AO_BUFFER4OBJ_COUNT_MAX

        t2 = ao_max(t2, c);

        x->count_max = t2;

#endif

        x->count = c;

        x->front = f;

        ao_memcpy(po + i, pi,      n1);

        ao_memcpy(po,     pi + n1, n2);
    }

    else
    {
        n = 0;
    }

    return n;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_BUFFER4PTR

// ----------------------------------------------------------------------------

bool ao_buffer4ptr_peek_back(ao_buffer4ptr_t const * x, void ** p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  i;

    void ** pi;
    void ** po;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C   = x->capacity;      ao_assert(c <= C);

    i   = x->front;         ao_assert(i <  C);

    i   = (i + c - 1) % C;

    po  = p;                ao_assert(po);

    pi  = x->store;         ao_assert(pi);

    *po = *(pi + i);

    return true;
}

bool ao_buffer4ptr_peek_front(ao_buffer4ptr_t const * x, void ** p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t  c;

    size_t  i;

    void ** pi;
    void ** po;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    po  = p;            ao_assert(po);

    pi  = x->store;     ao_assert(pi);

    i   = x->front;

    *po = *(pi + i);

    return true;
}

// ----------------------------------------------------------------------------

size_t ao_buffer4ptr_peek_range_back(ao_buffer4ptr_t const * x, void ** p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  i;

    size_t  n;

    size_t  n1;
    size_t  n2;

    void ** pi;
    void ** po;

    size_t  t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        i = (i + c - n) % C;

        t = C - i;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        ao_memcpy(po,      pi + i, n1 * sizeof(void *));

        ao_memcpy(po + n1, pi,     n2 * sizeof(void *));
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4ptr_peek_range_front(ao_buffer4ptr_t const * x, void ** p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  i;

    size_t  n;

    size_t  n1;
    size_t  n2;

    void ** pi;
    void ** po;

    size_t  t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        t = C - i;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        ao_memcpy(po,      pi + i, n1 * sizeof(void *));

        ao_memcpy(po + n1, pi,     n2 * sizeof(void *));
    }

    else
    {
        n = 0;
    }

    return n;
}

// ----------------------------------------------------------------------------

bool ao_buffer4ptr_pop_back(ao_buffer4ptr_t * x, void ** p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  i;

    void ** pi;
    void ** po;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C = x->capacity;        ao_assert(c <= C);

    c = c - 1;

    i = x->front;           ao_assert(i <  C);

    i = (i + c) % C;

    pi = x->store;          ao_assert(pi);

    po = p;                 ao_assert(po);

    *po = *(pi + i);

    x->count = c;

    return true;
}

bool ao_buffer4ptr_pop_front(ao_buffer4ptr_t * x, void ** p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  f;

    void ** pi;
    void ** po;


    // Ready.

    c = x->count;

    if (c == 0) return false;


    // Ready.

    C = x->capacity;            ao_assert(c <= C);

    f = x->front;               ao_assert(f <  C);

    pi = x->store;              ao_assert(pi);

    po = p;                     ao_assert(po);

    *po = *(pi + f);

    x->count = c - 1;

    x->front = (f + 1) % C;

    return true;
}

// ----------------------------------------------------------------------------

size_t ao_buffer4ptr_pop_range_back(ao_buffer4ptr_t * x, void ** p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  i;

    size_t  n;

    size_t  n1;
    size_t  n2;

    void ** pi;
    void ** po;

    size_t  t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        i = x->front;           ao_assert(i <  C);

        i = (i + c - n) % C;

        t = C - i;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        x->count = c - n;

        ao_memcpy(po,      pi + i, n1 * sizeof(void *));

        ao_memcpy(po + n1, pi,     n2 * sizeof(void *));
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4ptr_pop_range_front(ao_buffer4ptr_t * x, void ** p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  f;

    size_t  n;

    size_t  n1;
    size_t  n2;

    void ** pi;
    void ** po;

    size_t  t;


    // Ready.

    c = x->count;

    if (c >= n_min)
    {
        n = ao_min(c, n_max);

        C = x->capacity;        ao_assert(c <= C);

        f = x->front;           ao_assert(f <  C);

        t = C - f;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = x->store;          ao_assert(pi);

        po = p;                 ao_assert(po);

        x->count = c - n;

        x->front = (f + n) % C;

        ao_memcpy(po,      pi + f, n1 * sizeof(void *));

        ao_memcpy(po + n1, pi,     n2 * sizeof(void *));
    }

    else
    {
        n = 0;
    }

    return n;
}

// ----------------------------------------------------------------------------

bool ao_buffer4ptr_push_back(ao_buffer4ptr_t * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  f;

    size_t  n;

    void ** q;

#if AO_BUFFER4PTR_COUNT_MAX

    size_t  t;

#endif


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    if (c == C) return false;


    // Ready.

    f = x->front;               ao_assert(f < C);

    q = x->store;               ao_assert(q);

    f = (f + c) % C;

#if AO_BUFFER4PTR_COUNT_MAX

    t = x->count_max;           ao_assert(c <= t && t <= C);

#endif

    c = c + 1;

    x->count = c;

#if AO_BUFFER4PTR_COUNT_MAX

    x->count_max = ao_max(t, c);

#endif

    *(q + f) = p;

    return true;
}

bool ao_buffer4ptr_push_back_override(ao_buffer4ptr_t * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  f;

    size_t  i;

    void ** q;

#if AO_BUFFER4PTR_COUNT_MAX

    size_t  t;

#endif


    // Ready.

    C = x->capacity;

    if (C == 0) return false;


    // Ready.

    c = x->count;               ao_assert(c <= C);

    f = x->front;               ao_assert(f < C);

    q = x->store;               ao_assert(q);

    if (c == C)
    {
        i = f;

        x->front = (f + 1) % C;
    }

    else
    {

#if AO_BUFFER4PTR_COUNT_MAX

        t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

        i = (f + c) % C;

        c = c + 1;

        x->count = c;

#if AO_BUFFER4PTR_COUNT_MAX

        x->count_max = ao_max(t, c);

#endif

    }

    *(q + i) = p;

    return true;
}

bool ao_buffer4ptr_push_front(ao_buffer4ptr_t * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  f;

    void ** q;

#if AO_BUFFER4PTR_COUNT_MAX

    size_t  t;

#endif


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    if (c == C) return false;


    // Ready.

    f = x->front;               ao_assert(f < C);

    q = x->store;               ao_assert(q);

    f = (f + C - 1) % C;

#if AO_BUFFER4PTR_COUNT_MAX

    t = x->count_max;           ao_assert(c <= t && t <= C);

#endif

    c = c + 1;

    x->count = c;

#if AO_BUFFER4PTR_COUNT_MAX

    x->count_max = ao_max(t, c);

#endif

    x->front = f;

    *(q + f) = p;

    return true;
}

bool ao_buffer4ptr_push_front_override(ao_buffer4ptr_t * x, void * p)
{
    // Assert.

    ao_assert(x);


    // Variables.

    size_t  c;

    size_t  C;

    size_t  f;

    void ** q;

#if AO_BUFFER4PTR_COUNT_MAX

    size_t  t;

#endif


    // Ready.

    C = x->capacity;

    if (C == 0) return false;


    // Ready.

    c = x->count;           ao_assert(c <= C);

    f = x->front;           ao_assert(f < C);

    q = x->store;           ao_assert(q);

    f = (f + C - 1) % C;

    if (c != C)
    {

#if AO_BUFFER4PTR_COUNT_MAX

        t = x->count_max;   ao_assert(c <= t && t <= C);

#endif

        c = c + 1;

        x->count = c;

#if AO_BUFFER4PTR_COUNT_MAX

        x->count_max = ao_max(t, c);

#endif

    }

    x->front = f;

    *(q + f) = p;

    return true;
}

// ----------------------------------------------------------------------------

size_t ao_buffer4ptr_push_range_back(ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          n;

    size_t          n1;
    size_t          n2;

    void * const *  pi;
    void **         po;

    size_t          t;


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    t = C - c;

    if (t >= n_min)
    {
        n = ao_min(t, n_max);

        f = x->front;           ao_assert(f < C);

        f = (f + c) % C;

        t = C - f;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER4PTR_COUNT_MAX

        t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

        c = c + n;

#if AO_BUFFER4PTR_COUNT_MAX

        t = ao_max(t, c);

        x->count_max = t;

#endif

        x->count = c;

        ao_memcpy(po + f, pi,      n1 * sizeof(void *));

        ao_memcpy(po,     pi + n1, n2 * sizeof(void *));
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4ptr_push_range_back_override(ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          i;

    size_t          n;

    size_t          n1;
    size_t          n2;

    void * const *  pi;
    void **         po;

    size_t          t1;

#if AO_BUFFER4PTR_COUNT_MAX

    size_t          t2;

#endif


    // Ready.

    C = x->capacity;

    if (C >= n_min)
    {
        n = ao_min(C, n_max);

        c = x->count;           ao_assert(c <= C);

        f = x->front;           ao_assert(f < C);

        i = (f + c) % C;

        t1 = C - i;

        if (t1 >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t1;
            n2 = n - t1;
        }

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER4PTR_COUNT_MAX

        t2 = x->count_max;      ao_assert(c <= t2 && t2 <= C);

#endif

        t1 = C - c;

        if (t1 < n)
        {
            c = C;

            f = (f + n - t1) % C;

            x->front = f;
        }

        else
        {
            c = c + n;
        }

#if AO_BUFFER4PTR_COUNT_MAX

        t2 = ao_max(t2, c);

        x->count_max = t2;

#endif

        x->count = c;

        ao_memcpy(po + i, pi,      n1 * sizeof(void *));

        ao_memcpy(po,     pi + n1, n2 * sizeof(void *));
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4ptr_push_range_front(ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          n;

    size_t          n1;
    size_t          n2;

    void * const *  pi;
    void **         po;

    size_t          t;


    // Ready.

    C = x->capacity;

    c = x->count;               ao_assert(c <= C);

    t = C - c;

    if (t >= n_min)
    {
        n = ao_min(t, n_max);

        f = x->front;           ao_assert(f < C);

        f = (f + C - n) % C;

        t = C - f;

        if (t >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t;
            n2 = n - t;
        }

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER4PTR_COUNT_MAX

        t = x->count_max;       ao_assert(c <= t && t <= C);

#endif

        c = c + n;

#if AO_BUFFER4PTR_COUNT_MAX

        t = ao_max(t, c);

        x->count_max = t;

#endif

        x->count = c;

        x->front = f;

        ao_memcpy(po + f, pi,      n1 * sizeof(void *));

        ao_memcpy(po,     pi + n1, n2 * sizeof(void *));
    }

    else
    {
        n = 0;
    }

    return n;
}

size_t ao_buffer4ptr_push_range_front_override(ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max)
{
    // Assert.

    ao_assert(x);

    ao_assert(n_min <= n_max);


    // Variables.

    size_t          c;

    size_t          C;

    size_t          f;

    size_t          i;

    size_t          n;

    size_t          n1;
    size_t          n2;

    void * const *  pi;
    void **         po;

    size_t          t1;

#if AO_BUFFER4PTR_COUNT_MAX

    size_t          t2;

#endif


    // Ready.

    C = x->capacity;

    if (C >= n_min)
    {
        n = ao_min(C, n_max);

        c = x->count;           ao_assert(c <= C);

        f = x->front;           ao_assert(f < C);

        f = (f + C - n) % C;

        t1 = C - f;

        if (t1 >= n)
        {
            n1 = n;
            n2 = 0;
        }

        else
        {
            n1 = t1;
            n2 = n - t1;
        }

        i = f;

        pi = p;                 ao_assert(pi);

        po = x->store;          ao_assert(po);

#if AO_BUFFER4PTR_COUNT_MAX

        t2 = x->count_max;      ao_assert(c <= t2 && t2 <= C);

#endif

        t1 = C - c;

        if (t1 < n)
        {
            c = C;
        }

        else
        {
            c = c + n;
        }

#if AO_BUFFER4PTR_COUNT_MAX

        t2 = ao_max(t2, c);

        x->count_max = t2;

#endif

        x->count = c;

        x->front = f;

        ao_memcpy(po + i, pi,      n1 * sizeof(void *));

        ao_memcpy(po,     pi + n1, n2 * sizeof(void *));
    }

    else
    {
        n = 0;
    }

    return n;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_CHAR

// ----------------------------------------------------------------------------

#ifndef ao_char_is_alphanumeric

bool ao_char_is_alphanumeric(char x)
{
    return
        (0x30 <= x && x <= 0x39) ||
        (0x41 <= x && x <= 0x5A) ||
        (0x61 <= x && x <= 0x7A);
}

#endif

#ifndef ao_char_is_alphabetic

bool ao_char_is_alphabetic(char x)
{
    return
        (0x41 <= x && x <= 0x5A) ||
        (0x61 <= x && x <= 0x7A);
}

#endif

#ifndef ao_char_is_blank

bool ao_char_is_blank(char x)
{
    return x == 0x09 || x == 0x20;
}

#endif

#ifndef ao_char_is_control

bool ao_char_is_control(char x)
{
    return (0x00 <= x && x <= 0x1F) || (x == 0x7F);
}

#endif

#ifndef ao_char_is_decimal

bool ao_char_is_decimal(char x)
{
    return 0x30 <= x && x <= 0x39;
}

#endif

#ifndef ao_char_is_graphical

bool ao_char_is_graphical(char x)
{
    return 0x21 <= x && x <= 0x7E;
}

#endif

#ifndef ao_char_is_hexadecimal

bool ao_char_is_hexadecimal(char x)
{
    return
        (0x30 <= x && x <= 0x39) ||
        (0x41 <= x && x <= 0x46) ||
        (0x61 <= x && x <= 0x66);
}

#endif

#ifndef ao_char_is_lower

bool ao_char_is_lower(char x)
{
    return 0x61 <= x && x <= 0x7A;
}

#endif

#ifndef ao_char_is_printable

bool ao_char_is_printable(char x)
{
    return 0x20 <= x && x <= 0x7E;
}

#endif

#ifndef ao_char_is_punctuation

bool ao_char_is_punctuation(char x)
{
    return
        (0x21 <= x && x <= 0x2F) ||
        (0x3A <= x && x <= 0x40) ||
        (0x5B <= x && x <= 0x60) ||
        (0x7B <= x && x <= 0x7E);
}

#endif

#ifndef ao_char_is_upper

bool ao_char_is_upper(char x)
{
    return 0x41 <= x && x <= 0x5A;
}

#endif

#ifndef ao_char_is_whitespace

bool ao_char_is_whitespace(char x)
{
    return (0x09 <= x && x <= 0x0D) || (x == 0x20);
}

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_HEAP

// ----------------------------------------------------------------------------

static  ao_uint_t   ao_heap_assert_node(ao_heap_t * X, ao_heap_node_t * N);

// ----------------------------------------------------------------------------

static  void        ao_heap_down(       ao_heap_t * X, ao_heap_node_t * N);

// ----------------------------------------------------------------------------

static  void        ao_heap_replace(    ao_heap_t * X, ao_heap_node_t * N1, ao_heap_node_t * N2);

// ----------------------------------------------------------------------------

static  void        ao_heap_swap_left(  ao_heap_t * X, ao_heap_node_t * N);

static  void        ao_heap_swap_parent(ao_heap_t * X, ao_heap_node_t * N);

static  void        ao_heap_swap_right( ao_heap_t * X, ao_heap_node_t * N);

// ----------------------------------------------------------------------------

static  void        ao_heap_up(         ao_heap_t * X, ao_heap_node_t * N);

// ----------------------------------------------------------------------------

void ao_heap_assert(ao_heap_t * X)
{
    // Variables.

    ao_uint_t C1;

    ao_uint_t C2;

    ao_heap_node_t * N;


    // Ready.

    C1 = X->count;

    N = X->root;

    if (N)
    {
        ao_assert(!N->parent);

        C2 = ao_heap_assert_node(X, N);

        ao_assert(C1 == C2);
    }

    else
    {
        ao_assert(C1 == 0);
    }

#if AO_HEAP_COUNT_MAX

    ao_assert(C1 <= X->count_max);

#endif

}

ao_uint_t ao_heap_assert_node(ao_heap_t * X, ao_heap_node_t * N)
{
    // Variables.

    ao_uint_t CL;

    ao_uint_t CR;

    ao_heap_node_t * L;

    ao_heap_less_t Less;

    void * LessParameter;

    ao_heap_node_t * R;


    // Ready.

    L = N->left;

    if (L)
    {
        Less = X->less;

        LessParameter = X->less_parameter;

        ao_assert(N == L->parent);

        ao_assert(Less(N, L, LessParameter));

        CL = ao_heap_assert_node(X, L);

        R = N->right;

        if (R)
        {
            ao_assert(N == R->parent);

            ao_assert(Less(N, R, LessParameter));

            CR = ao_heap_assert_node(X, R);
        }

        else
        {
            CR = 0;
        }
    }

    else
    {
        ao_assert(!N->right);

        CL = 0;

        CR = 0;
    }

    return 1 + CL + CR;
}

void ao_heap_down(ao_heap_t * X, ao_heap_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->less);

    ao_assert(N);


    // Variables.

    bool B;

    ao_heap_node_t * L;

    ao_heap_less_t Less = X->less;

    void * LessParameter = X->less_parameter;

    ao_heap_node_t * R;


    // Ready.

    B = true;

    do
    {
        // Node has children.

        L = N->left;

        if (L)
        {
            // Node has two children.

            R = N->right;

            if (R)
            {
                // Left is less.

                if (Less(L, N, LessParameter))
                {
                    // Right is less.

                    if (Less(R, L, LessParameter))
                    {
                        ao_heap_swap_right(X, N);
                    }


                    // Right is not less.

                    else
                    {
                        ao_heap_swap_left(X, N);
                    }
                }


                // Left is not less.

                else
                {
                    // Right is less.

                    if (Less(R, N, LessParameter))
                    {
                        ao_heap_swap_right(X, N);
                    }


                    // Right is not less.

                    else
                    {
                        B = false;
                    }
                }
            }


            // Node has one child.

            else
            {
                // Left is less.

                if (Less(L, N, LessParameter))
                {
                    ao_heap_swap_left(X, N);
                }


                // Left is not less.

                else
                {
                    B = false;
                }
            }
        }


        // Node has no children.

        else
        {
            ao_assert(!N->right);

            B = false;
        }
    }
    while (B);
}

void ao_heap_insert(ao_heap_t * X, ao_heap_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(N);

    ao_assert(!N->parent);

    ao_assert(!N->left);

    ao_assert(!N->right);


    // Variables.

    ao_uint_t C1;

    ao_uint_t C2;

    ao_uint_t CM;

    ao_heap_node_t * P;

    ao_heap_node_t ** P2N;


    // Ready.

    // Count.

    C1 = X->count;

    C2 = C1 + 1;

    ao_assert(C2);

#if AO_HEAP_COUNT_MAX

    CM = X->count_max;

    CM = ao_max(C2, CM);

    X->count_max = CM;

#endif

    X->count = C2;


    // Insert.

    P2N = &X->root;

    if (C1)
    {
        CM = 1 << ao_flsu(C2);

        do
        {
            CM = CM >> 1;

            if (C2 & CM)
            {
                P = *P2N;

                P2N = &P->right;
            }

            else
            {
                P = *P2N;

                P2N = &P->left;
            }
        }
        while (CM > 1);
    }

    else
    {
        P = NULL;
    }

    *P2N = N;

    N->parent = P;


    // Bubble upwards, until the heap condition is fulfilled.

    ao_heap_up(X, N);
}

ao_heap_node_t * ao_heap_pop(ao_heap_t * X)
{
    ao_assert(X);

    ao_heap_node_t * N = X->root;

    ao_heap_remove(X, N);

    return N;
}

void ao_heap_remove(ao_heap_t * X, ao_heap_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->count);

    ao_assert(X->less);

    ao_assert(X->root);

    ao_assert(N);


    // Variables.

    ao_uint_t C1;

    ao_uint_t C2;

    ao_uint_t CM;

    ao_heap_node_t * E;

    ao_heap_node_t * P;

    ao_heap_node_t ** P2E;


    // Ready.

    // Count.

    C1 = X->count;

    C2 = C1 - 1;

    X->count = C2;


    // Find and remove the end.

    P2E = &X->root;

    if (C2)
    {
        CM = 1 << ao_flsu(C1);

        do
        {
            CM = CM >> 1;

            if (C1 & CM)
            {
                P = *P2E;

                P2E = &P->right;
            }

            else
            {
                P = *P2E;

                P2E = &P->left;
            }
        }
        while (CM > 1);

        E = *P2E;
    }

    else
    {
        E = X->root;

        P = NULL;
    }

    ao_assert(!E->left);

    ao_assert(!E->right);

    *P2E = NULL;

    E->parent = NULL;


    // Replace node by end.

    // Bubble end up or down, until the heap condition is fulfilled.

    if (N != E)
    {
        ao_heap_replace(X, N, E);

        if (X->less(E, N, X->less_parameter))
        {
            ao_heap_up(X, E);
        }

        else
        {
            ao_heap_down(X, E);
        }
    }
}

void ao_heap_replace(ao_heap_t * X, ao_heap_node_t * N1, ao_heap_node_t * N2)
{
    // Assert.

    ao_assert(X);

    ao_assert(N1);

    ao_assert(N2);

    ao_assert(!N2->parent);

    ao_assert(!N2->left);

    ao_assert(!N2->right);


    // Variables.

    ao_heap_node_t * P;

    ao_heap_node_t ** P2N;

    ao_heap_node_t * L;

    ao_heap_node_t * R;


    // Ready.

    P = N1->parent;

    if (P)
    {
        if (N1 == P->left)
        {
            P2N = &P->left;
        }

        else
        {
            P2N = &P->right;
        }

        N1->parent = NULL;
    }

    else
    {
        P2N = &X->root;
    }

    L = N1->left;

    R = N1->right;

    *P2N = N2;

    N2->parent = P;

    N2->left = L;

    N2->right = R;

    if (L)
    {
        L->parent = N2;

        N1->left = NULL;
    }

    if (R)
    {
        R->parent = N2;

        N1->right = NULL;
    }
}

void ao_heap_swap_left(ao_heap_t * X, ao_heap_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(N);

    ao_assert(N->left);


    // Variables.

    ao_heap_node_t * L;

    ao_heap_node_t * LL;

    ao_heap_node_t * LR;

    ao_heap_node_t * P;

    ao_heap_node_t ** P2L;

    ao_heap_node_t * R;


    // Ready.

    P = N->parent;

    if (P)
    {
        if (N == P->left)
        {
            P2L = &P->left;
        }

        else
        {
            P2L = &P->right;
        }
    }

    else
    {
        P2L = &X->root;
    }

    L = N->left;

    R = N->right;

    LL = L->left;

    LR = L->right;

    *P2L = L;

    L->parent = P;

    L->left = N;

    L->right = R;

    N->parent = L;

    if (R)
    {
        R->parent = L;
    }

    N->left = LL;

    N->right = LR;

    if (LL)
    {
        LL->parent = N;
    }

    if (LR)
    {
        LR->parent = N;
    }
}

void ao_heap_swap_parent(ao_heap_t * X, ao_heap_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(N);

    ao_assert(N->parent);


    // Variables.

    ao_heap_node_t * G;

    ao_heap_node_t ** G2N;

    ao_heap_node_t * L;

    ao_heap_node_t ** N2P;

    ao_heap_node_t ** N2S;

    ao_heap_node_t * P;

    ao_heap_node_t * R;

    ao_heap_node_t * S;


    // Ready.

    L = N->left;

    R = N->right;

    P = N->parent;

    if (N == P->left)
    {
        S = P->right;

        N2P = &N->left;

        N2S = &N->right;
    }

    else
    {
        S = P->left;

        N2P = &N->right;

        N2S = &N->left;
    }

    G = P->parent;

    if (G)
    {
        if (P == G->left)
        {
            G2N = &G->left;
        }

        else
        {
            G2N = &G->right;
        }
    }

    else
    {
        G2N = &X->root;
    }

    *G2N = N;

    N->parent = G;

    *N2P = P;

    *N2S = S;

    P->parent = N;

    if (S)
    {
        S->parent = N;
    }

    P->left = L;

    P->right = R;

    if (L)
    {
        L->parent = P;
    }

    if (R)
    {
        R->parent = P;
    }
}

void ao_heap_swap_right(ao_heap_t * X, ao_heap_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(N);

    ao_assert(N->left);

    ao_assert(N->right);


    // Variables.

    ao_heap_node_t * L;

    ao_heap_node_t * P;

    ao_heap_node_t ** P2R;

    ao_heap_node_t * R;

    ao_heap_node_t * RL;

    ao_heap_node_t * RR;


    // Ready.

    P = N->parent;

    if (P)
    {
        if (N == P->left)
        {
            P2R = &P->left;
        }

        else
        {
            P2R = &P->right;
        }
    }

    else
    {
        P2R = &X->root;
    }

    L = N->left;

    R = N->right;

    RL = R->left;

    RR = R->right;

    *P2R = R;

    R->parent = P;

    R->left = L;

    L->parent = R;

    R->right = N;

    N->parent = R;

    N->left = RL;

    N->right = RR;

    if (RL)
    {
        RL->parent = N;
    }

    if (RR)
    {
        RR->parent = N;
    }
}

void ao_heap_up(ao_heap_t * X, ao_heap_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->less);

    ao_assert(N);


    // Variables.

    ao_heap_less_t Less = X->less;

    void * LessParameter = X->less_parameter;

    ao_heap_node_t * P;


    // Ready.

    P = N->parent;

    while (P && Less(N, P, LessParameter))
    {
        ao_heap_swap_parent(X, N);

        P = N->parent;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_HEAP4OBJ

// ----------------------------------------------------------------------------

static  void    ao_heap4obj_down(   ao_heap4obj_t * x, size_t i);

static  void    ao_heap4obj_up(     ao_heap4obj_t * x, size_t i);

// ----------------------------------------------------------------------------

#define ao_heap4obj_left(i)         (2 * (i) + 1)

#define ao_heap4obj_right(i)        (2 * (i) + 2)

// ----------------------------------------------------------------------------

#define ao_heap4obj_parent(i)       (((i) - 1) / 2)

// ----------------------------------------------------------------------------

#define ao_heap4obj_q(x, j)         ((uint8_t *) (x)->store + (x)->size * (j))

// ----------------------------------------------------------------------------

void ao_heap4obj_assert(ao_heap4obj_t * x)
{
    // Variables.

    size_t c = x->count;

    size_t il;

    size_t ip;

    size_t ir;

    size_t jl;

    size_t jp;

    size_t jr;


    // Variables.

    size_t * h1 = x->heap1;

    size_t * h2 = x->heap2;


    // Variables.

    void * ql;

    void * qp;

    void * qr;


    // Variables.

    ao_heap4obj_less_t less = x->less;

    void * less_parameter = x->less_parameter;


    // Ready.

    for (ip = 0; ip < c; ip++)
    {
        il = ao_heap4obj_left(ip);

        ir = ao_heap4obj_right(ip);

        if (ir < c)
        {
            jp = h1[ip];

            jr = h1[ir];

            ao_assert(jp < c);

            ao_assert(jr < c);

            ao_assert(h2[jp] == ip);

            ao_assert(h2[jr] == ir);

            qp = ao_heap4obj_q(x, jp);

            qr = ao_heap4obj_q(x, jr);

            if (less(qr, qp, less_parameter))
            {
                ao_assert(false);
            }

            jl = h1[il];

            ao_assert(jl < c);

            ao_assert(h2[jl] == il);

            ql = ao_heap4obj_q(x, jl);

            if (less(ql, qp, less_parameter))
            {
                ao_assert(false);
            }
        }

        else if (il < c)
        {
            jp = h1[ip];

            jl = h1[il];

            ao_assert(jp < c);

            ao_assert(jl < c);

            ao_assert(h2[jp] == ip);

            ao_assert(h2[jl] == il);

            qp = ao_heap4obj_q(x, jp);

            ql = ao_heap4obj_q(x, jl);

            if (less(ql, qp, less_parameter))
            {
                ao_assert(false);
            }
        }
    }
}

void ao_heap4obj_down(ao_heap4obj_t * x, size_t i1)
{
    // Variables.

    bool b1;

    bool b2;


    // Variables.

    size_t c = x->count;

    size_t il;

    size_t ir;

    size_t j1;

    size_t jl;

    size_t jr;


    // Variables.

    void * q1;

    void * ql;

    void * qr;


    // Variables.

    ao_heap4obj_less_t less = x->less;

    void * less_parameter = x->less_parameter;


    // Ready.

    b1 = true;

    b2 = false;

    j1 = x->heap1[i1];

    q1 = ao_heap4obj_q(x, j1);

    do
    {
        il = ao_heap4obj_left(i1);

        ir = ao_heap4obj_right(i1);

        // Both left and right child.

        if (ir < c)
        {
            jl = x->heap1[il];

            jr = x->heap1[ir];

            ql = ao_heap4obj_q(x, jl);

            qr = ao_heap4obj_q(x, jr);

            // qr is less.

            if (less(qr, q1, less_parameter))
            {
                // qr is less than q1.

                // ql is less than qr.

                if (less(ql, qr, less_parameter))
                {
                    x->heap1[i1] = jl;

                    x->heap2[jl] = i1;

                    i1 = il;

                    b2 = true;
                }

                // qr is less than x1.

                // ql is not less than xr.

                else
                {
                    x->heap1[i1] = jr;

                    x->heap2[jr] = i1;

                    i1 = ir;

                    b2 = true;
                }
            }

            // qr is not less.

            // ql is less.

            else if (less(ql, q1, less_parameter))
            {
                x->heap1[i1] = jl;

                x->heap2[jl] = i1;

                i1 = il;

                b2 = true;
            }

            // qr is not less.

            // ql is not less.

            else
            {
                b1 = false;
            }
        }

        // Left child only.

        else if (il < c)
        {
            jl = x->heap1[il];

            ql = ao_heap4obj_q(x, jl);

            // ql is less.

            if (less(ql, q1, less_parameter))
            {
                x->heap1[i1] = jl;

                x->heap2[jl] = i1;

                i1 = il;

                b2 = true;
            }

            // ql is not less.

            else
            {
                b1 = false;
            }
        }

        // No children.

        else
        {
            b1 = false;
        }
    }
    while (b1);

    if (b2)
    {
        x->heap1[i1] = j1;

        x->heap2[j1] = i1;
    }
}

bool ao_heap4obj_insert(ao_heap4obj_t * x, void const * p)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->capacity >= x->count);

    ao_assert(x->heap1);

    ao_assert(x->heap2);

    ao_assert(x->less);

    ao_assert(x->size);

    ao_assert(x->store);

    ao_assert(p);


    // Variables.

    size_t c1 = x->count;

    size_t c2;

#if AO_HEAP4OBJ_COUNT_MAX

    size_t cm;

#endif


    // Variables.

    void * q;


    // Ready.

    // Heap is full.

    if (c1 == x->capacity) return false;


    // Heap is not full.

    c2 = c1 + 1;

#if AO_HEAP4OBJ_COUNT_MAX

    cm = x->count_max;

    cm = ao_max(cm, c2);

    x->count_max = cm;

#endif

    x->count = c2;

    x->heap1[c1] = c1;

    x->heap2[c1] = c1;

    q = ao_heap4obj_q(x, c1);

    ao_memcpy(q, p, x->size);

    ao_heap4obj_up(x, c1);

    return true;
}

bool ao_heap4obj_peek(ao_heap4obj_t const * x, void * p)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->capacity >= x->count);

    ao_assert(x->heap1);

    ao_assert(x->heap2);

    ao_assert(x->less);

    ao_assert(x->size);

    ao_assert(x->store);

    ao_assert(p);


    // Variables.

    size_t j;

    void * q;


    // Ready.

    // Heap is empty.

    if (x->count == 0) return false;


    // Heap is not empty.

    j = x->heap1[0];

    q = ao_heap4obj_q(x, j);

    ao_memcpy(p, q, x->size);

    return true;
}

bool ao_heap4obj_pop(ao_heap4obj_t * x, void * p)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->capacity >= x->count);

    ao_assert(x->heap1);

    ao_assert(x->heap2);

    ao_assert(x->less);

    ao_assert(x->size);

    ao_assert(x->store);

    ao_assert(p);


    // Variables.

    size_t c = x->count;

    size_t i;

    size_t j;

    void * q1;

    void * q2;


    // Ready.

    // Heap is empty.

    if (c == 0) return false;


    // Heap is not empty.

    j = x->heap1[0];

    q1 = ao_heap4obj_q(x, j);

    ao_memcpy(p, q1, x->size);

    x->count = --c;

    if (c > 0)
    {
        if (j != c)
        {
            q2 = ao_heap4obj_q(x, c);

            ao_memcpy(q1, q2, x->size);

            i = x->heap2[c];

            x->heap2[j] = i;

            x->heap1[i] = j;
        }

        j = x->heap1[c];

        x->heap1[0] = j;

        x->heap2[j] = 0;

        ao_heap4obj_down(x, 0);
    }

    return true;
}

void ao_heap4obj_up(ao_heap4obj_t * x, size_t i1)
{
    // Variables.

    bool b1 = i1 > 0 ? true : false;

    bool b2;


    // Variables.

    size_t i2;

    size_t j1;

    size_t j2;


    // Variables.

    void * q1;

    void * q2;


    // Variables.

    ao_heap4obj_less_t less;

    void * less_parameter;


    // Ready.

    if (b1)
    {
        less = x->less;

        less_parameter = x->less_parameter;

        b2 = false;

        j1 = x->heap1[i1];

        q1 = ao_heap4obj_q(x, j1);

        do
        {
            i2 = ao_heap4obj_parent(i1);

            j2 = x->heap1[i2];

            q2 = ao_heap4obj_q(x, j2);

            if (less(q1, q2, less_parameter))
            {
                x->heap1[i1] = j2;

                x->heap2[j2] = i1;

                i1 = i2;

                b1 = i1 > 0 ? true : false;

                b2 = true;
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);

        if (b2)
        {
            x->heap1[i1] = j1;

            x->heap2[j1] = i1;
        }
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_HEAP4PTR

// ----------------------------------------------------------------------------

static  void    ao_heap4ptr_down(   ao_heap4ptr_t * x, size_t i);

static  void    ao_heap4ptr_up(     ao_heap4ptr_t * x, size_t i);

// ----------------------------------------------------------------------------

#define ao_heap4ptr_left(i)         (2 * (i) + 1)

#define ao_heap4ptr_right(i)        (2 * (i) + 2)

// ----------------------------------------------------------------------------

#define ao_heap4ptr_parent(i)       (((i) - 1) / 2)

// ----------------------------------------------------------------------------

void ao_heap4ptr_assert(ao_heap4ptr_t * x)
{
    size_t c = x->count;

    size_t il;

    size_t ip;

    size_t ir;

    size_t jl;

    size_t jp;

    size_t jr;


    // Variables.

    size_t * h1 = x->heap1;

    size_t * h2 = x->heap2;


    // Variables.

    void * ql;

    void * qp;

    void * qr;


    // Variables.

    ao_heap4ptr_less_t less = x->less;

    void * less_parameter = x->less_parameter;


    // Ready.

    for (ip = 0; ip < c; ip++)
    {
        il = ao_heap4ptr_left(ip);

        ir = ao_heap4ptr_right(ip);

        if (ir < c)
        {
            jp = h1[ip];

            jr = h1[ir];

            ao_assert(jp < c);

            ao_assert(jr < c);

            ao_assert(h2[jp] == ip);

            ao_assert(h2[jr] == ir);

            qp = x->store[jp];

            qr = x->store[jr];

            if (less(qr, qp, less_parameter))
            {
                ao_assert(false);
            }

            jl = h1[il];

            ao_assert(jl < c);

            ao_assert(h2[jl] == il);

            ql = x->store[jl];

            if (less(ql, qp, less_parameter))
            {
                ao_assert(false);
            }
        }

        else if (il < c)
        {
            jp = h1[ip];

            jl = h1[il];

            ao_assert(jp < c);

            ao_assert(jl < c);

            ao_assert(h2[jp] == ip);

            ao_assert(h2[jl] == il);

            qp = x->store[jp];

            ql = x->store[jl];

            if (less(ql, qp, less_parameter))
            {
                ao_assert(false);
            }
        }
    }
}

void ao_heap4ptr_down(ao_heap4ptr_t * x, size_t i1)
{
    // Variables.

    bool b1;

    bool b2;


    // Variables.

    size_t c = x->count;

    size_t il;

    size_t ir;

    size_t j1;

    size_t jl;

    size_t jr;


    // Variables.

    void * q1;

    void * ql;

    void * qr;


    // Variables.

    ao_heap4ptr_less_t less = x->less;

    void * less_parameter = x->less_parameter;


    // Ready.

    b1 = true;

    b2 = false;

    j1 = x->heap1[i1];

    q1 = x->store[j1];

    do
    {
        il = ao_heap4ptr_left(i1);

        ir = ao_heap4ptr_right(i1);

        // Both left and right child.

        if (ir < c)
        {
            jl = x->heap1[il];

            jr = x->heap1[ir];

            ql = x->store[jl];

            qr = x->store[jr];

            // qr is less.

            if (less(qr, q1, less_parameter))
            {
                // qr is less than q1.

                // ql is less than qr.

                if (less(ql, qr, less_parameter))
                {
                    x->heap1[i1] = jl;

                    x->heap2[jl] = i1;

                    i1 = il;

                    b2 = true;
                }

                // qr is less than x1.

                // ql is not less than xr.

                else
                {
                    x->heap1[i1] = jr;

                    x->heap2[jr] = i1;

                    i1 = ir;

                    b2 = true;
                }
            }

            // qr is not less.

            // ql is less.

            else if (less(ql, q1, less_parameter))
            {
                x->heap1[i1] = jl;

                x->heap2[jl] = i1;

                i1 = il;

                b2 = true;
            }

            // qr is not less.

            // ql is not less.

            else
            {
                b1 = false;
            }
        }

        // Left child only.

        else if (il < c)
        {
            jl = x->heap1[il];

            ql = x->store[jl];

            // ql is less.

            if (less(ql, q1, less_parameter))
            {
                x->heap1[i1] = jl;

                x->heap2[jl] = i1;

                i1 = il;

                b2 = true;
            }

            // ql is not less.

            else
            {
                b1 = false;
            }
        }

        // No children.

        else
        {
            b1 = false;
        }
    }
    while (b1);

    if (b2)
    {
        x->heap1[i1] = j1;

        x->heap2[j1] = i1;
    }
}

bool ao_heap4ptr_insert(ao_heap4ptr_t * x, void * p)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->capacity >= x->count);

    ao_assert(x->heap1);

    ao_assert(x->heap2);

    ao_assert(x->less);

    ao_assert(x->store);


    // Variables.

    size_t c1 = x->count;

    size_t c2;

#if AO_HEAP4PTR_COUNT_MAX

    size_t cm;

#endif


    // Ready.

    // Heap is full.

    if (c1 == x->capacity) return false;


    // Heap is not full.

    c2 = c1 + 1;

#if AO_HEAP4PTR_COUNT_MAX

    cm = x->count_max;

    cm = ao_max(cm, c2);

    x->count_max = cm;

#endif

    x->count = c2;

    x->heap1[c1] = c1;

    x->heap2[c1] = c1;

    x->store[c1] = p;

    ao_heap4ptr_up(x, c1);

    return true;
}

bool ao_heap4ptr_peek(ao_heap4ptr_t const * x, void ** p)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->capacity >= x->count);

    ao_assert(x->heap1);

    ao_assert(x->heap2);

    ao_assert(x->less);

    ao_assert(x->store);

    ao_assert(p);


    // Variables.

    size_t j;


    // Ready.

    // Heap is empty.

    if (x->count == 0) return false;


    // Heap is not empty.

    j = x->heap1[0];

    *p = x->store[j];

    return true;
}

bool ao_heap4ptr_pop(ao_heap4ptr_t * x, void ** p)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->capacity >= x->count);

    ao_assert(x->heap1);

    ao_assert(x->heap2);

    ao_assert(x->less);

    ao_assert(x->store);

    ao_assert(p);


    // Variables.

    size_t c = x->count;

    size_t i;

    size_t j;

    void * q1;

    void * q2;


    // Ready.

    // Heap is empty.

    if (c == 0) return false;


    // Heap is not empty.

    j = x->heap1[0];

    *p = x->store[j];

    x->count = --c;

    if (c > 0)
    {
        if (j != c)
        {
            x->store[j] = x->store[c];

            i = x->heap2[c];

            x->heap2[j] = i;

            x->heap1[i] = j;
        }

        j = x->heap1[c];

        x->heap1[0] = j;

        x->heap2[j] = 0;

        ao_heap4ptr_down(x, 0);
    }

    return true;
}

void ao_heap4ptr_up(ao_heap4ptr_t * x, size_t i1)
{
    // Variables.

    bool b1 = i1 > 0 ? true : false;

    bool b2;


    // Variables.

    size_t i2;

    size_t j1;

    size_t j2;


    // Variables.

    void * q1;

    void * q2;


    // Variables.

    ao_heap4ptr_less_t less;

    void * less_parameter;


    // Ready.

    if (b1)
    {
        less = x->less;

        less_parameter = x->less_parameter;

        b2 = false;

        j1 = x->heap1[i1];

        q1 = x->store[j1];

        do
        {
            i2 = ao_heap4ptr_parent(i1);

            j2 = x->heap1[i2];

            q2 = x->store[j2];

            if (less(q1, q2, less_parameter))
            {
                x->heap1[i1] = j2;

                x->heap2[j2] = i1;

                i1 = i2;

                b1 = i1 > 0 ? true : false;

                b2 = true;
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);

        if (b2)
        {
            x->heap1[i1] = j1;

            x->heap2[j1] = i1;
        }
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_LFSR8

// ----------------------------------------------------------------------------

void ao_lfsr8(ao_lfsr8_t * x)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->polynomial);

    ao_assert(x->seed);


    // Variables.

    uint8_t s;

    uint8_t t;


    // Ready.

    s = x->seed;

    t = s & 1;

    s >>= 1;

    if (t)
    {
        s ^= x->polynomial;
    }

    x->seed = s;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_LFSR16

// ----------------------------------------------------------------------------

void ao_lfsr16(ao_lfsr16_t * x)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->polynomial);

    ao_assert(x->seed);


    // Variables.

    uint16_t s;

    uint16_t t;


    // Ready.

    s = x->seed;

    t = s & 1;

    s >>= 1;

    if (t)
    {
        s ^= x->polynomial;
    }

    x->seed = s;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_LFSR32

// ----------------------------------------------------------------------------

void ao_lfsr32(ao_lfsr32_t * x)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->polynomial);

    ao_assert(x->seed);


    // Variables.

    uint32_t s;

    uint32_t t;


    // Ready.

    s = x->seed;

    t = s & 1;

    s >>= 1;

    if (t)
    {
        s ^= x->polynomial;
    }

    x->seed = s;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_LFSR64

// ----------------------------------------------------------------------------

void ao_lfsr64(ao_lfsr64_t * x)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->polynomial);

    ao_assert(x->seed);


    // Variables.

    uint64_t s;

    uint64_t t;


    // Ready.

    s = x->seed;

    t = s & 1;

    s >>= 1;

    if (t)
    {
        s ^= x->polynomial;
    }

    x->seed = s;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_LIST

// ----------------------------------------------------------------------------

void ao_list_insert_after(ao_list_t * L, ao_list_node_t * N1, ao_list_node_t * N2)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->front);

    ao_assert(L->back);

    ao_assert(N1);

    ao_assert(N2);

    ao_assert(!N2->next);

    ao_assert(!N2->prev);


    // Variables.

    ao_list_node_t * N3;


    // Ready.

    N3 = N1->next;

    N1->next = N2;

    N2->prev = N1;

    if (N3)
    {
        N2->next = N3;

        N3->prev = N2;
    }

    else
    {
        L->back = N2;
    }
}

void ao_list_insert_before(ao_list_t * L, ao_list_node_t * N2, ao_list_node_t * N3)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->front);

    ao_assert(L->back);

    ao_assert(N2);

    ao_assert(!N2->next);

    ao_assert(!N2->prev);

    ao_assert(N3);


    // Variables.

    ao_list_node_t * N1;


    // Ready.

    N1 = N3->prev;

    N2->next = N3;

    N3->prev = N2;

    if (N1)
    {
        N1->next = N2;

        N2->prev = N1;
    }

    else
    {
        L->front = N2;
    }
}

// ----------------------------------------------------------------------------

ao_list_node_t * ao_list_pop_back(ao_list_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->front);

    ao_assert(L->back);


    // Variables.

    ao_list_node_t * N1;

    ao_list_node_t * N2;


    // Ready.

    N2 = L->back;

    N1 = N2->prev;

    if (N1)
    {
        N1->next = NULL;

        N2->prev = NULL;
    }

    else
    {
        L->front = NULL;
    }

    L->back = N1;

    return N2;
}

ao_list_node_t * ao_list_pop_front(ao_list_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->front);

    ao_assert(L->back);


    // Variables.

    ao_list_node_t * N1;

    ao_list_node_t * N2;


    // Ready.

    N1 = L->front;

    N2 = N1->next;

    if (N2)
    {
        N1->next = NULL;

        N2->prev = NULL;
    }

    else
    {
        L->back = NULL;
    }

    L->front = N2;

    return N1;
}

// ----------------------------------------------------------------------------

void ao_list_push_back(ao_list_t * L, ao_list_node_t * N2)
{
    // Assert.

    ao_assert(L);

    ao_assert(N2);

    ao_assert(!N2->next);

    ao_assert(!N2->prev);


    // Variables.

    ao_list_node_t * N1;


    // Ready.

    N1 = L->back;

    if (N1)
    {
        N1->next = N2;

        N2->prev = N1;
    }

    else
    {
        L->front = N2;
    }

    L->back = N2;
}

void ao_list_push_front(ao_list_t * L, ao_list_node_t * N1)
{
    // Assert.

    ao_assert(L);

    ao_assert(N1);

    ao_assert(!N1->next);

    ao_assert(!N1->prev);


    // Variables.

    ao_list_node_t * N2;


    // Ready.

    N2 = L->front;

    if (N2)
    {
        N1->next = N2;

        N2->prev = N1;
    }

    else
    {
        L->back = N1;
    }

    L->front = N1;
}

// ----------------------------------------------------------------------------

void ao_list_remove(ao_list_t * L, ao_list_node_t * N2)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->front);

    ao_assert(L->back);

    ao_assert(N2);


    // Variables.

    ao_list_node_t * N1;

    ao_list_node_t * N3;


    // Ready.

    N1 = N2->prev;

    N3 = N2->next;

    if (N1)
    {
        N1->next = N3;

        N2->prev = NULL;
    }

    else
    {
        L->front = N3;
    }

    if (N3)
    {
        N2->next = NULL;

        N3->prev = N1;
    }

    else
    {
        L->back = N1;
    }
}

void ao_list_remove_all(ao_list_t * L)
{
    // Assert.

    ao_assert(L);


    // Variables.

    ao_list_node_t * N1;

    ao_list_node_t * N2;


    // Ready.

    N1 = L->front;

    while (N1)
    {
        N2 = N1->next;

        N1->next = NULL;

        N1->prev = NULL;

        N1 = N2;
    }

    L->front = NULL;

    L->back  = NULL;
}

void ao_list_remove_back(ao_list_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->front);

    ao_assert(L->back);


    // Variables.

    ao_list_node_t * N1;

    ao_list_node_t * N2;


    // Ready.

    N2 = L->back;

    N1 = N2->prev;

    if (N1)
    {
        N1->next = NULL;

        N2->prev = NULL;
    }

    else
    {
        L->front = NULL;
    }

    L->back = N1;
}

void ao_list_remove_front(ao_list_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->front);

    ao_assert(L->back);


    // Variables.

    ao_list_node_t * N1;

    ao_list_node_t * N2;


    // Ready.

    N1 = L->front;

    N2 = N1->next;

    if (N2)
    {
        N1->next = NULL;

        N2->prev = NULL;
    }

    else
    {
        L->back = NULL;
    }

    L->front = N2;
}

// ----------------------------------------------------------------------------

void ao_list_reverse(ao_list_t * L)
{
    // Assert.

    ao_assert(L);


    // Variables.

    ao_list_node_t * N1;

    ao_list_node_t * N2;


    // Ready.

    N1 = L->front;

    L->front = L->back;

    L->back = N1;

    while (N1)
    {
        N2 = N1->next;

        N1->next = N1->prev;

        N1->prev = N2;

        N1 = N2;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MATHF

// ----------------------------------------------------------------------------

#ifndef ao_acoshd

double ao_acoshd(double x)
{
    double t1 = x - 1.0;
    double t2 = x + 1.0;

    t1 = ao_sqrtd(t1);
    t2 = ao_sqrtd(t2);

    double t3 = x + t1 * t2;

    return ao_logd(t3);
}

#endif

#ifndef ao_acoshf

float ao_acoshf(float x)
{
    float t1 = x - 1.0f;
    float t2 = x + 1.0f;

    t1 = ao_sqrtf(t1);
    t2 = ao_sqrtf(t2);

    float t3 = x + t1 * t2;

    return ao_logf(t3);
}

#endif

#ifndef ao_acoshl

long double ao_acoshl(long double x)
{
    long double t1 = x - 1.0l;
    long double t2 = x + 1.0l;

    t1 = ao_sqrtl(t1);
    t2 = ao_sqrtl(t2);

    long double t3 = x + t1 * t2;

    return ao_logl(t3);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_acotd

double ao_acotd(double x)
{
    return ao_atan2d(1.0, x);
}

#endif

#ifndef ao_acotf

float ao_acotf(float x)
{
    return ao_atan2f(1.0f, x);
}

#endif

#ifndef ao_acotl

long double ao_acotl(long double x)
{
    return ao_atan2l(1.0l, x);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_acothd

double ao_acothd(double x)
{
    double t1 = x + 1.0;
    double t2 = x - 1.0;

    t1 = ao_logd(t1);
    t2 = ao_logd(t2);

    return 0.5 * (t1 - t2);
}

#endif

#ifndef ao_acothf

float ao_acothf(float x)
{
    float t1 = x + 1.0f;
    float t2 = x - 1.0f;

    t1 = ao_logf(t1);
    t2 = ao_logf(t2);

    return 0.5f * (t1 - t2);
}

#endif

#ifndef ao_acothl

long double ao_acothl(long double x)
{
    long double t1 = x + 1.0l;
    long double t2 = x - 1.0l;

    t1 = ao_logl(t1);
    t2 = ao_logl(t2);

    return 0.5l * (t1 - t2);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_acscd

double ao_acscd(double x)
{
    double t1 = 1.0 / x;

    double t2 = 1.0 - t1 * t1;

    t2 = ao_sqrtd(t2);

    return ao_atan2d(t1, t2);
}

#endif

#ifndef ao_acscf

float ao_acscf(float x)
{
    float t1 = 1.0f / x;

    float t2 = 1.0f - t1 * t1;

    t2 = ao_sqrtf(t2);

    return ao_atan2f(t1, t2);
}

#endif

#ifndef ao_acscl

long double ao_acscl(long double x)
{
    long double t1 = 1.0l / x;

    long double t2 = 1.0l - t1 * t1;

    t2 = ao_sqrtl(t2);

    return ao_atan2l(t1, t2);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_acschd

double ao_acschd(double x)
{
    double t1 = 1.0 / x;

    double t2 = 1.0 + t1 * t1;

    t2 = ao_sqrtd(t2);

    t2 = t2 + t1;

    return ao_logd(t2);
}

#endif

#ifndef ao_acschf

float ao_acschf(float x)
{
    float t1 = 1.0f / x;

    float t2 = 1.0f + t1 * t1;

    t2 = ao_sqrtf(t2);

    t2 = t2 + t1;

    return ao_logf(t2);
}

#endif

#ifndef ao_acschl

long double ao_acschl(long double x)
{
    long double t1 = 1.0l / x;

    long double t2 = 1.0l + t1 * t1;

    t2 = ao_sqrtl(t2);

    t2 = t2 + t1;

    return ao_logl(t2);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_asecd

double ao_asecd(double x)
{
    double t1 = 1.0 / x;

    double t2 = 1.0 - t1 * t1;

    t2 = ao_sqrtd(t2);

    return (double) AO_PI_2 - ao_atan2d(t1, t2);
}

#endif

#ifndef ao_asecf

float ao_asecf(float x)
{
    float t1 = 1.0f / x;

    float t2 = 1.0f - t1 * t1;

    t2 = ao_sqrtf(t2);

    return (float) AO_PI_2 - ao_atan2f(t1, t2);
}

#endif

#ifndef ao_asecl

long double ao_asecl(long double x)
{
    long double t1 = 1.0l / x;

    long double t2 = 1.0l - t1 * t1;

    t2 = ao_sqrtl(t2);

    return (long double) AO_PI_2 - ao_atan2l(t1, t2);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_asechd

double ao_asechd(double x)
{
    double t1 = 1.0 / x;

    double t2 = t1 - 1.0;
    double t3 = t1 + 1.0;

    t2 = ao_sqrtd(t2);
    t3 = ao_sqrtd(t3);

    t1 = t1 + t2 * t3;

    return ao_logd(t1);
}

#endif

#ifndef ao_asechf

float ao_asechf(float x)
{
    float t1 = 1.0f / x;

    float t2 = t1 - 1.0f;
    float t3 = t1 + 1.0f;

    t2 = ao_sqrtf(t2);
    t3 = ao_sqrtf(t3);

    t1 = t1 + t2 * t3;

    return ao_logf(t1);
}

#endif

#ifndef ao_asechl

long double ao_asechl(long double x)
{
    long double t1 = 1.0l / x;

    long double t2 = t1 - 1.0l;
    long double t3 = t1 + 1.0l;

    t2 = ao_sqrtl(t2);
    t3 = ao_sqrtl(t3);

    t1 = t1 + t2 * t3;

    return ao_logl(t1);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_asinhd

double ao_asinhd(double x)
{
    double t = 1.0 + x * x;

    t = ao_sqrtd(t);

    t = t + x;

    return ao_logd(t);
}

#endif

#ifndef ao_asinhf

float ao_asinhf(float x)
{
    float t = 1.0f + x * x;

    t = ao_sqrtf(t);

    t = t + x;

    return ao_logf(t);
}

#endif

#ifndef ao_asinhl

long double ao_asinhl(long double x)
{
    long double t = 1.0l + x * x;

    t = ao_sqrtl(t);

    t = t + x;

    return ao_logl(t);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_atanhd

double ao_atanhd(double x)
{
    double t1 = 1.0 + x;
    double t2 = 1.0 - x;

    t1 = ao_logd(t1);
    t2 = ao_logd(t2);

    return 0.5 * (t1 - t2);
}

#endif

#ifndef ao_atanhf

float ao_atanhf(float x)
{
    float t1 = 1.0f + x;
    float t2 = 1.0f - x;

    t1 = ao_logf(t1);
    t2 = ao_logf(t2);

    return 0.5f * (t1 - t2);
}

#endif

#ifndef ao_atanhl

long double ao_atanhl(long double x)
{
    long double t1 = 1.0l + x;
    long double t2 = 1.0l - x;

    t1 = ao_logl(t1);
    t2 = ao_logl(t2);

    return 0.5l * (t1 - t2);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_cbrtd

double ao_cbrtd(double x)
{
    return ao_powd(x, 1.0 / 3.0);
}

#endif

#ifndef ao_cbrtf

float ao_cbrtf(float x)
{
    return ao_powf(x, 1.0f / 3.0f);
}

#endif

#ifndef ao_cbrtl

long double ao_cbrtl(long double x)
{
    return ao_powl(x, 1.0l / 3.0l);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_coshd

double ao_coshd(double x)
{
    double t1 = ao_expd( x);
    double t2 = ao_expd(-x);

    return 0.5 * (t1 + t2);
}

#endif

#ifndef ao_coshf

float ao_coshf(float x)
{
    float t1 = ao_expf( x);
    float t2 = ao_expf(-x);

    return 0.5f * (t1 + t2);
}

#endif

#ifndef ao_coshl

long double ao_coshl(long double x)
{
    long double t1 = ao_expl( x);
    long double t2 = ao_expl(-x);

    return 0.5l * (t1 + t2);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_cotd

double ao_cotd(double x)
{
    return 1.0 / ao_tand(x);
}

#endif

#ifndef ao_cotf

float ao_cotf(float x)
{
    return 1.0f / ao_tanf(x);
}

#endif

#ifndef ao_cotl

long double ao_cotl(long double x)
{
    return 1.0l / ao_tanl(x);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_cothd

double ao_cothd(double x)
{
    return 1.0 / ao_tanhd(x);
}

#endif

#ifndef ao_cothf

float ao_cothf(float x)
{
    return 1.0f / ao_tanhf(x);
}

#endif

#ifndef ao_cothl

long double ao_cothl(long double x)
{
    return 1.0l / ao_tanhl(x);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_cscd

double ao_cscd(double x)
{
    return 1.0 / ao_sind(x);
}

#endif

#ifndef ao_cscf

float ao_cscf(float x)
{
    return 1.0f / ao_sinf(x);
}

#endif

#ifndef ao_cscl

long double ao_cscl(long double x)
{
    return 1.0l / ao_sinl(x);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_cschd

double ao_cschd(double x)
{
    return 1.0 / ao_sinhd(x);
}

#endif

#ifndef ao_cschf

float ao_cschf(float x)
{
    return 1.0f / ao_sinhf(x);
}

#endif

#ifndef ao_cschl

long double ao_cschl(long double x)
{
    return 1.0l / ao_sinhl(x);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_deg2radd

double ao_deg2radd(double x)
{
    return x * (double) AO_RADIANS_PER_DEGREE;
}

#endif

#ifndef ao_deg2radf

float ao_deg2radf(float x)
{
    return x * (float) AO_RADIANS_PER_DEGREE;
}

#endif

#ifndef ao_deg2radl

long double ao_deg2radl(long double x)
{
    return x * (long double) AO_RADIANS_PER_DEGREE;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_exp2d

double ao_exp2d(double x)
{
    return ao_powd(2.0, x);
}

#endif

#ifndef ao_exp2f

float ao_exp2f(float x)
{
    return ao_powf(2.0f, x);
}

#endif

#ifndef ao_exp2l

long double ao_exp2l(long double x)
{
    return ao_powl(2.0l, x);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_frexpd

double ao_frexpd(double x, int * e)
{
    ao_assert(e);

    double t;

    if (x > 0)
    {
        t = x;
    }

    else if (x < 0)
    {
        t = -x;
    }

    else
    {
        *e = 0;

        return 0.0;
    }

    t = ao_log2d(t);

    t = ao_floord(t);

    *e = (int) t;

    t = ao_powd(2.0, t);

    return x * t;
}

#endif

#ifndef ao_frexpf

float ao_frexpf(float x, int * e)
{
    ao_assert(e);

    float t;

    if (x > 0)
    {
        t = x;
    }

    else if (x < 0)
    {
        t = -x;
    }

    else
    {
        *e = 0;

        return 0.0f;
    }

    t = ao_log2f(t);

    t = ao_floorf(t);

    *e = (int) t;

    t = ao_powf(2.0f, t);

    return x * t;
}

#endif

#ifndef ao_frexpl

long double ao_frexpl(long double x, int * e)
{
    ao_assert(e);

    long double t;

    if (x > 0)
    {
        t = x;
    }

    else if (x < 0)
    {
        t = -x;
    }

    else
    {
        *e = 0;

        return 0.0l;
    }

    t = ao_log2l(t);

    t = ao_floorl(t);

    *e = (int) t;

    t = ao_powl(2.0l, t);

    return x * t;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_frexp10d

double ao_frexp10d(double x, int * e)
{
    ao_assert(e);

    double t;

    if (x > 0)
    {
        t = x;
    }

    else if (x < 0)
    {
        t = -x;
    }

    else
    {
        *e = 0;

        return 0.0;
    }

    t = ao_log10d(t);

    t = ao_floord(t);

    *e = (int) t;

    t = ao_powd(10.0, t);

    return x / t;
}

#endif

#ifndef ao_frexp10f

float ao_frexp10f(float x, int * e)
{
    ao_assert(e);

    float t;

    if (x > 0)
    {
        t = x;
    }

    else if (x < 0)
    {
        t = -x;
    }

    else
    {
        *e = 0;

        return 0.0f;
    }

    t = ao_log10f(t);

    t = ao_floorf(t);

    *e = (int) t;

    t = ao_powf(10.0f, t);

    return x / t;
}

#endif

#ifndef ao_frexp10l

long double ao_frexp10l(long double x, int * e)
{
    ao_assert(e);

    long double t;

    if (x > 0)
    {
        t = x;
    }

    else if (x < 0)
    {
        t = -x;
    }

    else
    {
        *e = 0;

        return 0.0l;
    }

    t = ao_log10l(t);

    t = ao_floorl(t);

    *e = (int) t;

    t = ao_powl(10.0l, t);

    return x / t;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_hypotd

double ao_hypotd(double x, double y)
{
    double t1 = x * x;
    double t2 = y * y;

    return ao_sqrtd(t1 + t2);
}

#endif

#ifndef ao_hypotf

float ao_hypotf(float x, float y)
{
    float t1 = x * x;
    float t2 = y * y;

    return ao_sqrtf(t1 + t2);
}

#endif

#ifndef ao_hypotl

long double ao_hypotl(long double x, long double y)
{
    long double t1 = x * x;
    long double t2 = y * y;

    return ao_sqrtl(t1 + t2);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_infd

double ao_infd()
{
    return 1.0 / 0.0;
}

#endif

#ifndef ao_inff

float  ao_inff()
{
    return 1.0f / 0.0f;
}

#endif

#ifndef ao_infl

long double ao_infl()
{
    return 1.0l / 0.0l;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_isnand

bool ao_isnand(double x)
{
    return x != x ? true : false;
}

#endif

#ifndef ao_isnanf

bool ao_isnanf(float x)
{
    return x != x ? true : false;
}

#endif

#ifndef ao_isnanl

bool ao_isnanl(long double x)
{
    return x != x ? true : false;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ldexpd

double ao_ldexpd(double x, int e)
{
    double t = (double) e;

    t = ao_powd(2.0, t);

    return x * t;
}

#endif

#ifndef ao_ldexpf

float ao_ldexpf(float x, int e)
{
    float t = (float) e;

    t = ao_powf(2.0f, t);

    return x * t;
}

#endif

#ifndef ao_ldexpl

long double ao_ldexpl(long double x, int e)
{
    long double t = (long double) e;

    t = ao_powl(2.0l, t);

    return x * t;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ldexp10d

double ao_ldexp10d(double x, int e)
{
    double t = (double) e;

    t = ao_powd(10.0, t);

    return x * t;
}

#endif

#ifndef ao_ldexp10f

float ao_ldexp10f(float x, int e)
{
    float t = (float) e;

    t = ao_powf(10.0f, t);

    return x * t;
}

#endif

#ifndef ao_ldexp10l

long double ao_ldexp10l(long double x, int e)
{
    long double t = (long double) e;

    t = ao_powl(10.0l, t);

    return x * t;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_log10d

double ao_log10d(double x)
{
    return ao_logd(x) / (double) AO_LN10;
}

#endif

#ifndef ao_log10f

float ao_log10f(float x)
{
    return ao_logf(x) / (float) AO_LN10;
}

#endif

#ifndef ao_log10l

long double ao_log10l(long double x)
{
    return ao_logl(x) / (long double) AO_LN10;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_log2d

double ao_log2d(double x)
{
    return ao_logd(x) / (double) AO_LN2;
}

#endif

#ifndef ao_log2f

float ao_log2f(float x)
{
    return ao_logf(x) / (float) AO_LN2;
}

#endif

#ifndef ao_log2l

long double ao_log2l(long double x)
{
    return ao_logl(x) / (long double) AO_LN2;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_nand

double ao_nand()
{
    return 0.0 / 0.0;
}

#endif

#ifndef ao_nanf

float ao_nanf()
{
    return 0.0f / 0.0f;
}

#endif

#ifndef ao_nanl

long double ao_nanl()
{
    return 0.0l / 0.0l;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rad2degd

double ao_rad2degd(double x)
{
    return x * (double) AO_DEGREES_PER_RADIAN;
}

#endif

#ifndef ao_rad2degf

float ao_rad2degf(float x)
{
    return x * (float) AO_DEGREES_PER_RADIAN;
}

#endif

#ifndef ao_rad2degl

long double ao_rad2degl(long double x)
{
    return x * (long double) AO_DEGREES_PER_RADIAN;
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_roundd_away_from_zero

double ao_roundd_away_from_zero(double x)
{
    if (x > 0)
    {
        return ao_ceild(x);
    }
    else
    {
        return ao_floord(x);
    }
}

#endif

#ifndef ao_roundf_away_from_zero

float ao_roundf_away_from_zero(float x)
{
    if (x > 0)
    {
        return ao_ceilf(x);
    }
    else
    {
        return ao_floorf(x);
    }
}

#endif

#ifndef ao_roundl_away_from_zero

long double ao_roundl_away_from_zero(long double x)
{
    if (x > 0)
    {
        return ao_ceill(x);
    }
    else
    {
        return ao_floorl(x);
    }
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_roundd_half_down

double ao_roundd_half_down(double x)
{
    return ao_ceild(x - 0.5);
}

#endif

#ifndef ao_roundf_half_down

float ao_roundf_half_down(float x)
{
    return ao_ceilf(x - 0.5f);
}

#endif

#ifndef ao_roundl_half_down

long double ao_roundl_half_down(long double x)
{
    return ao_ceill(x - 0.5l);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_roundd_half_to_even

double ao_roundd_half_to_even(double x)
{
    // Variables.

    double f;

    double i;

    double t;


    // Ready.

    if (x > 0)
    {
        i = ao_truncd(x);

        f = x - i;

        if (f < 0.5)
        {
            return i;
        }

        else if (f > 0.5)
        {
            return i + 1.0;
        }

        else
        {
            t = ao_fmodd(i, 2.0);

            t = ao_fabsd(t);

            // i is even.

            if (t < 0.5)
            {
                return i;
            }

            // i is odd.

            else
            {
                return i + 1.0;
            }
        }
    }

    else if (x < 0)
    {
        i = ao_truncd(x);

        f = i - x;

        if (f < 0.5)
        {
            return i;
        }

        else if (f > 0.5)
        {
            return i - 1.0;
        }

        else
        {
            t = ao_fmodd(i, 2.0);

            t = ao_fabsd(t);

            // i is even.

            if (t < 0.5)
            {
                return i;
            }

            // i is odd.

            else
            {
                return i - 1.0;
            }
        }
    }

    else
    {
        return 0.0;
    }
}

#endif

#ifndef ao_roundf_half_to_even

float ao_roundf_half_to_even(float x)
{
    // Variables.

    float f;

    float i;

    float t;


    // Ready.

    if (x > 0)
    {
        i = ao_truncf(x);

        f = x - i;

        if (f < 0.5f)
        {
            return i;
        }

        else if (f > 0.5f)
        {
            return i + 1.0f;
        }

        else
        {
            t = ao_fmodf(i, 2.0f);

            t = ao_fabsf(t);

            // i is even.

            if (t < 0.5f)
            {
                return i;
            }

            // i is odd.

            else
            {
                return i + 1.0f;
            }
        }
    }

    else if (x < 0)
    {
        i = ao_truncf(x);

        f = i - x;

        if (f < 0.5f)
        {
            return i;
        }

        else if (f > 0.5f)
        {
            return i - 1.0f;
        }

        else
        {
            t = ao_fmodf(i, 2.0f);

            t = ao_fabsf(t);

            // i is even.

            if (t < 0.5f)
            {
                return i;
            }

            // i is odd.

            else
            {
                return i - 1.0f;
            }
        }
    }

    else
    {
        return 0.0f;
    }
}

#endif

#ifndef ao_roundl_half_to_even

long double ao_roundl_half_to_even(long double x)
{
    // Variables.

    long double f;

    long double i;

    long double t;


    // Ready.

    if (x > 0)
    {
        i = ao_truncl(x);

        f = x - i;

        if (f < 0.5l)
        {
            return i;
        }

        else if (f > 0.5l)
        {
            return i + 1.0l;
        }

        else
        {
            t = ao_fmodl(i, 2.0l);

            t = ao_fabsl(t);

            // i is even.

            if (t < 0.5l)
            {
                return i;
            }

            // i is odd.

            else
            {
                return i + 1.0l;
            }
        }
    }

    else if (x < 0)
    {
        i = ao_truncl(x);

        f = i - x;

        if (f < 0.5l)
        {
            return i;
        }

        else if (f > 0.5l)
        {
            return i - 1.0l;
        }

        else
        {
            t = ao_fmodl(i, 2.0l);

            t = ao_fabsl(t);

            // i is even.

            if (t < 0.5l)
            {
                return i;
            }

            // i is odd.

            else
            {
                return i - 1.0l;
            }
        }
    }

    else
    {
        return 0.0l;
    }
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_roundd_half_to_infinity

double ao_roundd_half_to_infinity(double x)
{
    if (x > 0)
    {
        return ao_floord(x + 0.5);
    }
    else
    {
        return ao_ceild(x - 0.5);
    }
}

#endif

#ifndef ao_roundf_half_to_infinity

float ao_roundf_half_to_infinity(float x)
{
    if (x > 0)
    {
        return ao_floorf(x + 0.5f);
    }
    else
    {
        return ao_ceilf(x - 0.5f);
    }
}

#endif

#ifndef ao_roundl_half_to_infinity

long double ao_roundl_half_to_infinity(long double x)
{
    if (x > 0)
    {
        return ao_floorl(x + 0.5l);
    }
    else
    {
        return ao_ceill(x - 0.5l);
    }
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_roundd_half_to_odd

double ao_roundd_half_to_odd(double x)
{
    // Variables.

    double f;

    double i;

    double t;


    // Ready.

    if (x > 0)
    {
        i = ao_truncd(x);

        f = x - i;

        if (f < 0.5)
        {
            return i;
        }

        else if (f > 0.5)
        {
            return i + 1.0;
        }

        else
        {
            t = ao_fmodd(i, 2.0);

            t = ao_fabsd(t);

            // i is even.

            if (t < 0.5)
            {
                return i + 1.0;
            }

            // i is odd.

            else
            {
                return i;
            }
        }
    }

    else if (x < 0)
    {
        i = ao_truncd(x);

        f = i - x;

        if (f < 0.5)
        {
            return i;
        }

        else if (f > 0.5)
        {
            return i - 1.0;
        }

        else
        {
            t = ao_fmodd(i, 2.0);

            t = ao_fabsd(t);

            // i is even.

            if (t < 0.5)
            {
                return i - 1.0;
            }

            // i is odd.

            else
            {
                return i;
            }
        }
    }

    else
    {
        return 0.0;
    }
}

#endif

#ifndef ao_roundf_half_to_odd

float ao_roundf_half_to_odd(float x)
{
    // Variables.

    float f;

    float i;

    float t;


    // Ready.

    if (x > 0)
    {
        i = ao_truncf(x);

        f = x - i;

        if (f < 0.5f)
        {
            return i;
        }

        else if (f > 0.5f)
        {
            return i + 1.0f;
        }

        else
        {
            t = ao_fmodf(i, 2.0f);

            t = ao_fabsf(t);

            // i is even.

            if (t < 0.5f)
            {
                return i + 1.0f;
            }

            // i is odd.

            else
            {
                return i;
            }
        }
    }

    else if (x < 0)
    {
        i = ao_truncf(x);

        f = i - x;

        if (f < 0.5f)
        {
            return i;
        }

        else if (f > 0.5f)
        {
            return i - 1.0f;
        }

        else
        {
            t = ao_fmodf(i, 2.0f);

            t = ao_fabsf(t);

            // i is even.

            if (t < 0.5f)
            {
                return i - 1.0f;
            }

            // i is odd.

            else
            {
                return i;
            }
        }
    }

    else
    {
        return 0.0f;
    }
}

#endif

#ifndef ao_roundl_half_to_odd

long double ao_roundl_half_to_odd(long double x)
{
    // Variables.

    long double f;

    long double i;

    long double t;


    // Ready.

    if (x > 0)
    {
        i = ao_truncl(x);

        f = x - i;

        if (f < 0.5l)
        {
            return i;
        }

        else if (f > 0.5l)
        {
            return i + 1.0l;
        }

        else
        {
            t = ao_fmodl(i, 2.0l);

            t = ao_fabsl(t);

            // i is even.

            if (t < 0.5l)
            {
                return i + 1.0l;
            }

            // i is odd.

            else
            {
                return i;
            }
        }
    }

    else if (x < 0)
    {
        i = ao_truncl(x);

        f = i - x;

        if (f < 0.5l)
        {
            return i;
        }

        else if (f > 0.5l)
        {
            return i - 1.0l;
        }

        else
        {
            t = ao_fmodl(i, 2.0l);

            t = ao_fabsl(t);

            // i is even.

            if (t < 0.5l)
            {
                return i - 1.0l;
            }

            // i is odd.

            else
            {
                return i;
            }
        }
    }

    else
    {
        return 0.0l;
    }
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_roundd_half_to_zero

double ao_roundd_half_to_zero(double x)
{
    if (x > 0)
    {
        return ao_ceild(x - 0.5);
    }
    else
    {
        return ao_floord(x + 0.5);
    }
}

#endif

#ifndef ao_roundf_half_to_zero

float ao_roundf_half_to_zero(float x)
{
    if (x > 0)
    {
        return ao_ceilf(x - 0.5f);
    }
    else
    {
        return ao_floorf(x + 0.5f);
    }
}

#endif

#ifndef ao_roundl_half_to_zero

long double ao_roundl_half_to_zero(long double x)
{
    if (x > 0)
    {
        return ao_ceill(x - 0.5l);
    }
    else
    {
        return ao_floorl(x + 0.5l);
    }
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_roundd_half_up

double ao_roundd_half_up(double x)
{
    return ao_floord(x + 0.5);
}

#endif

#ifndef ao_roundf_half_up

float ao_roundf_half_up(float x)
{
    return ao_floorf(x + 0.5f);
}

#endif

#ifndef ao_roundl_half_up

long double ao_roundl_half_up(long double x)
{
    return ao_floorl(x + 0.5l);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_secd

double ao_secd(double x)
{
    return 1.0 / ao_cosd(x);
}

#endif

#ifndef ao_secf

float ao_secf(float x)
{
    return 1.0f / ao_cosf(x);
}

#endif

#ifndef ao_secl

long double ao_secl(long double x)
{
    return 1.0l / ao_cosl(x);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_sechd

double ao_sechd(double x)
{
    return 1.0 / ao_coshd(x);
}

#endif

#ifndef ao_sechf

float ao_sechf(float x)
{
    return 1.0f / ao_coshf(x);
}

#endif

#ifndef ao_sechl

long double ao_sechl(long double x)
{
    return 1.0l / ao_coshl(x);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_signd

double ao_signd(double x)
{
    if (x > 0)
    {
        return 1.0;
    }
    else if (x < 0)
    {
        return -1.0;
    }
    else
    {
        return 0.0;
    }
}

#endif

#ifndef ao_signf

float ao_signf(float x)
{
    if (x > 0)
    {
        return 1.0f;
    }
    else if (x < 0)
    {
        return -1.0f;
    }
    else
    {
        return 0.0f;
    }
}

#endif

#ifndef ao_signl

long double ao_signl(long double x)
{
    if (x > 0)
    {
        return 1.0l;
    }
    else if (x < 0)
    {
        return -1.0l;
    }
    else
    {
        return 0.0l;
    }
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_sinhd

double ao_sinhd(double x)
{
    double t1 = ao_expd( x);
    double t2 = ao_expd(-x);

    return 0.5 * (t1 - t2);
}

#endif

#ifndef ao_sinhf

float ao_sinhf(float x)
{
    float t1 = ao_expf( x);
    float t2 = ao_expf(-x);

    return 0.5f * (t1 - t2);
}

#endif

#ifndef ao_sinhl

long double ao_sinhl(long double x)
{
    long double t1 = ao_expl( x);
    long double t2 = ao_expl(-x);

    return 0.5l * (t1 - t2);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_tanhd

double ao_tanhd(double x)
{
    double t = ao_expd(2.0 * x);

    return (t - 1.0) / (t + 1.0);
}

#endif

#ifndef ao_tanhf

float ao_tanhf(float x)
{
    float t = ao_expf(2.0f * x);

    return (t - 1.0f) / (t + 1.0f);
}

#endif

#ifndef ao_tanhl

long double ao_tanhl(long double x)
{
    long double t = ao_expl(2.0l * x);

    return (t - 1.0l) / (t + 1.0l);
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_truncd

double ao_truncd(double x)
{
    if (x > 0)
    {
        return ao_floord(x);
    }
    else
    {
        return ao_ceild(x);
    }
}

#endif

#ifndef ao_truncf

float ao_truncf(float x)
{
    if (x > 0)
    {
        return ao_floorf(x);
    }
    else
    {
        return ao_ceilf(x);
    }
}

#endif

#ifndef ao_truncl

long double ao_truncl(long double x)
{
    if (x > 0)
    {
        return ao_floorl(x);
    }
    else
    {
        return ao_ceill(x);
    }
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_wrapd

double ao_wrapd(double x, double beginning, double length)
{
    return x - length * ao_floord((x - beginning) / length);
}

#endif

#ifndef ao_wrapf

float ao_wrapf(float x, float beginning, float length)
{
    return x - length * ao_floorf((x - beginning) / length);
}

#endif

#ifndef ao_wrapl

long double ao_wrapl(long double x, long double beginning, long double length)
{
    return x - length * ao_floorl((x - beginning) / length);
}

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_PRINT

// ----------------------------------------------------------------------------

size_t ao_printed(char * s, size_t no_max, ao_print_t const * o, double const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(v);


    // Variables.

    bool b1;
    bool b2;
    bool b3;
    bool b4;

    char c;

    int_fast16_t e1;
    int_fast16_t e2;

    size_t i1;
    size_t i2;

    size_t nd;
    size_t ne;
    size_t nes;
    size_t nev;
    size_t nez;
    size_t nf;
    size_t nfv;
    size_t nfz;
    size_t ni;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    static const double p[16] =
    {
        1e+0,
        1e+1,
        1e+2,
        1e+3,
        1e+4,
        1e+5,
        1e+6,
        1e+7,
        1e+8,
        1e+9,
        1e+10,
        1e+11,
        1e+12,
        1e+13,
        1e+14,
        1e+15
    };

    double t1;
    double t2;

    bool u;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;


    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is finite.

    if (ao_isfinited(t1))
    {
        b1 = true;
    }

    // Value is not finite.

    else
    {
        b1 = false;

        // Value is infinity.

        if (ao_isinfd(t1))
        {
            b2 = true;
            b3 = false;
        }

        // Value is not-a-number.

        else if (ao_isnand(t1))
        {
            b2 = false;
            b3 = true;
        }

        // Value is indeterminate.

        else
        {
            b2 = false;
            b3 = false;
        }
    }


    // Sign.

    // Value is finite.

    if (b1)
    {
        // Value is negative.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent digits.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '-';

            t1 = ao_fabsd(t1);

            b4 = true;
        }

        // Value is positive.

        else if (ao_is_positive(t1))
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent digits.

                    if (no_max == 1) return 0;

                    no = 1;

                    s[0] = ' ';
                }

                else
                {
                    no = 0;
                }
            }

            b4 = true;
        }

        // Value is zero.

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }

            b4 = false;
        }
    }

    // Value is infinity.

    else if (b2)
    {
        // Value is negative infinity.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            s[0] = '-';
        }

        // Value is positive infinity.

        else
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent characters.

                if (no_max < 4) return 0;

                no = 1;

                s[0] = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 4) return 0;

                    no = 1;

                    s[0] = ' ';
                }

                else
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 3) return 0;

                    no = 0;
                }
            }
        }
    }

    // Value is not-a-number or indeterminate.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 3) return 0;

            no = 0;
        }
    }

    ns = no;


    // Value is finite.

    if (b1)
    {
        // Precision.

        np = o->precision;

        np = ao_min(np, DBL_DIG);


        // Mantissa and exponent.

        // Value is not zero.

        if (b4)
        {
            t2 = ao_log10d(t1);

            t2 = ao_floord(t2);

            e1 = (int_fast16_t) t2;

            if (0 == e1) { }

            else if (0 < e1 && e1 <= 15)
            {
                t2 = p[e1];

                t1 = t1 / t2;
            }

            else if (0 > e1 && e1 >= -15)
            {
                t2 = p[-e1];

                t1 = t1 * t2;
            }

            else
            {
                t2 = ao_powd((double) 10, t2);

                t1 = t1 / t2;
            }

            if (ao_is_less(t1, (double) 1))
            {
                e1--;

                t1 = t1 * (double) 10;
            }

            else if (ao_is_greater_equal(t1, (double) 10))
            {
                e1++;

                t1 = t1 / (double) 10;
            }

            if (np == 0)
            {
                t1 = ao_roundd_half_up(t1);

                if (ao_is_greater_equal(t1, (double) 10))
                {
                    e1++;

                    t1 = t1 / (double) 10;
                }
            }
        }

        // Value is zero.

        else
        {
            e1 = 0;
        }


        // Integral.

        ni = o->digits_integral;

        if (ni > 1)
        {
            niz = ni - 1;
        }

        else
        {
            ni = 1;
            niz = 0;
        }


        // Integral leading zeros.

        if (niz > 0)
        {
            // Not enough space left in the string.

            if (no_max - no < ni) return 0;

            for (i1 = 0; i1 < niz; i1++)
            {
                s[no + i1] = '0';
            }

            no += niz;
        }


        // Integral value.

        s[no] = '0' + (char) t1;

        no++;


        // Fractional value.

        // Precision is zero.

        if (np == 0)
        {
            nd = 0;

            nfv = 0;
        }

        // Precision is not zero.

        else
        {
            t2 = ao_floord(t1);

            t1 = t1 - t2;

            if (np <= 15)
            {
                t2 = p[np];
            }

            else
            {
                t2 = ao_powd((double) 10, (double) np);
            }

            t1 = t1 * t2;

            t1 = ao_roundd_half_up(t1);


            b2 = true;

            while (b2)
            {
                t2 = ao_fmodd(t1, (double) 10);

                c = (char) t2;

                if (c == 0)
                {
                    t1 = t1 / (double) 10;

                    np--;

                    if (np == 0)
                    {
                        b2 = false;
                    }
                }

                else
                {
                    b2 = false;
                }
            }

            nfv = np;


            // Fractional value is zero.

            if (nfv == 0)
            {
                nd = 0;
            }

            // Fractional value is not zero.

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfv + 1) return 0;

                s[no] = '.';

                s[no + np] = '0' + c;

                for (i1 = np - 1; i1 > 0; i1--)
                {
                    t1 = t1 / (double) 10;

                    t2 = ao_fmodd(t1, (double) 10);

                    s[no + i1] = '0' + (char) t2;
                }

                nd = 1;

                no = no + nfv + 1;
            }
        }


        nf = o->digits_fractional;

        if (nf < nfv)
        {
            nfz = 0;
            nf = nfv;
        }

        else
        {
            nfz = nf - nfv;
        }


        // Fractional trailing zeros.

        if (nfz > 0)
        {
            if (nfv == 0)
            {
                // Not enough space left in the string.

                if (no_max - no < nfz + 1) return 0;

                s[no] = '.';

                no++;

                nd = 1;
            }

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfz) return 0;
            }

            for (i1 = 0; i1 < nfz; i1++)
            {
                s[no + i1] = '0';
            }

            no += nfz;
        }


        // Exponent.

        // Not enough space left in the string.

        if (no_max - no < 2) return 0;

        u = o->uppercase;

        s[no] = u ? 'E' : 'e';

        no++;


        // Exponent sign.

        // Exponent is negative.

        if (e1 < 0)
        {
            // Not enough space left in the string.

            if (no_max - no < 2) return 0;

            s[no] = '-';

            no++;

            nes = 1;

            e1 = -e1;

            b4 = true;
        }

        // Exponent is positive or zero.

        else
        {
            b4 = (e1 > 0) ? true : false;

            if (o->sign_exponent)
            {
                // Not enough space left in the string.

                if (no_max - no < 2) return 0;

                s[no] = '+';

                no++;

                nes = 1;
            }

            else
            {
                nes = 0;
            }
        }


        // Exponent value.

        // Exponent value is not zero.

        if (b4)
        {
            nev = 0;

            do
            {
                e2 = e1 % 10;

                e1 = e1 / 10;

                s[no] = '0' + (char) e2;

                nev++;
                no++;

                if (e1 == 0)
                {
                    b4 = false;
                }

                else
                {
                    // Not enough space left in the string.

                    if (no == no_max) return 0;
                }
            }
            while (b4);
        }

        // Exponent value is zero.

        else
        {
            s[no] = '0';

            no++;

            nev = 1;
        }


        // Exponent leading zeros.

        nez = o->digits_exponent;

        if (nev < nez)
        {
            nez = nez - nev;

            // Not enough space left in the string.

            if (no_max - no < nez) return 0;

            for (i1 = 0; i1 < nez; i1++)
            {
                s[no + i1] = '0';
            }

            no += nez;
        }

        else
        {
            nez = 0;
        }

        ne = nez + nev;


        // Exponent reverse.

        if (ne > 1)
        {
            i1 = no - ne;
            i2 = no - 1;

            for (; i1 < i2; i1++, i2--)
            {
                c = s[i1];
                s[i1] = s[i2];
                s[i2] = c;
            }
        }


        ne = 1 + nes + ne;
    }

    // Value is not finite.

    else
    {
        u = o->uppercase;

        // Value is infinity.

        if (b2)
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'F';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'f';
            }
        }

        // Value is not-a-number.

        else if (b3)
        {
            if (u)
            {
                s[no + 0] = 'N';
                s[no + 1] = 'A';
                s[no + 2] = 'N';
            }

            else
            {
                s[no + 0] = 'n';
                s[no + 1] = 'a';
                s[no + 2] = 'n';
            }
        }

        // Value is indeterminate.

        else
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'D';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'd';
            }
        }

        no += 3;

        ni = 3;
        nd = 0;
        nf = 0;
        ne = 0;
    }


    nn = ns + ni + nd + nf + ne;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

size_t ao_printef(char * s, size_t no_max, ao_print_t const * o, float const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(v);


    // Variables.

    bool b1;
    bool b2;
    bool b3;
    bool b4;

    char c;

    int_fast16_t e1;
    int_fast16_t e2;

    size_t i1;
    size_t i2;

    size_t nd;
    size_t ne;
    size_t nes;
    size_t nev;
    size_t nez;
    size_t nf;
    size_t nfv;
    size_t nfz;
    size_t ni;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    static const float p[16] =
    {
        1e+0f,
        1e+1f,
        1e+2f,
        1e+3f,
        1e+4f,
        1e+5f,
        1e+6f,
        1e+7f,
        1e+8f,
        1e+9f,
        1e+10f,
        1e+11f,
        1e+12f,
        1e+13f,
        1e+14f,
        1e+15f
    };

    float t1;
    float t2;

    bool u;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is finite.

    if (ao_isfinited(t1))
    {
        b1 = true;
    }

    // Value is not finite.

    else
    {
        b1 = false;

        // Value is infinity.

        if (ao_isinfd(t1))
        {
            b2 = true;
            b3 = false;
        }

        // Value is not-a-number.

        else if (ao_isnand(t1))
        {
            b2 = false;
            b3 = true;
        }

        // Value is indeterminate.

        else
        {
            b2 = false;
            b3 = false;
        }
    }


    // Sign.

    // Value is finite.

    if (b1)
    {
        // Value is negative.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent digits.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '-';

            t1 = ao_fabsf(t1);

            b4 = true;
        }

        // Value is positive.

        else if (ao_is_positive(t1))
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent digits.

                    if (no_max == 1) return 0;

                    no = 1;

                    s[0] = ' ';
                }

                else
                {
                    no = 0;
                }
            }

            b4 = true;
        }

        // Value is zero.

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }

            b4 = false;
        }
    }

    // Value is infinity.

    else if (b2)
    {
        // Value is negative infinity.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            s[0] = '-';
        }

        // Value is positive infinity.

        else
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent characters.

                if (no_max < 4) return 0;

                no = 1;

                s[0] = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 4) return 0;

                    no = 1;

                    s[0] = ' ';
                }

                else
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 3) return 0;

                    no = 0;
                }
            }
        }
    }

    // Value is not-a-number or indeterminate.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 3) return 0;

            no = 0;
        }
    }

    ns = no;


    // Value is finite.

    if (b1)
    {
        // Precision.

        np = o->precision;

        np = ao_min(np, FLT_DIG);


        // Mantissa and exponent.

        // Value is not zero.

        if (b4)
        {
            t2 = ao_log10f(t1);

            t2 = ao_floorf(t2);

            e1 = (int_fast16_t) t2;

            if (0 == e1) { }

            else if (0 < e1 && e1 <= 15)
            {
                t2 = p[e1];

                t1 = t1 / t2;
            }

            else if (0 > e1 && e1 >= -15)
            {
                t2 = p[-e1];

                t1 = t1 * t2;
            }

            else
            {
                t2 = ao_powf((float) 10, t2);

                t1 = t1 / t2;
            }

            if (ao_is_less(t1, (float) 1))
            {
                e1--;

                t1 = t1 * (float) 10;
            }

            else if (ao_is_greater_equal(t1, (float) 10))
            {
                e1++;

                t1 = t1 / (float) 10;
            }

            if (np == 0)
            {
                t1 = ao_roundf_half_up(t1);

                if (ao_is_greater_equal(t1, (float) 10))
                {
                    e1++;

                    t1 = t1 / (float) 10;
                }
            }
        }

        // Value is zero.

        else
        {
            e1 = 0;
        }


        // Integral.

        ni = o->digits_integral;

        if (ni > 1)
        {
            niz = ni - 1;
        }

        else
        {
            ni = 1;
            niz = 0;
        }


        // Integral leading zeros.

        if (niz > 0)
        {
            // Not enough space left in the string.

            if (no_max - no < ni) return 0;

            for (i1 = 0; i1 < niz; i1++)
            {
                s[no + i1] = '0';
            }

            no += niz;
        }


        // Integral value.

        s[no] = '0' + (char) t1;

        no++;


        // Fractional value.

        // Precision is zero.

        if (np == 0)
        {
            nd = 0;

            nfv = 0;
        }

        // Precision is not zero.

        else
        {
            t2 = ao_floorf(t1);

            t1 = t1 - t2;

            if (np <= 15)
            {
                t2 = p[np];
            }

            else
            {
                t2 = ao_powf((float) 10, (float) np);
            }

            t1 = t1 * t2;

            t1 = ao_roundf_half_up(t1);


            b2 = true;

            while (b2)
            {
                t2 = ao_fmodf(t1, (float) 10);

                c = (char) t2;

                if (c == 0)
                {
                    t1 = t1 / (float) 10;

                    np--;

                    if (np == 0)
                    {
                        b2 = false;
                    }
                }

                else
                {
                    b2 = false;
                }
            }

            nfv = np;


            // Fractional value is zero.

            if (nfv == 0)
            {
                nd = 0;
            }

            // Fractional value is not zero.

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfv + 1) return 0;

                s[no] = '.';

                s[no + np] = '0' + c;

                for (i1 = np - 1; i1 > 0; i1--)
                {
                    t1 = t1 / (float) 10;

                    t2 = ao_fmodf(t1, (float) 10);

                    s[no + i1] = '0' + (char) t2;
                }

                nd = 1;

                no = no + nfv + 1;
            }
        }


        nf = o->digits_fractional;

        if (nf < nfv)
        {
            nfz = 0;
            nf = nfv;
        }

        else
        {
            nfz = nf - nfv;
        }


        // Fractional trailing zeros.

        if (nfz > 0)
        {
            if (nfv == 0)
            {
                // Not enough space left in the string.

                if (no_max - no < nfz + 1) return 0;

                s[no] = '.';

                no++;

                nd = 1;
            }

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfz) return 0;
            }

            for (i1 = 0; i1 < nfz; i1++)
            {
                s[no + i1] = '0';
            }

            no += nfz;
        }


        // Exponent.

        // Not enough space left in the string.

        if (no_max - no < 2) return 0;

        u = o->uppercase;

        s[no] = u ? 'E' : 'e';

        no++;


        // Exponent sign.

        // Exponent is negative.

        if (e1 < 0)
        {
            // Not enough space left in the string.

            if (no_max - no < 2) return 0;

            s[no] = '-';

            no++;

            nes = 1;

            e1 = -e1;

            b4 = true;
        }

        // Exponent is positive or zero.

        else
        {
            b4 = (e1 > 0) ? true : false;

            if (o->sign_exponent)
            {
                // Not enough space left in the string.

                if (no_max - no < 2) return 0;

                s[no] = '+';

                no++;

                nes = 1;
            }

            else
            {
                nes = 0;
            }
        }


        // Exponent value.

        // Exponent value is not zero.

        if (b4)
        {
            nev = 0;

            do
            {
                e2 = e1 % 10;

                e1 = e1 / 10;

                s[no] = '0' + (char) e2;

                nev++;
                no++;

                if (e1 == 0)
                {
                    b4 = false;
                }

                else
                {
                    // Not enough space left in the string.

                    if (no == no_max) return 0;
                }
            }
            while (b4);
        }

        // Exponent value is zero.

        else
        {
            s[no] = '0';

            no++;

            nev = 1;
        }


        // Exponent leading zeros.

        nez = o->digits_exponent;

        if (nev < nez)
        {
            nez = nez - nev;

            // Not enough space left in the string.

            if (no_max - no < nez) return 0;

            for (i1 = 0; i1 < nez; i1++)
            {
                s[no + i1] = '0';
            }

            no += nez;
        }

        else
        {
            nez = 0;
        }

        ne = nez + nev;


        // Exponent reverse.

        if (ne > 1)
        {
            i1 = no - ne;
            i2 = no - 1;

            for (; i1 < i2; i1++, i2--)
            {
                c = s[i1];
                s[i1] = s[i2];
                s[i2] = c;
            }
        }


        ne = 1 + nes + ne;
    }

    // Value is not finite.

    else
    {
        u = o->uppercase;

        // Value is infinity.

        if (b2)
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'F';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'f';
            }
        }

        // Value is not-a-number.

        else if (b3)
        {
            if (u)
            {
                s[no + 0] = 'N';
                s[no + 1] = 'A';
                s[no + 2] = 'N';
            }

            else
            {
                s[no + 0] = 'n';
                s[no + 1] = 'a';
                s[no + 2] = 'n';
            }
        }

        // Value is indeterminate.

        else
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'D';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'd';
            }
        }

        no += 3;

        ni = 3;
        nd = 0;
        nf = 0;
        ne = 0;
    }


    nn = ns + ni + nd + nf + ne;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

size_t ao_printel(char * s, size_t no_max, ao_print_t const * o, long double const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(v);


    // Variables.

    bool b1;
    bool b2;
    bool b3;
    bool b4;

    char c;

    int_fast16_t e1;
    int_fast16_t e2;

    size_t i1;
    size_t i2;

    size_t nd;
    size_t ne;
    size_t nes;
    size_t nev;
    size_t nez;
    size_t nf;
    size_t nfv;
    size_t nfz;
    size_t ni;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    static const long double p[16] =
    {
        1e+0l,
        1e+1l,
        1e+2l,
        1e+3l,
        1e+4l,
        1e+5l,
        1e+6l,
        1e+7l,
        1e+8l,
        1e+9l,
        1e+10l,
        1e+11l,
        1e+12l,
        1e+13l,
        1e+14l,
        1e+15l
    };

    long double t1;
    long double t2;

    bool u;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is finite.

    if (ao_isfinited(t1))
    {
        b1 = true;
    }

    // Value is not finite.

    else
    {
        b1 = false;

        // Value is infinity.

        if (ao_isinfd(t1))
        {
            b2 = true;
            b3 = false;
        }

        // Value is not-a-number.

        else if (ao_isnand(t1))
        {
            b2 = false;
            b3 = true;
        }

        // Value is indeterminate.

        else
        {
            b2 = false;
            b3 = false;
        }
    }


    // Sign.

    // Value is finite.

    if (b1)
    {
        // Value is negative.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent digits.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '-';

            t1 = ao_fabsl(t1);

            b4 = true;
        }

        // Value is positive.

        else if (ao_is_positive(t1))
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent digits.

                    if (no_max == 1) return 0;

                    no = 1;

                    s[0] = ' ';
                }

                else
                {
                    no = 0;
                }
            }

            b4 = true;
        }

        // Value is zero.

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }

            b4 = false;
        }
    }

    // Value is infinity.

    else if (b2)
    {
        // Value is negative infinity.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            s[0] = '-';
        }

        // Value is positive infinity.

        else
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent characters.

                if (no_max < 4) return 0;

                no = 1;

                s[0] = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 4) return 0;

                    no = 1;

                    s[0] = ' ';
                }

                else
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 3) return 0;

                    no = 0;
                }
            }
        }
    }

    // Value is not-a-number or indeterminate.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 3) return 0;

            no = 0;
        }
    }

    ns = no;


    // Value is finite.

    if (b1)
    {
        // Precision.

        np = o->precision;

        np = ao_min(np, LDBL_DIG);


        // Mantissa and exponent.

        // Value is not zero.

        if (b4)
        {
            t2 = ao_log10l(t1);

            t2 = ao_floorl(t2);

            e1 = (int_fast16_t) t2;

            if (0 == e1) { }

            else if (0 < e1 && e1 <= 15)
            {
                t2 = p[e1];

                t1 = t1 / t2;
            }

            else if (0 > e1 && e1 >= -15)
            {
                t2 = p[-e1];

                t1 = t1 * t2;
            }

            else
            {
                t2 = ao_powl((long double) 10, t2);

                t1 = t1 / t2;
            }

            if (ao_is_less(t1, (long double) 1))
            {
                e1--;

                t1 = t1 * (long double) 10;
            }

            else if (ao_is_greater_equal(t1, (long double) 10))
            {
                e1++;

                t1 = t1 / (long double) 10;
            }

            if (np == 0)
            {
                t1 = ao_roundl_half_up(t1);

                if (ao_is_greater_equal(t1, (long double) 10))
                {
                    e1++;

                    t1 = t1 / (long double) 10;
                }
            }
        }

        // Value is zero.

        else
        {
            e1 = 0;
        }


        // Integral.

        ni = o->digits_integral;

        if (ni > 1)
        {
            niz = ni - 1;
        }

        else
        {
            ni = 1;
            niz = 0;
        }


        // Integral leading zeros.

        if (niz > 0)
        {
            // Not enough space left in the string.

            if (no_max - no < ni) return 0;

            for (i1 = 0; i1 < niz; i1++)
            {
                s[no + i1] = '0';
            }

            no += niz;
        }


        // Integral value.

        s[no] = '0' + (char) t1;

        no++;


        // Fractional value.

        // Precision is zero.

        if (np == 0)
        {
            nd = 0;

            nfv = 0;
        }

        // Precision is not zero.

        else
        {
            t2 = ao_floorl(t1);

            t1 = t1 - t2;

            if (np <= 15)
            {
                t2 = p[np];
            }

            else
            {
                t2 = ao_powl((long double) 10, (long double) np);
            }

            t1 = t1 * t2;

            t1 = ao_roundl_half_up(t1);


            b2 = true;

            while (b2)
            {
                t2 = ao_fmodl(t1, (long double) 10);

                c = (char) t2;

                if (c == 0)
                {
                    t1 = t1 / (long double) 10;

                    np--;

                    if (np == 0)
                    {
                        b2 = false;
                    }
                }

                else
                {
                    b2 = false;
                }
            }

            nfv = np;


            // Fractional value is zero.

            if (nfv == 0)
            {
                nd = 0;
            }

            // Fractional value is not zero.

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfv + 1) return 0;

                s[no] = '.';

                s[no + np] = '0' + c;

                for (i1 = np - 1; i1 > 0; i1--)
                {
                    t1 = t1 / (long double) 10;

                    t2 = ao_fmodl(t1, (long double) 10);

                    s[no + i1] = '0' + (char) t2;
                }

                nd = 1;

                no = no + nfv + 1;
            }
        }


        nf = o->digits_fractional;

        if (nf < nfv)
        {
            nfz = 0;
            nf = nfv;
        }

        else
        {
            nfz = nf - nfv;
        }


        // Fractional trailing zeros.

        if (nfz > 0)
        {
            if (nfv == 0)
            {
                // Not enough space left in the string.

                if (no_max - no < nfz + 1) return 0;

                s[no] = '.';

                no++;

                nd = 1;
            }

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfz) return 0;
            }

            for (i1 = 0; i1 < nfz; i1++)
            {
                s[no + i1] = '0';
            }

            no += nfz;
        }


        // Exponent.

        // Not enough space left in the string.

        if (no_max - no < 2) return 0;

        u = o->uppercase;

        s[no] = u ? 'E' : 'e';

        no++;


        // Exponent sign.

        // Exponent is negative.

        if (e1 < 0)
        {
            // Not enough space left in the string.

            if (no_max - no < 2) return 0;

            s[no] = '-';

            no++;

            nes = 1;

            e1 = -e1;

            b4 = true;
        }

        // Exponent is positive or zero.

        else
        {
            b4 = (e1 > 0) ? true : false;

            if (o->sign_exponent)
            {
                // Not enough space left in the string.

                if (no_max - no < 2) return 0;

                s[no] = '+';

                no++;

                nes = 1;
            }

            else
            {
                nes = 0;
            }
        }


        // Exponent value.

        // Exponent value is not zero.

        if (b4)
        {
            nev = 0;

            do
            {
                e2 = e1 % 10;

                e1 = e1 / 10;

                s[no] = '0' + (char) e2;

                nev++;
                no++;

                if (e1 == 0)
                {
                    b4 = false;
                }

                else
                {
                    // Not enough space left in the string.

                    if (no == no_max) return 0;
                }
            }
            while (b4);
        }

        // Exponent value is zero.

        else
        {
            s[no] = '0';

            no++;

            nev = 1;
        }


        // Exponent leading zeros.

        nez = o->digits_exponent;

        if (nev < nez)
        {
            nez = nez - nev;

            // Not enough space left in the string.

            if (no_max - no < nez) return 0;

            for (i1 = 0; i1 < nez; i1++)
            {
                s[no + i1] = '0';
            }

            no += nez;
        }

        else
        {
            nez = 0;
        }

        ne = nez + nev;


        // Exponent reverse.

        if (ne > 1)
        {
            i1 = no - ne;
            i2 = no - 1;

            for (; i1 < i2; i1++, i2--)
            {
                c = s[i1];
                s[i1] = s[i2];
                s[i2] = c;
            }
        }


        ne = 1 + nes + ne;
    }

    // Value is not finite.

    else
    {
        u = o->uppercase;

        // Value is infinity.

        if (b2)
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'F';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'f';
            }
        }

        // Value is not-a-number.

        else if (b3)
        {
            if (u)
            {
                s[no + 0] = 'N';
                s[no + 1] = 'A';
                s[no + 2] = 'N';
            }

            else
            {
                s[no + 0] = 'n';
                s[no + 1] = 'a';
                s[no + 2] = 'n';
            }
        }

        // Value is indeterminate.

        else
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'D';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'd';
            }
        }

        no += 3;

        ni = 3;
        nd = 0;
        nf = 0;
        ne = 0;
    }


    nn = ns + ni + nd + nf + ne;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

// ----------------------------------------------------------------------------

size_t ao_printfd(char * s, size_t no_max, ao_print_t const * o, double const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(v);


    // Variables.

    bool b1;
    bool b2;
    bool b3;

    char c;

    char cs;

    size_t i1;
    size_t i2;

    size_t nd;
    size_t nf;
    size_t nfv;
    size_t nfz;
    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    static const double p[16] =
    {
        1e+0,
        1e+1,
        1e+2,
        1e+3,
        1e+4,
        1e+5,
        1e+6,
        1e+7,
        1e+8,
        1e+9,
        1e+10,
        1e+11,
        1e+12,
        1e+13,
        1e+14,
        1e+15
    };

    double t1;
    double t1i;
    double t1f;
    double t2;

    bool u;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is finite.

    if (ao_isfinited(t1))
    {
        b1 = true;
    }

    // Value is not finite.

    else
    {
        b1 = false;

        // Value is infinity.

        if (ao_isinfd(t1))
        {
            b2 = true;
            b3 = false;
        }

        // Value is not-a-number.

        else if (ao_isnand(t1))
        {
            b2 = false;
            b3 = true;
        }

        // Value is indeterminate.

        else
        {
            b2 = false;
            b3 = false;
        }
    }


    // Sign.

    // Value is finite.

    if (b1)
    {
        // Value is negative.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent digits.

            if (no_max == 1) return 0;

            no = 1;

            cs = '-';

            t1 = ao_fabsd(t1);
        }

        // Value is positive.

        else if (ao_is_positive(t1))
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                cs = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent digits.

                    if (no_max == 1) return 0;

                    no = 1;

                    cs = ' ';
                }

                else
                {
                    no = 0;
                }
            }
        }

        // Value is zero.

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                cs = ' ';
            }

            else
            {
                no = 0;
            }
        }
    }

    // Value is infinity.

    else if (b2)
    {
        // Value is negative infinity.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            cs = '-';
        }

        // Value is positive infinity.

        else
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent characters.

                if (no_max < 4) return 0;

                no = 1;

                cs = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 4) return 0;

                    no = 1;

                    cs = ' ';
                }

                else
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 3) return 0;

                    no = 0;
                }
            }
        }
    }

    // Value is not-a-number or indeterminate.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            cs = ' ';
        }

        else
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 3) return 0;

            no = 0;
        }
    }

    ns = no;


    // Value is finite.

    if (b1)
    {
        // Precision.

        np = o->precision;

        np = ao_min(np, DBL_DIG);


        // Value.

        t1i = ao_floord(t1);

        t1f = t1 - t1i;

        t2 = (np <= 15) ? p[np] : ao_powd((double) 10, (double) np);

        t1f = t1f * t2;

        t1f = ao_roundd_half_up(t1f);

        t1 = t1f / t2;

        if (ao_is_greater_equal(t1, (double) 1))
        {
            t1i = t1i + (double) 1;

            t1 = t1 - (double) 1;

            t1f = t1 * t2;
        }


        // Integral.

        // Integral is not zero.

        if (ao_is_greater_equal(t1i, (double) 1))
        {
            t1 = ao_log10d(t1i);

            ao_assert(ao_isfinited(t1));

            t1 = ao_floord(t1);

            ao_assert(ao_is_greater_equal(t1, (double) 0));

            ni = (size_t) t1;

            if (ni > DBL_DIG)
            {
                niv = ni - DBL_DIG;

                // Not enough space left in the string.

                if (no_max - no < niv + 1) return 0;

                for (i1 = 0; i1 < niv; i1++)
                {
                    s[no + i1] = '0';
                }

                no += niv;

                t2 = (niv <= 15) ? p[niv] : ao_powd((double) 10, (double) niv);

                t1i = t1i / t2;
            }

            else
            {
                niv = 0;
            }

            b2 = true;

            do
            {
                t2 = ao_fmodd(t1i, (double) 10);

                t1i = t1i / (double) 10;

                s[no] = '0' + (char) t2;

                no++;
                niv++;

                if (ao_is_less(t1i, (double) 1))
                {
                    b2 = false;
                }

                else
                {
                    if (no == no_max) return 0;
                }
            }
            while (b2);
        }

        // Integral is zero.

        else
        {
            // Fractional is zero.

            if (ao_is_less(t1f, (double) 1))
            {
                no = no - ns;

                ns = 0;
            }

            s[no] = '0';

            no++;

            niv = 1;
        }


        // Integral leading zeros.

        ni = o->digits_integral;

        if (ni > niv)
        {
            niz = ni - niv;

            // Not enough space left in the string.

            if (no_max - no < niz) return 0;

            for (i1 = 0; i1 < niz; i1++)
            {
                s[no + i1] = '0';
            }

            no += niz;
        }

        else
        {
            ni = niv;
        }


        // Integral reverse.

        if (ni > 1)
        {
            i1 = ns;
            i2 = ns + ni - 1;

            for (; i1 < i2; i1++, i2--)
            {
                c = s[i1];
                s[i1] = s[i2];
                s[i2] = c;
            }
        }


        // Precision is zero.

        if (np == 0)
        {
            nd = 0;

            nfv = 0;
        }

        // Precision is not zero.

        else
        {
            b2 = true;

            while (b2)
            {
                t2 = ao_fmodd(t1f, (double) 10);

                c = (char) t2;

                if (c == 0)
                {
                    t1f = t1f / (double) 10;

                    np--;

                    if (np == 0)
                    {
                        b2 = false;
                    }
                }

                else
                {
                    b2 = false;
                }
            }

            nfv = np;


            // Fractional value is zero.

            if (nfv == 0)
            {
                nd = 0;
            }

            // Fractional value is not zero.

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfv + 1) return 0;

                s[no] = '.';

                s[no + np] = '0' + c;

                for (i1 = np - 1; i1 > 0; i1--)
                {
                    t1f = t1f / (double) 10;

                    t2 = ao_fmodd(t1f, (double) 10);

                    s[no + i1] = '0' + (char) t2;
                }

                nd = 1;

                no = no + nfv + 1;
            }
        }


        nf = o->digits_fractional;

        if (nf < nfv)
        {
            nfz = 0;
            nf = nfv;
        }

        else
        {
            nfz = nf - nfv;
        }


        // Fractional trailing zeros.

        if (nfz > 0)
        {
            if (nfv == 0)
            {
                // Not enough space left in the string.

                if (no_max - no < nfz + 1) return 0;

                s[no] = '.';

                no++;

                nd = 1;
            }

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfz) return 0;
            }

            for (i1 = 0; i1 < nfz; i1++)
            {
                s[no + i1] = '0';
            }

            no += nfz;
        }
    }

    // Value is not finite.

    else
    {
        u = o->uppercase;

        // Value is infinity.

        if (b2)
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'F';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'f';
            }
        }

        // Value is not-a-number.

        else if (b3)
        {
            if (u)
            {
                s[no + 0] = 'N';
                s[no + 1] = 'A';
                s[no + 2] = 'N';
            }

            else
            {
                s[no + 0] = 'n';
                s[no + 1] = 'a';
                s[no + 2] = 'n';
            }
        }

        // Value is indeterminate.

        else
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'D';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'd';
            }
        }

        no += 3;

        ni = 3;
        nd = 0;
        nf = 0;
    }


    nn = ns + ni + nd + nf;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    if (ns == 1)
    {
        s[0] = cs;
    }


    return no;
}

size_t ao_printff(char * s, size_t no_max, ao_print_t const * o, float const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(v);


    // Variables.

    bool b1;
    bool b2;
    bool b3;

    char c;

    char cs;

    size_t i1;
    size_t i2;

    size_t nd;
    size_t nf;
    size_t nfv;
    size_t nfz;
    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    static const float p[16] =
    {
        1e+0f,
        1e+1f,
        1e+2f,
        1e+3f,
        1e+4f,
        1e+5f,
        1e+6f,
        1e+7f,
        1e+8f,
        1e+9f,
        1e+10f,
        1e+11f,
        1e+12f,
        1e+13f,
        1e+14f,
        1e+15f
    };

    float t1;
    float t1i;
    float t1f;
    float t2;

    bool u;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is finite.

    if (ao_isfinited(t1))
    {
        b1 = true;
    }

    // Value is not finite.

    else
    {
        b1 = false;

        // Value is infinity.

        if (ao_isinfd(t1))
        {
            b2 = true;
            b3 = false;
        }

        // Value is not-a-number.

        else if (ao_isnand(t1))
        {
            b2 = false;
            b3 = true;
        }

        // Value is indeterminate.

        else
        {
            b2 = false;
            b3 = false;
        }
    }


    // Sign.

    // Value is finite.

    if (b1)
    {
        // Value is negative.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent digits.

            if (no_max == 1) return 0;

            no = 1;

            cs = '-';

            t1 = ao_fabsf(t1);
        }

        // Value is positive.

        else if (ao_is_positive(t1))
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                cs = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent digits.

                    if (no_max == 1) return 0;

                    no = 1;

                    cs = ' ';
                }

                else
                {
                    no = 0;
                }
            }
        }

        // Value is zero.

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                cs = ' ';
            }

            else
            {
                no = 0;
            }
        }
    }

    // Value is infinity.

    else if (b2)
    {
        // Value is negative infinity.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            cs = '-';
        }

        // Value is positive infinity.

        else
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent characters.

                if (no_max < 4) return 0;

                no = 1;

                cs = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 4) return 0;

                    no = 1;

                    cs = ' ';
                }

                else
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 3) return 0;

                    no = 0;
                }
            }
        }
    }

    // Value is not-a-number or indeterminate.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            cs = ' ';
        }

        else
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 3) return 0;

            no = 0;
        }
    }

    ns = no;


    // Value is finite.

    if (b1)
    {
        // Precision.

        np = o->precision;

        np = ao_min(np, FLT_DIG);


        // Value.

        t1i = ao_floorf(t1);

        t1f = t1 - t1i;

        t2 = (np <= 15) ? p[np] : ao_powf((float) 10, (float) np);

        t1f = t1f * t2;

        t1f = ao_roundf_half_up(t1f);

        t1 = t1f / t2;

        if (ao_is_greater_equal(t1, (float) 1))
        {
            t1i = t1i + (float) 1;

            t1 = t1 - (float) 1;

            t1f = t1 * t2;
        }


        // Integral.

        // Integral is not zero.

        if (ao_is_greater_equal(t1i, (float) 1))
        {
            t1 = ao_log10f(t1i);

            ao_assert(ao_isfinited(t1));

            t1 = ao_floorf(t1);

            ao_assert(ao_is_greater_equal(t1, (float) 0));

            ni = (size_t) t1;

            if (ni > FLT_DIG)
            {
                niv = ni - FLT_DIG;

                // Not enough space left in the string.

                if (no_max - no < niv + 1) return 0;

                for (i1 = 0; i1 < niv; i1++)
                {
                    s[no + i1] = '0';
                }

                no += niv;

                t2 = (niv <= 15) ? p[niv] : ao_powf((float) 10, (float) niv);

                t1i = t1i / t2;
            }

            else
            {
                niv = 0;
            }

            b2 = true;

            do
            {
                t2 = ao_fmodf(t1i, (float) 10);

                t1i = t1i / (float) 10;

                s[no] = '0' + (char) t2;

                no++;
                niv++;

                if (ao_is_less(t1i, (float) 1))
                {
                    b2 = false;
                }

                else
                {
                    if (no == no_max) return 0;
                }
            }
            while (b2);
        }

        // Integral is zero.

        else
        {
            // Fractional is zero.

            if (ao_is_less(t1f, (float) 1))
            {
                no = no - ns;

                ns = 0;
            }

            s[no] = '0';

            no++;

            niv = 1;
        }


        // Integral leading zeros.

        ni = o->digits_integral;

        if (ni > niv)
        {
            niz = ni - niv;

            // Not enough space left in the string.

            if (no_max - no < niz) return 0;

            for (i1 = 0; i1 < niz; i1++)
            {
                s[no + i1] = '0';
            }

            no += niz;
        }

        else
        {
            ni = niv;
        }


        // Integral reverse.

        if (ni > 1)
        {
            i1 = ns;
            i2 = ns + ni - 1;

            for (; i1 < i2; i1++, i2--)
            {
                c = s[i1];
                s[i1] = s[i2];
                s[i2] = c;
            }
        }


        // Precision is zero.

        if (np == 0)
        {
            nd = 0;

            nfv = 0;
        }

        // Precision is not zero.

        else
        {
            b2 = true;

            while (b2)
            {
                t2 = ao_fmodf(t1f, (float) 10);

                c = (char) t2;

                if (c == 0)
                {
                    t1f = t1f / (float) 10;

                    np--;

                    if (np == 0)
                    {
                        b2 = false;
                    }
                }

                else
                {
                    b2 = false;
                }
            }

            nfv = np;


            // Fractional value is zero.

            if (nfv == 0)
            {
                nd = 0;
            }

            // Fractional value is not zero.

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfv + 1) return 0;

                s[no] = '.';

                s[no + np] = '0' + c;

                for (i1 = np - 1; i1 > 0; i1--)
                {
                    t1f = t1f / (float) 10;

                    t2 = ao_fmodf(t1f, (float) 10);

                    s[no + i1] = '0' + (char) t2;
                }

                nd = 1;

                no = no + nfv + 1;
            }
        }


        nf = o->digits_fractional;

        if (nf < nfv)
        {
            nfz = 0;
            nf = nfv;
        }

        else
        {
            nfz = nf - nfv;
        }


        // Fractional trailing zeros.

        if (nfz > 0)
        {
            if (nfv == 0)
            {
                // Not enough space left in the string.

                if (no_max - no < nfz + 1) return 0;

                s[no] = '.';

                no++;

                nd = 1;
            }

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfz) return 0;
            }

            for (i1 = 0; i1 < nfz; i1++)
            {
                s[no + i1] = '0';
            }

            no += nfz;
        }
    }

    // Value is not finite.

    else
    {
        u = o->uppercase;

        // Value is infinity.

        if (b2)
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'F';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'f';
            }
        }

        // Value is not-a-number.

        else if (b3)
        {
            if (u)
            {
                s[no + 0] = 'N';
                s[no + 1] = 'A';
                s[no + 2] = 'N';
            }

            else
            {
                s[no + 0] = 'n';
                s[no + 1] = 'a';
                s[no + 2] = 'n';
            }
        }

        // Value is indeterminate.

        else
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'D';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'd';
            }
        }

        no += 3;

        ni = 3;
        nd = 0;
        nf = 0;
    }


    nn = ns + ni + nd + nf;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    if (ns == 1)
    {
        s[0] = cs;
    }


    return no;
}

size_t ao_printfl(char * s, size_t no_max, ao_print_t const * o, long double const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(v);


    // Variables.

    bool b1;
    bool b2;
    bool b3;

    char c;

    char cs;

    size_t i1;
    size_t i2;

    size_t nd;
    size_t nf;
    size_t nfv;
    size_t nfz;
    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    static const long double p[16] =
    {
        1e+0l,
        1e+1l,
        1e+2l,
        1e+3l,
        1e+4l,
        1e+5l,
        1e+6l,
        1e+7l,
        1e+8l,
        1e+9l,
        1e+10l,
        1e+11l,
        1e+12l,
        1e+13l,
        1e+14l,
        1e+15l
    };

    long double t1;
    long double t1i;
    long double t1f;
    long double t2;

    bool u;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is finite.

    if (ao_isfinited(t1))
    {
        b1 = true;
    }

    // Value is not finite.

    else
    {
        b1 = false;

        // Value is infinity.

        if (ao_isinfd(t1))
        {
            b2 = true;
            b3 = false;
        }

        // Value is not-a-number.

        else if (ao_isnand(t1))
        {
            b2 = false;
            b3 = true;
        }

        // Value is indeterminate.

        else
        {
            b2 = false;
            b3 = false;
        }
    }


    // Sign.

    // Value is finite.

    if (b1)
    {
        // Value is negative.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent digits.

            if (no_max == 1) return 0;

            no = 1;

            cs = '-';

            t1 = ao_fabsl(t1);
        }

        // Value is positive.

        else if (ao_is_positive(t1))
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                cs = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent digits.

                    if (no_max == 1) return 0;

                    no = 1;

                    cs = ' ';
                }

                else
                {
                    no = 0;
                }
            }
        }

        // Value is zero.

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string for subsequent digits.

                if (no_max == 1) return 0;

                no = 1;

                cs = ' ';
            }

            else
            {
                no = 0;
            }
        }
    }

    // Value is infinity.

    else if (b2)
    {
        // Value is negative infinity.

        if (ao_is_negative(t1))
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            cs = '-';
        }

        // Value is positive infinity.

        else
        {
            if (o->sign)
            {
                // Not enough space left in the string for subsequent characters.

                if (no_max < 4) return 0;

                no = 1;

                cs = '+';
            }

            else
            {
                if (o->sign_space)
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 4) return 0;

                    no = 1;

                    cs = ' ';
                }

                else
                {
                    // Not enough space left in the string for subsequent characters.

                    if (no_max < 3) return 0;

                    no = 0;
                }
            }
        }
    }

    // Value is not-a-number or indeterminate.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 4) return 0;

            no = 1;

            cs = ' ';
        }

        else
        {
            // Not enough space left in the string for subsequent characters.

            if (no_max < 3) return 0;

            no = 0;
        }
    }

    ns = no;


    // Value is finite.

    if (b1)
    {
        // Precision.

        np = o->precision;

        np = ao_min(np, LDBL_DIG);


        // Value.

        t1i = ao_floorl(t1);

        t1f = t1 - t1i;

        t2 = (np <= 15) ? p[np] : ao_powl((long double) 10, (long double) np);

        t1f = t1f * t2;

        t1f = ao_roundl_half_up(t1f);

        t1 = t1f / t2;

        if (ao_is_greater_equal(t1, (long double) 1))
        {
            t1i = t1i + (long double) 1;

            t1 = t1 - (long double) 1;

            t1f = t1 * t2;
        }


        // Integral.

        // Integral is not zero.

        if (ao_is_greater_equal(t1i, (long double) 1))
        {
            t1 = ao_log10l(t1i);

            ao_assert(ao_isfinited(t1));

            t1 = ao_floorl(t1);

            ao_assert(ao_is_greater_equal(t1, (long double) 0));

            ni = (size_t) t1;

            if (ni > LDBL_DIG)
            {
                niv = ni - LDBL_DIG;

                // Not enough space left in the string.

                if (no_max - no < niv + 1) return 0;

                for (i1 = 0; i1 < niv; i1++)
                {
                    s[no + i1] = '0';
                }

                no += niv;

                t2 = (niv <= 15) ? p[niv] : ao_powl((long double) 10, (long double) niv);

                t1i = t1i / t2;
            }

            else
            {
                niv = 0;
            }

            b2 = true;

            do
            {
                t2 = ao_fmodl(t1i, (long double) 10);

                t1i = t1i / (long double) 10;

                s[no] = '0' + (char) t2;

                no++;
                niv++;

                if (ao_is_less(t1i, (long double) 1))
                {
                    b2 = false;
                }

                else
                {
                    if (no == no_max) return 0;
                }
            }
            while (b2);
        }

        // Integral is zero.

        else
        {
            // Fractional is zero.

            if (ao_is_less(t1f, (long double) 1))
            {
                no = no - ns;

                ns = 0;
            }

            s[no] = '0';

            no++;

            niv = 1;
        }


        // Integral leading zeros.

        ni = o->digits_integral;

        if (ni > niv)
        {
            niz = ni - niv;

            // Not enough space left in the string.

            if (no_max - no < niz) return 0;

            for (i1 = 0; i1 < niz; i1++)
            {
                s[no + i1] = '0';
            }

            no += niz;
        }

        else
        {
            ni = niv;
        }


        // Integral reverse.

        if (ni > 1)
        {
            i1 = ns;
            i2 = ns + ni - 1;

            for (; i1 < i2; i1++, i2--)
            {
                c = s[i1];
                s[i1] = s[i2];
                s[i2] = c;
            }
        }


        // Precision is zero.

        if (np == 0)
        {
            nd = 0;

            nfv = 0;
        }

        // Precision is not zero.

        else
        {
            b2 = true;

            while (b2)
            {
                t2 = ao_fmodl(t1f, (long double) 10);

                c = (char) t2;

                if (c == 0)
                {
                    t1f = t1f / (long double) 10;

                    np--;

                    if (np == 0)
                    {
                        b2 = false;
                    }
                }

                else
                {
                    b2 = false;
                }
            }

            nfv = np;


            // Fractional value is zero.

            if (nfv == 0)
            {
                nd = 0;
            }

            // Fractional value is not zero.

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfv + 1) return 0;

                s[no] = '.';

                s[no + np] = '0' + c;

                for (i1 = np - 1; i1 > 0; i1--)
                {
                    t1f = t1f / (long double) 10;

                    t2 = ao_fmodl(t1f, (long double) 10);

                    s[no + i1] = '0' + (char) t2;
                }

                nd = 1;

                no = no + nfv + 1;
            }
        }


        nf = o->digits_fractional;

        if (nf < nfv)
        {
            nfz = 0;
            nf = nfv;
        }

        else
        {
            nfz = nf - nfv;
        }


        // Fractional trailing zeros.

        if (nfz > 0)
        {
            if (nfv == 0)
            {
                // Not enough space left in the string.

                if (no_max - no < nfz + 1) return 0;

                s[no] = '.';

                no++;

                nd = 1;
            }

            else
            {
                // Not enough space left in the string.

                if (no_max - no < nfz) return 0;
            }

            for (i1 = 0; i1 < nfz; i1++)
            {
                s[no + i1] = '0';
            }

            no += nfz;
        }
    }

    // Value is not finite.

    else
    {
        u = o->uppercase;

        // Value is infinity.

        if (b2)
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'F';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'f';
            }
        }

        // Value is not-a-number.

        else if (b3)
        {
            if (u)
            {
                s[no + 0] = 'N';
                s[no + 1] = 'A';
                s[no + 2] = 'N';
            }

            else
            {
                s[no + 0] = 'n';
                s[no + 1] = 'a';
                s[no + 2] = 'n';
            }
        }

        // Value is indeterminate.

        else
        {
            if (u)
            {
                s[no + 0] = 'I';
                s[no + 1] = 'N';
                s[no + 2] = 'D';
            }

            else
            {
                s[no + 0] = 'i';
                s[no + 1] = 'n';
                s[no + 2] = 'd';
            }
        }

        no += 3;

        ni = 3;
        nd = 0;
        nf = 0;
    }


    nn = ns + ni + nd + nf;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    if (ns == 1)
    {
        s[0] = cs;
    }


    return no;
}

// ----------------------------------------------------------------------------

size_t ao_printi8(char * s, size_t no_max, ao_print_t const * o, int8_t const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    bool b;

    char c;

    size_t i1;
    size_t i2;

    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    int8_t r;

    bool u;

    int8_t t1;
    int8_t t2;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is negative.

    if (t1 < 0)
    {
        // Not enough space left in the string.

        if (no_max == 1) return 0;

        no = 1;

        s[0] = '-';

        t1 = -t1;

        b = true;
    }

    // Value is positive.

    else if (t1 > 0)
    {
        if (o->sign)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '+';
        }

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }
        }

        b = true;
    }

    // Value is zero.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            no = 0;
        }

        b = false;
    }

    ns = no;


    // Value is not zero.

    if (b)
    {
        niv = 0;

        r = (int8_t) o->radix;

        u = o->uppercase;

        do
        {
            t2 = t1 % r;

            t1 = t1 / r;

            if (t2 < 10)
            {
                s[no] = '0' + (char) t2;
            }

            else if (u)
            {
                s[no] = 'A' + (char) t2 - 10;
            }

            else
            {
                s[no] = 'a' + (char) t2 - 10;
            }

            niv++;
            no++;

            if (t1 == 0)
            {
                b = false;
            }

            else
            {
                // Not enough space left in the string.

                if (no == no_max) return 0;
            }
        }
        while (b);
    }

    // Value is zero.

    else
    {
        s[no] = '0';

        no++;

        niv = 1;
    }


    ni = o->digits_integral;

    if (niv < ni)
    {
        niz = ni - niv;

        // Not enough space left in the string.

        if (no_max - no < niz) return 0;

        for (i1 = 0; i1 < niz; i1++)
        {
            s[no + i1] = '0';
        }

        no += niz;
    }

    else
    {
        ni = niv;
    }


    // Reverse digits.

    if (ni > 1)
    {
        i1 = ns;
        i2 = ns + ni - 1;

        for (; i1 < i2; i1++, i2--)
        {
            c = s[i1];
            s[i1] = s[i2];
            s[i2] = c;
        }
    }


    // Append leading or trailing spaces.

    nn = ns + ni;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

size_t ao_printi16(char * s, size_t no_max, ao_print_t const * o, int16_t const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    bool b;

    char c;

    size_t i1;
    size_t i2;

    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    int16_t r;

    bool u;

    int16_t t1;
    int16_t t2;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is negative.

    if (t1 < 0)
    {
        // Not enough space left in the string.

        if (no_max == 1) return 0;

        no = 1;

        s[0] = '-';

        t1 = -t1;

        b = true;
    }

    // Value is positive.

    else if (t1 > 0)
    {
        if (o->sign)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '+';
        }

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }
        }

        b = true;
    }

    // Value is zero.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            no = 0;
        }

        b = false;
    }

    ns = no;


    // Value is not zero.

    if (b)
    {
        niv = 0;

        r = (int16_t) o->radix;

        u = o->uppercase;

        do
        {
            t2 = t1 % r;

            t1 = t1 / r;

            if (t2 < 10)
            {
                s[no] = '0' + (char) t2;
            }

            else if (u)
            {
                s[no] = 'A' + (char) t2 - 10;
            }

            else
            {
                s[no] = 'a' + (char) t2 - 10;
            }

            niv++;
            no++;

            if (t1 == 0)
            {
                b = false;
            }

            else
            {
                // Not enough space left in the string.

                if (no == no_max) return 0;
            }
        }
        while (b);
    }

    // Value is zero.

    else
    {
        s[no] = '0';

        no++;

        niv = 1;
    }


    ni = o->digits_integral;

    if (niv < ni)
    {
        niz = ni - niv;

        // Not enough space left in the string.

        if (no_max - no < niz) return 0;

        for (i1 = 0; i1 < niz; i1++)
        {
            s[no + i1] = '0';
        }

        no += niz;
    }

    else
    {
        ni = niv;
    }


    // Reverse digits.

    if (ni > 1)
    {
        i1 = ns;
        i2 = ns + ni - 1;

        for (; i1 < i2; i1++, i2--)
        {
            c = s[i1];
            s[i1] = s[i2];
            s[i2] = c;
        }
    }


    // Append leading or trailing spaces.

    nn = ns + ni;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

size_t ao_printi32(char * s, size_t no_max, ao_print_t const * o, int32_t const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    bool b;

    char c;

    size_t i1;
    size_t i2;

    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    int32_t r;

    bool u;

    int32_t t1;
    int32_t t2;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is negative.

    if (t1 < 0)
    {
        // Not enough space left in the string.

        if (no_max == 1) return 0;

        no = 1;

        s[0] = '-';

        t1 = -t1;

        b = true;
    }

    // Value is positive.

    else if (t1 > 0)
    {
        if (o->sign)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '+';
        }

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }
        }

        b = true;
    }

    // Value is zero.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            no = 0;
        }

        b = false;
    }

    ns = no;


    // Value is not zero.

    if (b)
    {
        niv = 0;

        r = (int32_t) o->radix;

        u = o->uppercase;

        do
        {
            t2 = t1 % r;

            t1 = t1 / r;

            if (t2 < 10)
            {
                s[no] = '0' + (char) t2;
            }

            else if (u)
            {
                s[no] = 'A' + (char) t2 - 10;
            }

            else
            {
                s[no] = 'a' + (char) t2 - 10;
            }

            niv++;
            no++;

            if (t1 == 0)
            {
                b = false;
            }

            else
            {
                // Not enough space left in the string.

                if (no == no_max) return 0;
            }
        }
        while (b);
    }

    // Value is zero.

    else
    {
        s[no] = '0';

        no++;

        niv = 1;
    }


    ni = o->digits_integral;

    if (niv < ni)
    {
        niz = ni - niv;

        // Not enough space left in the string.

        if (no_max - no < niz) return 0;

        for (i1 = 0; i1 < niz; i1++)
        {
            s[no + i1] = '0';
        }

        no += niz;
    }

    else
    {
        ni = niv;
    }


    // Reverse digits.

    if (ni > 1)
    {
        i1 = ns;
        i2 = ns + ni - 1;

        for (; i1 < i2; i1++, i2--)
        {
            c = s[i1];
            s[i1] = s[i2];
            s[i2] = c;
        }
    }


    // Append leading or trailing spaces.

    nn = ns + ni;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

size_t ao_printi64(char * s, size_t no_max, ao_print_t const * o, int64_t const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    bool b;

    char c;

    size_t i1;
    size_t i2;

    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    int64_t r;

    bool u;

    int64_t t1;
    int64_t t2;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is negative.

    if (t1 < 0)
    {
        // Not enough space left in the string.

        if (no_max == 1) return 0;

        no = 1;

        s[0] = '-';

        t1 = -t1;

        b = true;
    }

    // Value is positive.

    else if (t1 > 0)
    {
        if (o->sign)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '+';
        }

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }
        }

        b = true;
    }

    // Value is zero.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            no = 0;
        }

        b = false;
    }

    ns = no;


    // Value is not zero.

    if (b)
    {
        niv = 0;

        r = (int64_t) o->radix;

        u = o->uppercase;

        do
        {
            t2 = t1 % r;

            t1 = t1 / r;

            if (t2 < 10)
            {
                s[no] = '0' + (char) t2;
            }

            else if (u)
            {
                s[no] = 'A' + (char) t2 - 10;
            }

            else
            {
                s[no] = 'a' + (char) t2 - 10;
            }

            niv++;
            no++;

            if (t1 == 0)
            {
                b = false;
            }

            else
            {
                // Not enough space left in the string.

                if (no == no_max) return 0;
            }
        }
        while (b);
    }

    // Value is zero.

    else
    {
        s[no] = '0';

        no++;

        niv = 1;
    }


    ni = o->digits_integral;

    if (niv < ni)
    {
        niz = ni - niv;

        // Not enough space left in the string.

        if (no_max - no < niz) return 0;

        for (i1 = 0; i1 < niz; i1++)
        {
            s[no + i1] = '0';
        }

        no += niz;
    }

    else
    {
        ni = niv;
    }


    // Reverse digits.

    if (ni > 1)
    {
        i1 = ns;
        i2 = ns + ni - 1;

        for (; i1 < i2; i1++, i2--)
        {
            c = s[i1];
            s[i1] = s[i2];
            s[i2] = c;
        }
    }


    // Append leading or trailing spaces.

    nn = ns + ni;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

// ----------------------------------------------------------------------------

size_t ao_printu8(char * s, size_t no_max, ao_print_t const * o, uint8_t const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    bool b;

    char c;

    size_t i1;
    size_t i2;

    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    uint8_t r;

    bool u;

    uint8_t t1;
    uint8_t t2;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is positive.

    if (t1 > 0)
    {
        if (o->sign)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '+';
        }

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }
        }

        b = true;
    }

    // Value is zero.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            no = 0;
        }

        b = false;
    }

    ns = no;


    // Value is not zero.

    if (b)
    {
        niv = 0;

        r = (uint8_t) o->radix;

        u = o->uppercase;

        do
        {
            t2 = t1 % r;

            t1 = t1 / r;

            if (t2 < 10)
            {
                s[no] = '0' + (char) t2;
            }

            else if (u)
            {
                s[no] = 'A' + (char) t2 - 10;
            }

            else
            {
                s[no] = 'a' + (char) t2 - 10;
            }

            niv++;
            no++;

            if (t1 == 0)
            {
                b = false;
            }

            else
            {
                // Not enough space left in the string.

                if (no == no_max) return 0;
            }
        }
        while (b);
    }

    // Value is zero.

    else
    {
        s[no] = '0';

        no++;

        niv = 1;
    }


    ni = o->digits_integral;

    if (niv < ni)
    {
        niz = ni - niv;

        // Not enough space left in the string.

        if (no_max - no < niz) return 0;

        for (i1 = 0; i1 < niz; i1++)
        {
            s[no + i1] = '0';
        }

        no += niz;
    }

    else
    {
        ni = niv;
    }


    // Reverse digits.

    if (ni > 1)
    {
        i1 = ns;
        i2 = ns + ni - 1;

        for (; i1 < i2; i1++, i2--)
        {
            c = s[i1];
            s[i1] = s[i2];
            s[i2] = c;
        }
    }


    // Append leading or trailing spaces.

    nn = ns + ni;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

size_t ao_printu16(char * s, size_t no_max, ao_print_t const * o, uint16_t const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    bool b;

    char c;

    size_t i1;
    size_t i2;

    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    uint16_t r;

    bool u;

    uint16_t t1;
    uint16_t t2;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is positive.

    if (t1 > 0)
    {
        if (o->sign)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '+';
        }

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }
        }

        b = true;
    }

    // Value is zero.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            no = 0;
        }

        b = false;
    }

    ns = no;


    // Value is not zero.

    if (b)
    {
        niv = 0;

        r = (uint16_t) o->radix;

        u = o->uppercase;

        do
        {
            t2 = t1 % r;

            t1 = t1 / r;

            if (t2 < 10)
            {
                s[no] = '0' + (char) t2;
            }

            else if (u)
            {
                s[no] = 'A' + (char) t2 - 10;
            }

            else
            {
                s[no] = 'a' + (char) t2 - 10;
            }

            niv++;
            no++;

            if (t1 == 0)
            {
                b = false;
            }

            else
            {
                // Not enough space left in the string.

                if (no == no_max) return 0;
            }
        }
        while (b);
    }

    // Value is zero.

    else
    {
        s[no] = '0';

        no++;

        niv = 1;
    }


    ni = o->digits_integral;

    if (niv < ni)
    {
        niz = ni - niv;

        // Not enough space left in the string.

        if (no_max - no < niz) return 0;

        for (i1 = 0; i1 < niz; i1++)
        {
            s[no + i1] = '0';
        }

        no += niz;
    }

    else
    {
        ni = niv;
    }


    // Reverse digits.

    if (ni > 1)
    {
        i1 = ns;
        i2 = ns + ni - 1;

        for (; i1 < i2; i1++, i2--)
        {
            c = s[i1];
            s[i1] = s[i2];
            s[i2] = c;
        }
    }


    // Append leading or trailing spaces.

    nn = ns + ni;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

size_t ao_printu32(char * s, size_t no_max, ao_print_t const * o, uint32_t const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    bool b;

    char c;

    size_t i1;
    size_t i2;

    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    uint32_t r;

    bool u;

    uint32_t t1;
    uint32_t t2;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is positive.

    if (t1 > 0)
    {
        if (o->sign)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '+';
        }

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }
        }

        b = true;
    }

    // Value is zero.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            no = 0;
        }

        b = false;
    }

    ns = no;


    // Value is not zero.

    if (b)
    {
        niv = 0;

        r = (uint32_t) o->radix;

        u = o->uppercase;

        do
        {
            t2 = t1 % r;

            t1 = t1 / r;

            if (t2 < 10)
            {
                s[no] = '0' + (char) t2;
            }

            else if (u)
            {
                s[no] = 'A' + (char) t2 - 10;
            }

            else
            {
                s[no] = 'a' + (char) t2 - 10;
            }

            niv++;
            no++;

            if (t1 == 0)
            {
                b = false;
            }

            else
            {
                // Not enough space left in the string.

                if (no == no_max) return 0;
            }
        }
        while (b);
    }

    // Value is zero.

    else
    {
        s[no] = '0';

        no++;

        niv = 1;
    }


    ni = o->digits_integral;

    if (niv < ni)
    {
        niz = ni - niv;

        // Not enough space left in the string.

        if (no_max - no < niz) return 0;

        for (i1 = 0; i1 < niz; i1++)
        {
            s[no + i1] = '0';
        }

        no += niz;
    }

    else
    {
        ni = niv;
    }


    // Reverse digits.

    if (ni > 1)
    {
        i1 = ns;
        i2 = ns + ni - 1;

        for (; i1 < i2; i1++, i2--)
        {
            c = s[i1];
            s[i1] = s[i2];
            s[i2] = c;
        }
    }


    // Append leading or trailing spaces.

    nn = ns + ni;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

size_t ao_printu64(char * s, size_t no_max, ao_print_t const * o, uint64_t const * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    bool b;

    char c;

    size_t i1;
    size_t i2;

    size_t ni;
    size_t niv;
    size_t niz;
    size_t nn;
    size_t no;
    size_t np;
    size_t ns;
    size_t nw;

    uint64_t r;

    bool u;

    uint64_t t1;
    uint64_t t2;


    // Ready.

    // Not enough space left in the string.

    if (no_max == 0) return 0;


    nw = o->width;

    // Not enough space left in the string for the minimum width.

    if (nw > no_max) return 0;

    t1 = *v;


    // Value is positive.

    if (t1 > 0)
    {
        if (o->sign)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = '+';
        }

        else
        {
            if (o->sign_space)
            {
                // Not enough space left in the string.

                if (no_max == 1) return 0;

                no = 1;

                s[0] = ' ';
            }

            else
            {
                no = 0;
            }
        }

        b = true;
    }

    // Value is zero.

    else
    {
        if (o->sign_space)
        {
            // Not enough space left in the string.

            if (no_max == 1) return 0;

            no = 1;

            s[0] = ' ';
        }

        else
        {
            no = 0;
        }

        b = false;
    }

    ns = no;


    // Value is not zero.

    if (b)
    {
        niv = 0;

        r = (uint64_t) o->radix;

        u = o->uppercase;

        do
        {
            t2 = t1 % r;

            t1 = t1 / r;

            if (t2 < 10)
            {
                s[no] = '0' + (char) t2;
            }

            else if (u)
            {
                s[no] = 'A' + (char) t2 - 10;
            }

            else
            {
                s[no] = 'a' + (char) t2 - 10;
            }

            niv++;
            no++;

            if (t1 == 0)
            {
                b = false;
            }

            else
            {
                // Not enough space left in the string.

                if (no == no_max) return 0;
            }
        }
        while (b);
    }

    // Value is zero.

    else
    {
        s[no] = '0';

        no++;

        niv = 1;
    }


    ni = o->digits_integral;

    if (niv < ni)
    {
        niz = ni - niv;

        // Not enough space left in the string.

        if (no_max - no < niz) return 0;

        for (i1 = 0; i1 < niz; i1++)
        {
            s[no + i1] = '0';
        }

        no += niz;
    }

    else
    {
        ni = niv;
    }


    // Reverse digits.

    if (ni > 1)
    {
        i1 = ns;
        i2 = ns + ni - 1;

        for (; i1 < i2; i1++, i2--)
        {
            c = s[i1];
            s[i1] = s[i2];
            s[i2] = c;
        }
    }


    // Append leading or trailing spaces.

    nn = ns + ni;

    if (nn < nw)
    {
        np = nw - nn;

        if (o->right)
        {
            i1 = nn;

            do
            {
                i1--;

                s[i1 + np] = s[i1];
            }
            while (i1 > 0);

            no += np;

            while (np > 0)
            {
                np--;

                s[np] = ' ';
            }
        }

        else
        {
            while (np > 0)
            {
                s[no] = ' ';

                no++;
                np--;
            }
        }
    }


    return no;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RB

// ----------------------------------------------------------------------------

static  size_t          ao_rb_assert_node(  ao_rb_t * X, ao_rb_node_t * N);

// ----------------------------------------------------------------------------

static  bool            ao_rb_is_black(     ao_rb_node_t * N);

// ----------------------------------------------------------------------------

static  void            ao_rb_rotate_left(  ao_rb_t * X, ao_rb_node_t * N);

static  void            ao_rb_rotate_right( ao_rb_t * X, ao_rb_node_t * N);

// ----------------------------------------------------------------------------

static  ao_rb_node_t *  ao_rb_successor(    ao_rb_node_t * N);

// ----------------------------------------------------------------------------

static  void            ao_rb_swap(         ao_rb_t * X, ao_rb_node_t * N1, ao_rb_node_t * N2);

// ----------------------------------------------------------------------------

void ao_rb_assert(ao_rb_t * X)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->less);


    // Variables.

    ao_rb_node_t * N;


    // Ready.

    N = X->root;

    if (N)
    {
        ao_assert(!N->parent);

        ao_rb_assert_node(X, N);
    }
}

size_t ao_rb_assert_node(ao_rb_t * X, ao_rb_node_t * N)
{
    // Variables.

    size_t BL;

    size_t BN;

    size_t BR;

    ao_rb_node_t * L;

    ao_rb_node_t * R;


    // Ready.

    BN = N->black ? 1 : 0;

    L = N->left;

    R = N->right;

    if (L)
    {
        ao_assert(N == L->parent);

        ao_assert(X->less(L, N, X->less_parameter));

        if (R)
        {
            ao_assert(N == R->parent);

            ao_assert(X->less(N, R, X->less_parameter));

            BL = ao_rb_assert_node(X, L);

            BR = ao_rb_assert_node(X, R);

            ao_assert(BL == BR);

            if (BN)
            {
                return BL + 1;
            }

            else
            {
                ao_assert(L->black);

                ao_assert(R->black);

                return BL;
            }
        }

        else
        {
            if (BN)
            {
                return ao_rb_assert_node(X, L) + 1;
            }

            else
            {
                ao_assert(L->black);

                return ao_rb_assert_node(X, L);
            }
        }
    }

    else
    {
        if (R)
        {
            ao_assert(N == R->parent);

            ao_assert(X->less(N, R, X->less_parameter));

            if (BN)
            {
                return ao_rb_assert_node(X, R) + 1;
            }

            else
            {
                ao_assert(R->black);

                return ao_rb_assert_node(X, R);
            }
        }

        else
        {
            return BN;
        }
    }
}

void ao_rb_insert(ao_rb_t * X, ao_rb_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->less);

    ao_assert(N);

    ao_assert(!N->parent);

    ao_assert(!N->left);

    ao_assert(!N->right);


    // Variables.

    bool B1;

    bool B2;

    ao_rb_node_t * C;

    ao_rb_node_t * G;

    ao_rb_less_t Less = X->less;

    void * LessParameter = X->less_parameter;

    ao_rb_node_t * P;

    ao_rb_node_t * U;


    // Ready.

    // Traverse.

    P = NULL;

    C = X->root;

    while (C)
    {
        P = C;

        B1 = Less(N, P, LessParameter);

        C = B1 ? P->left : P->right;
    }


    // Parent exists.

    if (P)
    {
        // Insert node in red.

        if (B1)
        {
            P->left = N;
        }

        else
        {
            P->right = N;
        }

        N->black = false;

        N->parent = P;


        // Fix if parent is red.

        B2 = !P->black;

        while (B2)
        {
            // Parent exists.

            // Parent is red.

            ao_assert(P);

            ao_assert(!P->black);


            // Grandparent exists.

            G = P->parent;

            if (G)
            {
                // Grandparent is black.

                ao_assert(G->black);


                // Uncle.

                if (P == G->left)
                {
                    B1 = true;

                    U = G->right;
                }

                else
                {
                    B1 = false;

                    U = G->left;
                }


                // Uncle is red.

                if (U && !U->black)
                {
                    // Color parent and uncle black.

                    // Color grandparent red.

                    P->black = true;

                    U->black = true;

                    G->black = false;


                    // Continue fixing, if grandparent's parent is red.

                    N = G;

                    P = N->parent;

                    if (P && !P->black)
                    {
                        B2 = true;
                    }

                    else
                    {
                        B2 = false;
                    }
                }


                // Uncle is black.

                else
                {
                    // Parent is left child of grandparent.

                    if (B1)
                    {
                        if (N == P->right)
                        {
                            ao_rb_rotate_left(X, P);

                            P = N;
                        }

                        ao_rb_rotate_right(X, G);
                    }


                    // Parent is right child of grandparent.

                    else
                    {
                        if (N == P->left)
                        {
                            ao_rb_rotate_right(X, P);

                            P = N;
                        }

                        ao_rb_rotate_left(X, G);
                    }


                    // Color parent black.

                    // Color grandparent red.

                    P->black = true;

                    G->black = false;

                    B2 = false;
                }
            }


            // Grandparent exists not.

            else
            {
                // Parent is the root.

                // Color parent black and stop fixing.

                ao_assert(P == X->root);

                P->black = true;

                B2 = false;
            }
        }
    }


    // Parent exists not.

    // Tree is empty.

    else
    {
        X->root = N;
    }
}

bool ao_rb_is_black(ao_rb_node_t * N)
{
    return N ? N->black : true;
}

ao_rb_node_t * ao_rb_max(ao_rb_t * X)
{
    // Assert.

    ao_assert(X);


    // Variables.

    ao_rb_node_t * N = X->root;


    // Ready.

    if (N)
    {
        while (N->right)
        {
            N = N->right;
        }
    }

    return N;
}

ao_rb_node_t * ao_rb_min(ao_rb_t * X)
{
    // Assert.

    ao_assert(X);


    // Variables.

    ao_rb_node_t * N = X->root;


    // Ready.

    if (N)
    {
        while (N->left)
        {
            N = N->left;
        }
    }

    return N;
}

void ao_rb_remove(ao_rb_t * X, ao_rb_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->root);

    ao_assert(N);


    // Variables.

    bool B;

    ao_rb_node_t * L;

    ao_rb_node_t * P;

    ao_rb_node_t * R;

    ao_rb_node_t * S;

    ao_rb_node_t * SL;

    ao_rb_node_t * SR;


    // Ready.

    // Node has two children.

    // Swap node with its in-order successor.

    L = N->left;

    R = N->right;

    if (L && R)
    {
        R = ao_rb_successor(N);

        ao_rb_swap(X, N, R);

        L = N->left;

        R = N->right;
    }


    // Node has at most one child.

    ao_assert(!L || !R);


    // Parent exists.

    P = N->parent;

    if (P)
    {
        // Remove.

        if (N == P->left)
        {
            B = true;

            if (L)
            {
                P->left = L;

                L->parent = P;

                N->left = NULL;
            }

            else if (R)
            {
                P->left = R;

                R->parent = P;

                N->right = NULL;
            }

            else
            {
                P->left = NULL;
            }
        }

        else
        {
            B = false;

            if (L)
            {
                P->right = L;

                L->parent = P;

                N->left = NULL;
            }

            else if (R)
            {
                P->right = R;

                R->parent = P;

                N->right = NULL;
            }

            else
            {
                P->right = NULL;
            }
        }

        N->parent = NULL;


        // Fix if the removed node is black.

        if (N->black)
        {
            // Sibling.

            S = B ? P->right : P->left;


            // Fix.

            do
            {
                // Sibling exists.

                ao_assert(S);


                // Sibling is red.

                if (!S->black)
                {
                    // Color sibling black.

                    // Color parent red.

                    S->black = true;

                    P->black = false;


                    // Rotate around parent.

                    if (B)
                    {
                        S = S->left;

                        ao_rb_rotate_left(X, P);
                    }

                    else
                    {
                        S = S->right;

                        ao_rb_rotate_right(X, P);
                    }
                }


                // Sibling exists.

                // Sibling is black.

                ao_assert(S);

                ao_assert(S->black);


                // Sibling has two black children.

                if
                (
                    ao_rb_is_black(S->left) &&
                    ao_rb_is_black(S->right)
                )
                {
                    // Color sibling red.

                    S->black = false;


                    // Parent is black.

                    if (P->black)
                    {
                        N = P;

                        P = N->parent;

                        if (P)
                        {
                            if (N == P->left)
                            {
                                B = true;

                                S = P->right;
                            }

                            else
                            {
                                B = false;

                                S = P->left;
                            }
                        }
                    }


                    // Parent is red.

                    else
                    {
                        P->black = true;

                        P = NULL;
                    }
                }


                // Sibling has at least one red child.

                else
                {
                    // Node is left child and sibling's right child is black.

                    if (B && ao_rb_is_black(S->right))
                    {
                        // Sibling's left child.

                        SL = S->left;


                        // Sibling's left child exists.

                        // Sibling's left child is red.

                        ao_assert(SL);

                        ao_assert(!SL->black);


                        // Color sibling red.

                        // Color sibling's left child black.

                        S->black = false;

                        SL->black = true;


                        // Rotate right around sibling.

                        ao_rb_rotate_right(X, S);


                        // Sibling.

                        S = SL;
                    }


                    // Node is right child and sibling's left child is black.

                    else if (!B && ao_rb_is_black(S->left))
                    {
                        // Sibling's right child.

                        SR = S->right;


                        // Sibling's right child exists.

                        // Sibling's right child is red.

                        ao_assert(SR);

                        ao_assert(!SR->black);


                        // Color sibling red.

                        // Color sibling's right child black.

                        S->black = false;

                        SR->black = true;


                        // Rotate left around sibling.

                        ao_rb_rotate_left(X, S);


                        // Sibling.

                        S = SR;
                    }


                    // Sibling exists.

                    // Sibling is black.

                    ao_assert(S);

                    ao_assert(S->black);


                    // Color sibling like parent.

                    // Color parent black.

                    S->black = P->black;

                    P->black = true;


                    // Node is left child.

                    if (B)
                    {
                        // Color sibling's right child black.

                        ao_assert(S->right);

                        S->right->black = true;


                        // Rotate left around parent.

                        ao_rb_rotate_left(X, P);
                    }


                    // Node is right child.

                    else
                    {
                        // Color sibling's left child black.

                        ao_assert(S->left);

                        S->left->black = true;


                        // Rotate right around parent.

                        ao_rb_rotate_right(X, P);
                    }


                    // Fixing is done.

                    P = NULL;
                }
            }
            while (P);
        }
    }


    // Parent exists not.

    // The root is to be removed.

    else
    {
        ao_assert(N == X->root);

        if (L)
        {
            X->root = L;

            L->parent = NULL;

            N->left = NULL;
        }

        else if (R)
        {
            X->root = R;

            R->parent = NULL;

            N->right = NULL;
        }

        else
        {
            X->root = NULL;
        }
    }
}

void ao_rb_rotate_left(ao_rb_t * X, ao_rb_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(N);

    ao_assert(N->right);


    // Variables.

    ao_rb_node_t * P;

    ao_rb_node_t ** P2N;

    ao_rb_node_t * R;

    ao_rb_node_t * RL;


    // Ready.

    P = N->parent;

    if (P)
    {
        if (P->left == N)
        {
            P2N = &P->left;
        }

        else
        {
            P2N = &P->right;
        }
    }

    else
    {
        P2N = &X->root;
    }

    R = N->right;

    RL = R->left;

    if (RL)
    {
        RL->parent = N;
    }

    N->right = RL;

    N->parent = R;

    R->left = N;

    R->parent = P;

    *P2N = R;
}

void ao_rb_rotate_right( ao_rb_t * X, ao_rb_node_t * N)
{
    // Assert.

    ao_assert(X);

    ao_assert(N);

    ao_assert(N->left);


    // Variables.

    ao_rb_node_t * L;

    ao_rb_node_t * LR;

    ao_rb_node_t * P;

    ao_rb_node_t ** P2N;


    // Ready.

    P = N->parent;

    if (P)
    {
        if (P->left == N)
        {
            P2N = &P->left;
        }

        else
        {
            P2N = &P->right;
        }
    }

    else
    {
        P2N = &X->root;
    }

    L = N->left;

    LR = L->right;

    if (LR)
    {
        LR->parent = N;
    }

    N->left = LR;

    N->parent = L;

    L->right = N;

    L->parent = P;

    *P2N = L;
}

ao_rb_node_t * ao_rb_successor(ao_rb_node_t * N)
{
    ao_assert(N);

    N = N->right;

    if (N)
    {
        while (N->left)
        {
            N = N->left;
        }
    }

    return N;
}

void ao_rb_swap(ao_rb_t * X, ao_rb_node_t * N1, ao_rb_node_t * N2)
{
    // Assert.

    ao_assert(X);

    ao_assert(N1);

    ao_assert(N2);


    // Variables.

    bool B;

    ao_rb_node_t * C1;

    ao_rb_node_t * C2;

    ao_rb_node_t * P1;

    ao_rb_node_t * P2;

    ao_rb_node_t ** P2N1;

    ao_rb_node_t ** P2N2;


    // Ready.

    // Parent.

    P1 = N1->parent;

    P2 = N2->parent;

    N1->parent = P2;

    N2->parent = P1;

    if (P1)
    {
        if (P1->left == N1)
        {
            P2N1 = &P1->left;
        }

        else
        {
            P2N1 = &P1->right;
        }
    }

    else
    {
        P2N1 = &X->root;
    }

    if (P2)
    {
        if (P2->left == N2)
        {
            P2N2 = &P2->left;
        }

        else
        {
            P2N2 = &P2->right;
        }
    }

    else
    {
        P2N2 = &X->root;
    }

    *P2N1 = N2;

    *P2N2 = N1;


    // Left.

    C1 = N1->left;

    C2 = N2->left;

    N1->left = C2;

    N2->left = C1;

    if (C1)
    {
        C1->parent = N2;
    }

    if (C2)
    {
        C2->parent = N1;
    }


    // Right.

    C1 = N1->right;

    C2 = N2->right;

    N1->right = C2;

    N2->right = C1;

    if (C1)
    {
        C1->parent = N2;
    }

    if (C2)
    {
        C2->parent = N1;
    }


    // Black.

    B = N1->black;

    N1->black = N2->black;

    N2->black = B;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SCAN

// ----------------------------------------------------------------------------

size_t ao_scanfd(char const * s, size_t ni_max, ao_scan_t const * o, double * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(v);


    // Variables.

    bool b1;
    bool b2;

    char c;

    bool me;
    bool ms;

    size_t ni;
    size_t nie;

    uint_fast16_t ve1;
    uint_fast16_t ve2;

    double vs;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;


    // Seek.

    if (o->seek)
    {
        b2 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('-' == c)              ||
                ('.' == c)              ||
                ('0' <= c && c <= '9')
            )
            {
                b2 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b2);
    }


    // Significant sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;

        ms = false;
    }

    else if (c == '-')
    {
        ni++;

        if (ni == ni_max) return 0;

        ms = true;
    }

    else
    {
        ms = false;
    }


    // Significant value.

    c = s[ni];

    if ('0' <= c && c <= '9')
    {
        b1 = true;
    }

    else if (c == '.')
    {
        b1 = false;

        ni++;

        vs = (double) 0;
    }

    else
    {
        return 0;
    }


    // Significant integral.

    if (b1)
    {
        vs = (double) (c - '0');

        ni++;

        if (ni < ni_max)
        {
            b2 = true;

            do
            {
                c = s[ni];

                if ('0' <= c && c <= '9')
                {
                    vs = (double) 10 * vs + (double) (c - '0');

                    ni++;

                    if (ni == ni_max)
                    {
                        b2 = false;
                    }
                }

                else
                {
                    b2 = false;
                }
            }
            while (b2);
        }

        if (ni < ni_max)
        {
            c = s[ni];

            if (c == '.')
            {
                b1 = true;

                ni++;
            }

            else
            {
                b1 = false;
            }
        }

        else
        {
            b1 = false;
        }
    }

    else
    {
        b1 = true;
    }


    // Significant fractional.

    if (b1)
    {
        if (ni < ni_max)
        {
            c = s[ni];

            if ('0' <= c && c <= '9')
            {
                vs = (double) 10 * vs + (double) (c - '0');

                ve1 = 1;

                ni++;

                if (ni < ni_max)
                {
                    b2 = true;

                    do
                    {
                        c = s[ni];

                        if ('0' <= c && c <= '9')
                        {
                            vs = (double) 10 * vs + (double) (c - '0');

                            ve1++;

                            ni++;

                            if (ni == ni_max)
                            {
                                b2 = false;
                            }
                        }

                        else
                        {
                            b2 = false;
                        }
                    }
                    while (b2);
                }
            }

            else
            {
                ve1 = 0;
            }
        }

        else
        {
            ve1 = 0;
        }
    }

    else
    {
        ve1 = 0;
    }


    // Exponent.

    if (ni < ni_max)
    {
        c = s[ni];

        if (c == 'e' || c == 'E')
        {
            nie = ni;

            nie++;

            if (nie < ni_max)
            {
                // Exponent sign.

                c = s[nie];

                if (c == '+')
                {
                    nie++;

                    if (nie < ni_max)
                    {
                        me = false;
                    }

                    else
                    {
                        b1 = false;
                    }
                }

                else if (c == '-')
                {
                    nie++;

                    if (nie < ni_max)
                    {
                        me = true;
                    }

                    else
                    {
                        b1 = false;
                    }
                }

                else
                {
                    b1 = true;

                    me = false;
                }

                if (b1)
                {
                    // Exponent integral.

                    c = s[nie];

                    if ('0' <= c && c <= '9')
                    {
                        ve2 = (uint_fast16_t) (c - '0');

                        nie++;

                        if (nie < ni_max)
                        {
                            b2 = true;

                            do
                            {
                                c = s[nie];

                                if ('0' <= c && c <= '9')
                                {
                                    ve2 = 10 * ve2 + (uint_fast16_t) (c - '0');

                                    nie++;

                                    if (nie == ni_max)
                                    {
                                        b2 = false;
                                    }
                                }

                                else
                                {
                                    b2 = false;
                                }
                            }
                            while (b2);
                        }
                    }

                    else
                    {
                        b1 = false;
                    }
                }
            }

            else
            {
                b1 = false;
            }
        }

        else
        {
            b1 = false;

            nie = 0;
        }
    }

    else
    {
        b1 = false;

        nie = 0;
    }


    if (b1)
    {
        if (me)
        {
            ve1 = ve1 + ve2;
            ve2 = 0;
        }

        else
        {
            if (ve1 > ve2)
            {
                ve1 = ve1 - ve2;
                ve2 = 0;
            }

            else
            {
                ve2 = ve2 - ve1;
                ve1 = 0;

                while (ve2 > 0)
                {
                    vs = vs * (double) 10;

                    ve2--;
                }
            }
        }
    }

    while (ve1 > 0)
    {
        vs = vs * (double) 0.1;

        ve1--;
    }

    if (ms)
    {
        vs = -vs;
    }

    *v = vs;


    return b1 ? nie : ni;
}

size_t ao_scanff(char const * s, size_t ni_max, ao_scan_t const * o, float * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(v);


    // Variables.

    bool b1;
    bool b2;

    char c;

    bool me;
    bool ms;

    size_t ni;
    size_t nie;

    uint_fast16_t ve1;
    uint_fast16_t ve2;

    float vs;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;


    // Seek.

    if (o->seek)
    {
        b2 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('-' == c)              ||
                ('.' == c)              ||
                ('0' <= c && c <= '9')
            )
            {
                b2 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b2);
    }


    // Significant sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;

        ms = false;
    }

    else if (c == '-')
    {
        ni++;

        if (ni == ni_max) return 0;

        ms = true;
    }

    else
    {
        ms = false;
    }


    // Significant value.

    c = s[ni];

    if ('0' <= c && c <= '9')
    {
        b1 = true;
    }

    else if (c == '.')
    {
        b1 = false;

        ni++;

        vs = (float) 0;
    }

    else
    {
        return 0;
    }


    // Significant integral.

    if (b1)
    {
        vs = (float) (c - '0');

        ni++;

        if (ni < ni_max)
        {
            b2 = true;

            do
            {
                c = s[ni];

                if ('0' <= c && c <= '9')
                {
                    vs = (float) 10 * vs + (float) (c - '0');

                    ni++;

                    if (ni == ni_max)
                    {
                        b2 = false;
                    }
                }

                else
                {
                    b2 = false;
                }
            }
            while (b2);
        }

        if (ni < ni_max)
        {
            c = s[ni];

            if (c == '.')
            {
                b1 = true;

                ni++;
            }

            else
            {
                b1 = false;
            }
        }

        else
        {
            b1 = false;
        }
    }

    else
    {
        b1 = true;
    }


    // Significant fractional.

    if (b1)
    {
        if (ni < ni_max)
        {
            c = s[ni];

            if ('0' <= c && c <= '9')
            {
                vs = (float) 10 * vs + (float) (c - '0');

                ve1 = 1;

                ni++;

                if (ni < ni_max)
                {
                    b2 = true;

                    do
                    {
                        c = s[ni];

                        if ('0' <= c && c <= '9')
                        {
                            vs = (float) 10 * vs + (float) (c - '0');

                            ve1++;

                            ni++;

                            if (ni == ni_max)
                            {
                                b2 = false;
                            }
                        }

                        else
                        {
                            b2 = false;
                        }
                    }
                    while (b2);
                }
            }

            else
            {
                ve1 = 0;
            }
        }

        else
        {
            ve1 = 0;
        }
    }

    else
    {
        ve1 = 0;
    }


    // Exponent.

    if (ni < ni_max)
    {
        c = s[ni];

        if (c == 'e' || c == 'E')
        {
            nie = ni;

            nie++;

            if (nie < ni_max)
            {
                // Exponent sign.

                c = s[nie];

                if (c == '+')
                {
                    nie++;

                    if (nie < ni_max)
                    {
                        me = false;
                    }

                    else
                    {
                        b1 = false;
                    }
                }

                else if (c == '-')
                {
                    nie++;

                    if (nie < ni_max)
                    {
                        me = true;
                    }

                    else
                    {
                        b1 = false;
                    }
                }

                else
                {
                    b1 = true;

                    me = false;
                }

                if (b1)
                {
                    // Exponent integral.

                    c = s[nie];

                    if ('0' <= c && c <= '9')
                    {
                        ve2 = (uint_fast16_t) (c - '0');

                        nie++;

                        if (nie < ni_max)
                        {
                            b2 = true;

                            do
                            {
                                c = s[nie];

                                if ('0' <= c && c <= '9')
                                {
                                    ve2 = 10 * ve2 + (uint_fast16_t) (c - '0');

                                    nie++;

                                    if (nie == ni_max)
                                    {
                                        b2 = false;
                                    }
                                }

                                else
                                {
                                    b2 = false;
                                }
                            }
                            while (b2);
                        }
                    }

                    else
                    {
                        b1 = false;
                    }
                }
            }

            else
            {
                b1 = false;
            }
        }

        else
        {
            b1 = false;

            nie = 0;
        }
    }

    else
    {
        b1 = false;

        nie = 0;
    }


    if (b1)
    {
        if (me)
        {
            ve1 = ve1 + ve2;
            ve2 = 0;
        }

        else
        {
            if (ve1 > ve2)
            {
                ve1 = ve1 - ve2;
                ve2 = 0;
            }

            else
            {
                ve2 = ve2 - ve1;
                ve1 = 0;

                while (ve2 > 0)
                {
                    vs = vs * (float) 10;

                    ve2--;
                }
            }
        }
    }

    while (ve1 > 0)
    {
        vs = vs * (float) 0.1;

        ve1--;
    }

    if (ms)
    {
        vs = -vs;
    }

    *v = vs;


    return b1 ? nie : ni;
}

size_t ao_scanfl(char const * s, size_t ni_max, ao_scan_t const * o, long double * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(v);


    // Variables.

    bool b1;
    bool b2;

    char c;

    bool me;
    bool ms;

    size_t ni;
    size_t nie;

    uint_fast16_t ve1;
    uint_fast16_t ve2;

    long double vs;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;


    // Seek.

    if (o->seek)
    {
        b2 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('-' == c)              ||
                ('.' == c)              ||
                ('0' <= c && c <= '9')
            )
            {
                b2 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b2);
    }


    // Significant sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;

        ms = false;
    }

    else if (c == '-')
    {
        ni++;

        if (ni == ni_max) return 0;

        ms = true;
    }

    else
    {
        ms = false;
    }


    // Significant value.

    c = s[ni];

    if ('0' <= c && c <= '9')
    {
        b1 = true;
    }

    else if (c == '.')
    {
        b1 = false;

        ni++;

        vs = (long double) 0;
    }

    else
    {
        return 0;
    }


    // Significant integral.

    if (b1)
    {
        vs = (long double) (c - '0');

        ni++;

        if (ni < ni_max)
        {
            b2 = true;

            do
            {
                c = s[ni];

                if ('0' <= c && c <= '9')
                {
                    vs = (long double) 10 * vs + (long double) (c - '0');

                    ni++;

                    if (ni == ni_max)
                    {
                        b2 = false;
                    }
                }

                else
                {
                    b2 = false;
                }
            }
            while (b2);
        }

        if (ni < ni_max)
        {
            c = s[ni];

            if (c == '.')
            {
                b1 = true;

                ni++;
            }

            else
            {
                b1 = false;
            }
        }

        else
        {
            b1 = false;
        }
    }

    else
    {
        b1 = true;
    }


    // Significant fractional.

    if (b1)
    {
        if (ni < ni_max)
        {
            c = s[ni];

            if ('0' <= c && c <= '9')
            {
                vs = (long double) 10 * vs + (long double) (c - '0');

                ve1 = 1;

                ni++;

                if (ni < ni_max)
                {
                    b2 = true;

                    do
                    {
                        c = s[ni];

                        if ('0' <= c && c <= '9')
                        {
                            vs = (long double) 10 * vs + (long double) (c - '0');

                            ve1++;

                            ni++;

                            if (ni == ni_max)
                            {
                                b2 = false;
                            }
                        }

                        else
                        {
                            b2 = false;
                        }
                    }
                    while (b2);
                }
            }

            else
            {
                ve1 = 0;
            }
        }

        else
        {
            ve1 = 0;
        }
    }

    else
    {
        ve1 = 0;
    }


    // Exponent.

    if (ni < ni_max)
    {
        c = s[ni];

        if (c == 'e' || c == 'E')
        {
            nie = ni;

            nie++;

            if (nie < ni_max)
            {
                // Exponent sign.

                c = s[nie];

                if (c == '+')
                {
                    nie++;

                    if (nie < ni_max)
                    {
                        me = false;
                    }

                    else
                    {
                        b1 = false;
                    }
                }

                else if (c == '-')
                {
                    nie++;

                    if (nie < ni_max)
                    {
                        me = true;
                    }

                    else
                    {
                        b1 = false;
                    }
                }

                else
                {
                    b1 = true;

                    me = false;
                }

                if (b1)
                {
                    // Exponent integral.

                    c = s[nie];

                    if ('0' <= c && c <= '9')
                    {
                        ve2 = (uint_fast16_t) (c - '0');

                        nie++;

                        if (nie < ni_max)
                        {
                            b2 = true;

                            do
                            {
                                c = s[nie];

                                if ('0' <= c && c <= '9')
                                {
                                    ve2 = 10 * ve2 + (uint_fast16_t) (c - '0');

                                    nie++;

                                    if (nie == ni_max)
                                    {
                                        b2 = false;
                                    }
                                }

                                else
                                {
                                    b2 = false;
                                }
                            }
                            while (b2);
                        }
                    }

                    else
                    {
                        b1 = false;
                    }
                }
            }

            else
            {
                b1 = false;
            }
        }

        else
        {
            b1 = false;

            nie = 0;
        }
    }

    else
    {
        b1 = false;

        nie = 0;
    }


    if (b1)
    {
        if (me)
        {
            ve1 = ve1 + ve2;
            ve2 = 0;
        }

        else
        {
            if (ve1 > ve2)
            {
                ve1 = ve1 - ve2;
                ve2 = 0;
            }

            else
            {
                ve2 = ve2 - ve1;
                ve1 = 0;

                while (ve2 > 0)
                {
                    vs = vs * (long double) 10;

                    ve2--;
                }
            }
        }
    }

    while (ve1 > 0)
    {
        vs = vs * (long double) 0.1;

        ve1--;
    }

    if (ms)
    {
        vs = -vs;
    }

    *v = vs;


    return b1 ? nie : ni;
}

// ----------------------------------------------------------------------------

size_t ao_scani8(char const * s, size_t ni_max, ao_scan_t const * o, int8_t * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    char c;
    char cd;
    char cl;
    char cL;

    bool b1;
    bool b2;

    bool m;

    size_t ni;

    int8_t r;

    int8_t v1;
    int8_t v2;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;

    r = o->radix;

    cd = '0' + r - 1;
    cl = 'a' + r - 11;
    cL = 'A' + r - 11;

    cd = ao_min(cd, '9');


    // Seek.

    if (o->seek)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('-' == c)              ||
                ('0' <= c && c <= cd)   ||
                ('a' <= c && c <= cl)   ||
                ('A' <= c && c <= cL)
            )
            {
                b1 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b1);
    }


    // Sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;

        m = false;
    }

    else if (c == '-')
    {
        ni++;

        if (ni == ni_max) return 0;

        m = true;
    }

    else
    {
        m = false;
    }


    // Value.

    c = s[ni];

    if ('0' <= c && c <= cd)
    {
        v1 = (int8_t) (c - '0');
    }

    else if ('a' <= c && c <= cl)
    {
        v1 = (int8_t) (c - 'a') + 10;
    }

    else if ('A' <= c && c <= cL)
    {
        v1 = (int8_t) (c - 'A') + 10;
    }

    else
    {
        return 0;
    }

    ni++;

    if (ni < ni_max)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if ('0' <= c && c <= cd)
            {
                b2 = true;

                v2 = (int8_t) (c - '0');
            }

            else if ('a' <= c && c <= cl)
            {
                b2 = true;

                v2 = (int8_t) (c - 'a') + 10;
            }

            else if ('A' <= c && c <= cL)
            {
                b2 = true;

                v2 = (int8_t) (c - 'A') + 10;
            }

            else
            {
                b2 = false;
            }

            if (b2)
            {
                v1 = v1 * r + v2;

                ni++;

                if (ni == ni_max)
                {
                    b1 = false;
                }
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);
    }

    if (m)
    {
        v1 = -v1;
    }

    *v = v1;


    return ni;
}

size_t ao_scani16(char const * s, size_t ni_max, ao_scan_t const * o, int16_t * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    char c;
    char cd;
    char cl;
    char cL;

    bool b1;
    bool b2;

    bool m;

    size_t ni;

    int16_t r;

    int16_t v1;
    int16_t v2;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;

    r = o->radix;

    cd = '0' + r - 1;
    cl = 'a' + r - 11;
    cL = 'A' + r - 11;

    cd = ao_min(cd, '9');


    // Seek.

    if (o->seek)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('-' == c)              ||
                ('0' <= c && c <= cd)   ||
                ('a' <= c && c <= cl)   ||
                ('A' <= c && c <= cL)
            )
            {
                b1 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b1);
    }


    // Sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;

        m = false;
    }

    else if (c == '-')
    {
        ni++;

        if (ni == ni_max) return 0;

        m = true;
    }

    else
    {
        m = false;
    }


    // Value.

    c = s[ni];

    if ('0' <= c && c <= cd)
    {
        v1 = (int16_t) (c - '0');
    }

    else if ('a' <= c && c <= cl)
    {
        v1 = (int16_t) (c - 'a') + 10;
    }

    else if ('A' <= c && c <= cL)
    {
        v1 = (int16_t) (c - 'A') + 10;
    }

    else
    {
        return 0;
    }

    ni++;

    if (ni < ni_max)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if ('0' <= c && c <= cd)
            {
                b2 = true;

                v2 = (int16_t) (c - '0');
            }

            else if ('a' <= c && c <= cl)
            {
                b2 = true;

                v2 = (int16_t) (c - 'a') + 10;
            }

            else if ('A' <= c && c <= cL)
            {
                b2 = true;

                v2 = (int16_t) (c - 'A') + 10;
            }

            else
            {
                b2 = false;
            }

            if (b2)
            {
                v1 = v1 * r + v2;

                ni++;

                if (ni == ni_max)
                {
                    b1 = false;
                }
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);
    }

    if (m)
    {
        v1 = -v1;
    }

    *v = v1;


    return ni;
}

size_t ao_scani32(char const * s, size_t ni_max, ao_scan_t const * o, int32_t * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    char c;
    char cd;
    char cl;
    char cL;

    bool b1;
    bool b2;

    bool m;

    size_t ni;

    int32_t r;

    int32_t v1;
    int32_t v2;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;

    r = o->radix;

    cd = '0' + r - 1;
    cl = 'a' + r - 11;
    cL = 'A' + r - 11;

    cd = ao_min(cd, '9');


    // Seek.

    if (o->seek)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('-' == c)              ||
                ('0' <= c && c <= cd)   ||
                ('a' <= c && c <= cl)   ||
                ('A' <= c && c <= cL)
            )
            {
                b1 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b1);
    }


    // Sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;

        m = false;
    }

    else if (c == '-')
    {
        ni++;

        if (ni == ni_max) return 0;

        m = true;
    }

    else
    {
        m = false;
    }


    // Value.

    c = s[ni];

    if ('0' <= c && c <= cd)
    {
        v1 = (int32_t) (c - '0');
    }

    else if ('a' <= c && c <= cl)
    {
        v1 = (int32_t) (c - 'a') + 10;
    }

    else if ('A' <= c && c <= cL)
    {
        v1 = (int32_t) (c - 'A') + 10;
    }

    else
    {
        return 0;
    }

    ni++;

    if (ni < ni_max)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if ('0' <= c && c <= cd)
            {
                b2 = true;

                v2 = (int32_t) (c - '0');
            }

            else if ('a' <= c && c <= cl)
            {
                b2 = true;

                v2 = (int32_t) (c - 'a') + 10;
            }

            else if ('A' <= c && c <= cL)
            {
                b2 = true;

                v2 = (int32_t) (c - 'A') + 10;
            }

            else
            {
                b2 = false;
            }

            if (b2)
            {
                v1 = v1 * r + v2;

                ni++;

                if (ni == ni_max)
                {
                    b1 = false;
                }
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);
    }

    if (m)
    {
        v1 = -v1;
    }

    *v = v1;


    return ni;
}

size_t ao_scani64(char const * s, size_t ni_max, ao_scan_t const * o, int64_t * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    char c;
    char cd;
    char cl;
    char cL;

    bool b1;
    bool b2;

    bool m;

    size_t ni;

    int64_t r;

    int64_t v1;
    int64_t v2;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;

    r = o->radix;

    cd = '0' + r - 1;
    cl = 'a' + r - 11;
    cL = 'A' + r - 11;

    cd = ao_min(cd, '9');


    // Seek.

    if (o->seek)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('-' == c)              ||
                ('0' <= c && c <= cd)   ||
                ('a' <= c && c <= cl)   ||
                ('A' <= c && c <= cL)
            )
            {
                b1 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b1);
    }


    // Sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;

        m = false;
    }

    else if (c == '-')
    {
        ni++;

        if (ni == ni_max) return 0;

        m = true;
    }

    else
    {
        m = false;
    }


    // Value.

    c = s[ni];

    if ('0' <= c && c <= cd)
    {
        v1 = (int64_t) (c - '0');
    }

    else if ('a' <= c && c <= cl)
    {
        v1 = (int64_t) (c - 'a') + 10;
    }

    else if ('A' <= c && c <= cL)
    {
        v1 = (int64_t) (c - 'A') + 10;
    }

    else
    {
        return 0;
    }

    ni++;

    if (ni < ni_max)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if ('0' <= c && c <= cd)
            {
                b2 = true;

                v2 = (int64_t) (c - '0');
            }

            else if ('a' <= c && c <= cl)
            {
                b2 = true;

                v2 = (int64_t) (c - 'a') + 10;
            }

            else if ('A' <= c && c <= cL)
            {
                b2 = true;

                v2 = (int64_t) (c - 'A') + 10;
            }

            else
            {
                b2 = false;
            }

            if (b2)
            {
                v1 = v1 * r + v2;

                ni++;

                if (ni == ni_max)
                {
                    b1 = false;
                }
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);
    }

    if (m)
    {
        v1 = -v1;
    }

    *v = v1;


    return ni;
}

// ----------------------------------------------------------------------------

size_t ao_scanu8(char const * s, size_t ni_max, ao_scan_t const * o, uint8_t * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    char c;
    char cd;
    char cl;
    char cL;

    bool b1;
    bool b2;

    size_t ni;

    uint8_t r;

    uint8_t v1;
    uint8_t v2;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;

    r = o->radix;

    cd = '0' + r - 1;
    cl = 'a' + r - 11;
    cL = 'A' + r - 11;

    cd = ao_min(cd, '9');


    // Seek.

    if (o->seek)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('0' <= c && c <= cd)   ||
                ('a' <= c && c <= cl)   ||
                ('A' <= c && c <= cL)
            )
            {
                b1 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b1);
    }


    // Sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;
    }


    // Value.

    c = s[ni];

    if ('0' <= c && c <= cd)
    {
        v1 = (uint8_t) (c - '0');
    }

    else if ('a' <= c && c <= cl)
    {
        v1 = (uint8_t) (c - 'a') + 10;
    }

    else if ('A' <= c && c <= cL)
    {
        v1 = (uint8_t) (c - 'A') + 10;
    }

    else
    {
        return 0;
    }

    ni++;

    if (ni < ni_max)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if ('0' <= c && c <= cd)
            {
                b2 = true;

                v2 = (uint8_t) (c - '0');
            }

            else if ('a' <= c && c <= cl)
            {
                b2 = true;

                v2 = (uint8_t) (c - 'a') + 10;
            }

            else if ('A' <= c && c <= cL)
            {
                b2 = true;

                v2 = (uint8_t) (c - 'A') + 10;
            }

            else
            {
                b2 = false;
            }

            if (b2)
            {
                v1 = v1 * r + v2;

                ni++;

                if (ni == ni_max)
                {
                    b1 = false;
                }
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);
    }

    *v = v1;


    return ni;
}

size_t ao_scanu16(char const * s, size_t ni_max, ao_scan_t const * o, uint16_t * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    char c;
    char cd;
    char cl;
    char cL;

    bool b1;
    bool b2;

    size_t ni;

    uint16_t r;

    uint16_t v1;
    uint16_t v2;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;

    r = o->radix;

    cd = '0' + r - 1;
    cl = 'a' + r - 11;
    cL = 'A' + r - 11;

    cd = ao_min(cd, '9');


    // Seek.

    if (o->seek)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('0' <= c && c <= cd)   ||
                ('a' <= c && c <= cl)   ||
                ('A' <= c && c <= cL)
            )
            {
                b1 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b1);
    }


    // Sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;
    }


    // Value.

    c = s[ni];

    if ('0' <= c && c <= cd)
    {
        v1 = (uint16_t) (c - '0');
    }

    else if ('a' <= c && c <= cl)
    {
        v1 = (uint16_t) (c - 'a') + 10;
    }

    else if ('A' <= c && c <= cL)
    {
        v1 = (uint16_t) (c - 'A') + 10;
    }

    else
    {
        return 0;
    }

    ni++;

    if (ni < ni_max)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if ('0' <= c && c <= cd)
            {
                b2 = true;

                v2 = (uint16_t) (c - '0');
            }

            else if ('a' <= c && c <= cl)
            {
                b2 = true;

                v2 = (uint16_t) (c - 'a') + 10;
            }

            else if ('A' <= c && c <= cL)
            {
                b2 = true;

                v2 = (uint16_t) (c - 'A') + 10;
            }

            else
            {
                b2 = false;
            }

            if (b2)
            {
                v1 = v1 * r + v2;

                ni++;

                if (ni == ni_max)
                {
                    b1 = false;
                }
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);
    }

    *v = v1;


    return ni;
}

size_t ao_scanu32(char const * s, size_t ni_max, ao_scan_t const * o, uint32_t * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    char c;
    char cd;
    char cl;
    char cL;

    bool b1;
    bool b2;

    size_t ni;

    uint32_t r;

    uint32_t v1;
    uint32_t v2;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;

    r = o->radix;

    cd = '0' + r - 1;
    cl = 'a' + r - 11;
    cL = 'A' + r - 11;

    cd = ao_min(cd, '9');


    // Seek.

    if (o->seek)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('0' <= c && c <= cd)   ||
                ('a' <= c && c <= cl)   ||
                ('A' <= c && c <= cL)
            )
            {
                b1 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b1);
    }


    // Sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;
    }


    // Value.

    c = s[ni];

    if ('0' <= c && c <= cd)
    {
        v1 = (uint32_t) (c - '0');
    }

    else if ('a' <= c && c <= cl)
    {
        v1 = (uint32_t) (c - 'a') + 10;
    }

    else if ('A' <= c && c <= cL)
    {
        v1 = (uint32_t) (c - 'A') + 10;
    }

    else
    {
        return 0;
    }

    ni++;

    if (ni < ni_max)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if ('0' <= c && c <= cd)
            {
                b2 = true;

                v2 = (uint32_t) (c - '0');
            }

            else if ('a' <= c && c <= cl)
            {
                b2 = true;

                v2 = (uint32_t) (c - 'a') + 10;
            }

            else if ('A' <= c && c <= cL)
            {
                b2 = true;

                v2 = (uint32_t) (c - 'A') + 10;
            }

            else
            {
                b2 = false;
            }

            if (b2)
            {
                v1 = v1 * r + v2;

                ni++;

                if (ni == ni_max)
                {
                    b1 = false;
                }
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);
    }

    *v = v1;


    return ni;
}

size_t ao_scanu64(char const * s, size_t ni_max, ao_scan_t const * o, uint64_t * v)
{
    // Assert.

    ao_assert(s);

    ao_assert(o);

    ao_assert(o->radix > 0);

    ao_assert(v);


    // Variables.

    char c;
    char cd;
    char cl;
    char cL;

    bool b1;
    bool b2;

    size_t ni;

    uint64_t r;

    uint64_t v1;
    uint64_t v2;


    // Ready.

    if (ni_max == 0) return 0;

    ni = 0;

    r = o->radix;

    cd = '0' + r - 1;
    cl = 'a' + r - 11;
    cL = 'A' + r - 11;

    cd = ao_min(cd, '9');


    // Seek.

    if (o->seek)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if (c == '\0') return 0;

            if
            (
                ('+' == c)              ||
                ('0' <= c && c <= cd)   ||
                ('a' <= c && c <= cl)   ||
                ('A' <= c && c <= cL)
            )
            {
                b1 = false;
            }

            else
            {
                ni++;

                if (ni == ni_max) return 0;
            }
        }
        while (b1);
    }


    // Sign.

    c = s[ni];

    if (c == '+')
    {
        ni++;

        if (ni == ni_max) return 0;
    }


    // Value.

    c = s[ni];

    if ('0' <= c && c <= cd)
    {
        v1 = (uint64_t) (c - '0');
    }

    else if ('a' <= c && c <= cl)
    {
        v1 = (uint64_t) (c - 'a') + 10;
    }

    else if ('A' <= c && c <= cL)
    {
        v1 = (uint64_t) (c - 'A') + 10;
    }

    else
    {
        return 0;
    }

    ni++;

    if (ni < ni_max)
    {
        b1 = true;

        do
        {
            c = s[ni];

            if ('0' <= c && c <= cd)
            {
                b2 = true;

                v2 = (uint64_t) (c - '0');
            }

            else if ('a' <= c && c <= cl)
            {
                b2 = true;

                v2 = (uint64_t) (c - 'a') + 10;
            }

            else if ('A' <= c && c <= cL)
            {
                b2 = true;

                v2 = (uint64_t) (c - 'A') + 10;
            }

            else
            {
                b2 = false;
            }

            if (b2)
            {
                v1 = v1 * r + v2;

                ni++;

                if (ni == ni_max)
                {
                    b1 = false;
                }
            }

            else
            {
                b1 = false;
            }
        }
        while (b1);
    }

    *v = v1;


    return ni;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SLIST

// ----------------------------------------------------------------------------

void ao_slist_assert(ao_slist_t * X)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->less);


    // Variables.

    ao_slist_less_t Less = X->less;

    void * LessParameter = X->less_parameter;

    ao_slist_node_t * N1;

    ao_slist_node_t * N2;


    // Ready.

    N1 = X->front;

    while (N1)
    {
        N2 = N1->next;

        if (N2)
        {
            if (Less(N1, N2, LessParameter)) { }

            else
            {
                ao_assert(false);
            }
        }

        N1 = N2;
    }
}

// ----------------------------------------------------------------------------

void ao_slist_insert(ao_slist_t * X, ao_slist_node_t * N2)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->less);

    ao_assert(N2);

    ao_assert(!N2->next);

    ao_assert(!N2->prev);


    // Variables.

    ao_slist_less_t Less = X->less;

    void * LessParameter = X->less_parameter;

    ao_slist_node_t * N1;

    ao_slist_node_t * N3;


    // Ready.

    N1 = NULL;

    N3 = X->front;

    while (N3 && !Less(N2, N3, LessParameter))
    {
        N1 = N3;

        N3 = N3->next;
    }

    if (N1)
    {
        N1->next = N2;

        N2->prev = N1;
    }

    else
    {
        X->front = N2;
    }

    if (N3)
    {
        N2->next = N3;

        N3->prev = N2;
    }

    else
    {
        X->back = N2;
    }
}

// ----------------------------------------------------------------------------

ao_slist_node_t * ao_slist_pop_back(ao_slist_t * X)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->front);

    ao_assert(X->back);


    // Variables.

    ao_slist_node_t * N1;

    ao_slist_node_t * N2;


    // Ready.

    N2 = X->back;

    N1 = N2->prev;

    if (N1)
    {
        N1->next = NULL;

        N2->prev = NULL;
    }

    else
    {
        X->front = NULL;
    }

    X->back = N1;

    return N2;
}

ao_slist_node_t * ao_slist_pop_front(ao_slist_t * X)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->front);

    ao_assert(X->back);


    // Variables.

    ao_slist_node_t * N1;

    ao_slist_node_t * N2;


    // Ready.

    N1 = X->front;

    N2 = N1->next;

    if (N2)
    {
        N1->next = NULL;

        N2->prev = NULL;
    }

    else
    {
        X->back = NULL;
    }

    X->front = N2;

    return N1;
}

// ----------------------------------------------------------------------------

void ao_slist_remove(ao_slist_t * X, ao_slist_node_t * N2)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->front);

    ao_assert(X->back);

    ao_assert(N2);


    // Variables.

    ao_slist_node_t * N1;

    ao_slist_node_t * N3;


    // Ready.

    N1 = N2->prev;

    N3 = N2->next;

    if (N1)
    {
        N1->next = N3;

        N2->prev = NULL;
    }

    else
    {
        X->front = N3;
    }

    if (N3)
    {
        N2->next = NULL;

        N3->prev = N1;
    }

    else
    {
        X->back = N1;
    }
}

void ao_slist_remove_all(ao_slist_t * X)
{
    // Assert.

    ao_assert(X);


    // Variables.

    ao_slist_node_t * N1;

    ao_slist_node_t * N2;


    // Ready.

    N1 = X->front;

    while (N1)
    {
        N2 = N1->next;

        N1->next = NULL;

        N1->prev = NULL;

        N1 = N2;
    }

    X->front = NULL;

    X->back  = NULL;
}

void ao_slist_remove_back(ao_slist_t * X)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->front);

    ao_assert(X->back);


    // Variables.

    ao_slist_node_t * N1;

    ao_slist_node_t * N2;


    // Ready.

    N2 = X->back;

    N1 = N2->prev;

    if (N1)
    {
        N1->next = NULL;

        N2->prev = NULL;
    }

    else
    {
        X->front = NULL;
    }

    X->back = N1;
}

void ao_slist_remove_front(ao_slist_t * X)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->front);

    ao_assert(X->back);


    // Variables.

    ao_slist_node_t * N1;

    ao_slist_node_t * N2;


    // Ready.

    N1 = X->front;

    N2 = N1->next;

    if (N2)
    {
        N1->next = NULL;

        N2->prev = NULL;
    }

    else
    {
        X->back = NULL;
    }

    X->front = N2;
}

// ----------------------------------------------------------------------------

void ao_slist_update(ao_slist_t * X, ao_slist_node_t * N)
{
    ao_slist_remove(X, N);

    ao_slist_insert(X, N);
}

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------
