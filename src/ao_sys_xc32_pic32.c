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
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/kmem.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#if defined AO_STACK

// ----------------------------------------------------------------------------

static  void *  ao_stack_get_beginning( void const * ptr);

static  void *  ao_stack_get_end(       void const * ptr, size_t size);

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32

#if defined AO_IR

// ----------------------------------------------------------------------------

        ao_ir_stack_t   ao_ir_stack                                 __attribute__ ((used));

static  uint8_t         ao_ir_stack_store[AO_IR_STACK_SIZE_ALIGNED] __attribute__ ((used, aligned(AO_STACK_ALIGN)));

// ----------------------------------------------------------------------------

void ao_boot_ir_stack()
{
    uint8_t * sp;

    sp = ao_ir_stack_store;

    sp = sp + AO_IR_STACK_SIZE_ALIGNED;

    sp = sp - AO_IR_STACK_SIZE_AS;

    ao_ir_stack.sp = (uint32_t) sp;

#if AO_IR_STACK_FILL

    ao_stack_fill
    (
        (void *) ao_ir_stack_store,
        (size_t) AO_IR_STACK_SIZE_ALIGNED
    );

#endif

}

// ----------------------------------------------------------------------------

__attribute__ ((naked))
void * ao_ir_stack_func0(ao_func0_t func)
{
    // Variables.

    (void) func;


    // Ready.

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = &ao_ir_stack

    asm volatile ("la $k0, ao_ir_stack");

    // k1 = ao_ir_stack.depth

    asm volatile ("lw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // if (k1 != 0) then goto 1

    asm volatile ("bne $k1, $zero, 1f");

    // k1++

    asm volatile ("addiu $k1, $k1, 1");

    // ao_ir_stack.sp_backup = sp

    asm volatile ("sw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp_backup)));

    // ao_ir_stack.fp_backup = s8

    asm volatile ("sw $s8, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, fp_backup)));

    // sp = ao_ir_stack.sp

    asm volatile ("lw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp)));

    // s8 = sp

    asm volatile ("addu $s8, $sp, $zero");

    asm volatile ("1:");

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

#if AO_IR_STACK_DEPTH_MAX

    // sp -= 8

    asm volatile ("addiu $sp, $sp, -8");

    // Save s0.

    asm volatile ("sw $s0, 0($sp)");

    // s0 = ao_ir_stack.depth_max

    asm volatile ("lw $s0, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    // s0 = s0 - k1

    asm volatile ("subu $s0, $s0, $k1");

    // if (s0 >= 0) then goto 1

    asm volatile ("bgez $s0, 1f");
    asm volatile ("nop");

    // ao_ir_stack.depth_max = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    asm volatile ("1:");

    // Restore s0.

    asm volatile ("lw $s0, 0($sp)");

    // sp += 8

    asm volatile ("addiu $sp, $sp, 8");

#endif

    // Enable interrupts.

    asm volatile ("ei");
    asm volatile ("nop");

    // Save ra.

    asm volatile ("sw $ra, 20($sp)");

    // Execute.

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jalr $a0");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Restore ra.

    asm volatile ("lw $ra, 20($sp)");

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = &ao_ir_stack

    asm volatile ("la $k0, ao_ir_stack");

    // k1 = ao_ir_stack.depth

    asm volatile ("lw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // k1--

    asm volatile ("addiu $k1, $k1, -1");

    // if (k1 != 0) then goto 1

    asm volatile ("bne $k1, $zero, 1f");

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // sp = ao_ir_stack.sp_backup

    asm volatile ("lw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp_backup)));

    // s8 = ao_ir_stack.fp_backup

    asm volatile ("lw $s8, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, fp_backup)));

    asm volatile ("1:");

    // Enable interrupts.

    asm volatile ("ei");
    asm volatile ("nop");

    // Return.

    asm volatile ("jr $ra");
    asm volatile ("nop");

    asm volatile (".set reorder");
    asm volatile (".set at");
}

__attribute__ ((naked))
void * ao_ir_stack_func1(void * param1, ao_func1_t func)
{
    // Variables.

    (void) param1;

    (void) func;


    // Ready.

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = &ao_ir_stack

    asm volatile ("la $k0, ao_ir_stack");

    // k1 = ao_ir_stack.depth

    asm volatile ("lw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // if (k1 != 0) then goto 1

    asm volatile ("bne $k1, $zero, 1f");

    // k1++

    asm volatile ("addiu $k1, $k1, 1");

    // ao_ir_stack.sp_backup = sp

    asm volatile ("sw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp_backup)));

    // ao_ir_stack.fp_backup = s8

    asm volatile ("sw $s8, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, fp_backup)));

    // sp = ao_ir_stack.sp

    asm volatile ("lw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp)));

    // s8 = sp

    asm volatile ("addu $s8, $sp, $zero");

    asm volatile ("1:");

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

#if AO_IR_STACK_DEPTH_MAX

    // sp -= 8

    asm volatile ("addiu $sp, $sp, -8");

    // Save s0.

    asm volatile ("sw $s0, 0($sp)");

    // s0 = ao_ir_stack.depth_max

    asm volatile ("lw $s0, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    // s0 = s0 - k1

    asm volatile ("subu $s0, $s0, $k1");

    // if (s0 >= 0) then goto 1

    asm volatile ("bgez $s0, 1f");
    asm volatile ("nop");

    // ao_ir_stack.depth_max = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    asm volatile ("1:");

    // Restore s0.

    asm volatile ("lw $s0, 0($sp)");

    // sp += 8

    asm volatile ("addiu $sp, $sp, 8");

#endif

    // Enable interrupts.

    asm volatile ("ei");
    asm volatile ("nop");

    // Save ra.

    asm volatile ("sw $ra, 20($sp)");

    // Execute.

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jalr $a1");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Restore ra.

    asm volatile ("lw $ra, 20($sp)");

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = &ao_ir_stack

    asm volatile ("la $k0, ao_ir_stack");

    // k1 = ao_ir_stack.depth

    asm volatile ("lw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // k1--

    asm volatile ("addiu $k1, $k1, -1");

    // if (k1 != 0) then goto 1

    asm volatile ("bne $k1, $zero, 1f");

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // sp = ao_ir_stack.sp_backup

    asm volatile ("lw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp_backup)));

    // s8 = ao_ir_stack.fp_backup

    asm volatile ("lw $s8, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, fp_backup)));

    asm volatile ("1:");

    // Enable interrupts.

    asm volatile ("ei");
    asm volatile ("nop");

    // Return.

    asm volatile ("jr $ra");
    asm volatile ("nop");

    asm volatile (".set reorder");
    asm volatile (".set at");
}

__attribute__ ((naked))
void * ao_ir_stack_func2(void * param1, void * param2, ao_func2_t func)
{
    // Variables.

    (void) param1;

    (void) param2;

    (void) func;


    // Ready.

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = &ao_ir_stack

    asm volatile ("la $k0, ao_ir_stack");

    // k1 = ao_ir_stack.depth

    asm volatile ("lw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // if (k1 != 0) then goto 1

    asm volatile ("bne $k1, $zero, 1f");

    // k1++

    asm volatile ("addiu $k1, $k1, 1");

    // ao_ir_stack.sp_backup = sp

    asm volatile ("sw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp_backup)));

    // ao_ir_stack.fp_backup = s8

    asm volatile ("sw $s8, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, fp_backup)));

    // sp = ao_ir_stack.sp

    asm volatile ("lw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp)));

    // s8 = sp

    asm volatile ("addu $s8, $sp, $zero");

    asm volatile ("1:");

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

#if AO_IR_STACK_DEPTH_MAX

    // sp -= 8

    asm volatile ("addiu $sp, $sp, -8");

    // Save s0.

    asm volatile ("sw $s0, 0($sp)");

    // s0 = ao_ir_stack.depth_max

    asm volatile ("lw $s0, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    // s0 = s0 - k1

    asm volatile ("subu $s0, $s0, $k1");

    // if (s0 >= 0) then goto 1

    asm volatile ("bgez $s0, 1f");
    asm volatile ("nop");

    // ao_ir_stack.depth_max = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    asm volatile ("1:");

    // Restore s0.

    asm volatile ("lw $s0, 0($sp)");

    // sp += 8

    asm volatile ("addiu $sp, $sp, 8");

#endif

    // Enable interrupts.

    asm volatile ("ei");
    asm volatile ("nop");

    // Save ra.

    asm volatile ("sw $ra, 20($sp)");

    // Execute.

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jalr $a2");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Restore ra.

    asm volatile ("lw $ra, 20($sp)");

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = &ao_ir_stack

    asm volatile ("la $k0, ao_ir_stack");

    // k1 = ao_ir_stack.depth

    asm volatile ("lw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // k1--

    asm volatile ("addiu $k1, $k1, -1");

    // if (k1 != 0) then goto 1

    asm volatile ("bne $k1, $zero, 1f");

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // sp = ao_ir_stack.sp_backup

    asm volatile ("lw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp_backup)));

    // s8 = ao_ir_stack.fp_backup

    asm volatile ("lw $s8, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, fp_backup)));

    asm volatile ("1:");

    // Enable interrupts.

    asm volatile ("ei");
    asm volatile ("nop");

    // Return.

    asm volatile ("jr $ra");
    asm volatile ("nop");

    asm volatile (".set reorder");
    asm volatile (".set at");
}

__attribute__ ((naked))
void * ao_ir_stack_func3(void * param1, void * param2, void * param3, ao_func3_t func)
{
    // Variables.

    (void) param1;

    (void) param2;

    (void) param3;

    (void) func;


    // Ready.

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = &ao_ir_stack

    asm volatile ("la $k0, ao_ir_stack");

    // k1 = ao_ir_stack.depth

    asm volatile ("lw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // if (k1 != 0) then goto 1

    asm volatile ("bne $k1, $zero, 1f");

    // k1++

    asm volatile ("addiu $k1, $k1, 1");

    // ao_ir_stack.sp_backup = sp

    asm volatile ("sw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp_backup)));

    // ao_ir_stack.fp_backup = s8

    asm volatile ("sw $s8, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, fp_backup)));

    // sp = ao_ir_stack.sp

    asm volatile ("lw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp)));

    // s8 = sp

    asm volatile ("addu $s8, $sp, $zero");

    asm volatile ("1:");

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

#if AO_IR_STACK_DEPTH_MAX

    // sp -= 8

    asm volatile ("addiu $sp, $sp, -8");

    // Save s0.

    asm volatile ("sw $s0, 0($sp)");

    // s0 = ao_ir_stack.depth_max

    asm volatile ("lw $s0, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    // s0 = s0 - k1

    asm volatile ("subu $s0, $s0, $k1");

    // if (s0 >= 0) then goto 1

    asm volatile ("bgez $s0, 1f");
    asm volatile ("nop");

    // ao_ir_stack.depth_max = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    asm volatile ("1:");

    // Restore s0.

    asm volatile ("lw $s0, 0($sp)");

    // sp += 8

    asm volatile ("addiu $sp, $sp, 8");

#endif

    // Enable interrupts,

    asm volatile ("ei");
    asm volatile ("nop");

    // Save ra.

    asm volatile ("sw $ra, 20($sp)");

    // Execute.

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jalr $a3");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Restore ra.

    asm volatile ("lw $ra, 20($sp)");

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = &ao_ir_stack

    asm volatile ("la $k0, ao_ir_stack");

    // k1 = ao_ir_stack.depth

    asm volatile ("lw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // k1--

    asm volatile ("addiu $k1, $k1, -1");

    // if (k1 != 0) then goto 1

    asm volatile ("bne $k1, $zero, 1f");

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // sp = ao_ir_stack.sp_backup

    asm volatile ("lw $sp, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, sp_backup)));

    // s8 = ao_ir_stack.fp_backup

    asm volatile ("lw $s8, %0($k0)" :: "K" (offsetof(ao_ir_stack_t, fp_backup)));

    asm volatile ("1:");

    // Enable interrupts.

    asm volatile ("ei");
    asm volatile ("nop");

    // Return.

    asm volatile ("jr $ra");
    asm volatile ("nop");

    asm volatile (".set reorder");
    asm volatile (".set at");
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_IR && AO_IR_STACK_FILL

// ----------------------------------------------------------------------------

void ao_ir_stack_high_water_mark()
{
    ao_ir_stack.high_water_mark = ao_stack_get_high_water_mark
    (
        (void *) ao_ir_stack_store,
        (size_t) AO_IR_STACK_SIZE_ALIGNED
    );
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_STACK

// ----------------------------------------------------------------------------

void ao_stack_fill(void * p, size_t s)
{
    // Variables.

    uint32_t * b;

    uint32_t * e;


    // Ready.

    if (p)
    {
        b = ao_stack_get_beginning(p);

        e = ao_stack_get_end(p, s);

        for (; b < e; b++)
        {
            *b = AO_STACK_FILL;
        }
    }
}

void * ao_stack_get_beginning(void const * p)
{
    uintptr_t t1 = (uintptr_t) p;

    uintptr_t t2 = ao_align_up(t1, AO_STACK_ALIGN);

    return (void *) t2;
}

void * ao_stack_get_end(void const * p, size_t s)
{
    uintptr_t t1 = (uintptr_t) p;

    uintptr_t t2 = (uintptr_t) s;

    uintptr_t t3 = t1 + t2;

    uintptr_t t4 = ao_align_down(t3, AO_STACK_ALIGN);

    return (void *) t4;
}

size_t ao_stack_get_high_water_mark(void const * p, size_t s)
{
    // Variables.

    uint32_t * b;

    uint32_t * e;


    // Ready.

    if (p)
    {
        b = ao_stack_get_beginning(p);

        e = ao_stack_get_end(p, s);

        if (b < e)
        {
            while (1)
            {
                if (*b == AO_STACK_FILL)
                {
                    b++;

                    if (b == e)
                    {
                        return 0;
                    }
                }

                else
                {
                    return sizeof(uint32_t) * (size_t) (e - b);
                }
            }
        }

        else
        {
            return 0;
        }
    }

    else
    {
        return 0;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_sys_idle()
{
    ao_sys_wait_idle();
    ao_sys_wait();
}

// ----------------------------------------------------------------------------

void ao_sys_lock_device(ao_sys_lock_device_t * x)
{
    ao_assert(x);

    SYSKEY = 0x0;

    ao_sys_unlock_dma(x->dma);

    ao_sys_unlock_ie(x->ie);
}

uint32_t ao_sys_lock_dma()
{
    // DMA controller is suspended.

    uint32_t x = DMACON & _DMACON_SUSPEND_MASK;

    if (x) { }

    // DMA controller is not suspended.

    else
    {
        DMACONSET = _DMACON_SUSPEND_MASK;

#ifdef _DMACON_DMABUSY_MASK

        // Family Reference Manual.

        // Section 31.4.5.

        // The DMACON.DMABUSY bit is not available on all devices.

        while (DMACONbits.DMABUSY) { }

#endif

    }

    return x;
}

// ----------------------------------------------------------------------------

__attribute__ ((noreturn))
void ao_sys_reset()
{
    // Variables.

    uint32_t volatile d;

    ao_sys_lock_device_t l;


    // Ready.

    ao_sys_unlock_device(&l);
    {
        RSWRSTbits.SWRST = 1;

        d = RSWRST;

        while (1) { }
    }
    ao_sys_lock_device(&l);
}

// ----------------------------------------------------------------------------

void ao_sys_sleep()
{
    ao_sys_wait_sleep();
    ao_sys_wait();
}

// ----------------------------------------------------------------------------

void ao_sys_unlock_device(ao_sys_lock_device_t * x)
{
    ao_assert(x);

    x->ie = ao_sys_lock_ie();

    x->dma = ao_sys_lock_dma();

    // First, make sure that the device is actually locked.

    SYSKEY = 0x0;

    // Then, perform the unlock sequence.

    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
}

void ao_sys_unlock_dma(uint32_t x)
{
    if (x) { }

    else
    {
        DMACONCLR = _DMACON_SUSPEND_MASK;
    }
}

// ----------------------------------------------------------------------------

void ao_sys_wait()
{
    // Notes.

    // In the following, we save the return address before the wait and restore
    // it afterwards. Here's why.

    // If we use the watchdog timer (WDT) to wake up the device, then following
    // a WDT timeout event, a non-maskable interrupt (NMI) is generated, that
    // vectors execution to the CPU start-up address.

    // The NMI saves the PC to ErrorEPC
    // and sets both Status.ERL and Status.NMI.

    // At the CPU start-up address, there's the _reset() function.
    // The following roughly demonstrates what's going on from there,
    // after a WDT timeout event in idle or sleep mode.


    // _reset:

    // jal _startup
    // nop


    // _startup:

    // if (Status.NMI)
    // {
    //   jr _nmi_handler
    //   nop
    // }


    // _nmi_handler:

    // eret


    // The eret instructions restores the PC from ErrorEPC, because Status.ERL
    // is set.

    // As a result, the CPU continues execution with the instruction following
    // the wait instruction.

    // Obviously, after the wait the value of the return address register (ra)
    // has changed, because the _reset() function executed a jal instruction,
    // which writes the ra register.


    // Ready.

    // directives
    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // sp -= 8
    asm volatile ("addiu $sp, $sp, -8");

    // save ra
    asm volatile ("sw $ra, 0($sp)");

    // wait
    asm volatile ("wait");

    // restore ra
    asm volatile ("lw $ra, 0($sp)");

    // sp += 8
    asm volatile ("addiu $sp, $sp, 8");

    // directives
    asm volatile (".set reorder");
    asm volatile (".set at");
}

void ao_sys_wait_idle()
{
    ao_sys_lock_device_t l;

    ao_sys_unlock_device(&l);
    {
        OSCCONCLR = _OSCCON_SLPEN_MASK;
    }
    ao_sys_lock_device(&l);
}

void ao_sys_wait_sleep()
{
    ao_sys_lock_device_t l;

    ao_sys_unlock_device(&l);
    {
        OSCCONSET = _OSCCON_SLPEN_MASK;
    }
    ao_sys_lock_device(&l);
}

// ----------------------------------------------------------------------------

#endif

#endif

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32MK

#if defined AO_ALARM

// ----------------------------------------------------------------------------

AO_IR_CT_ATTRIBUTE
void ao_ir_ct()
{
    ao_ir_stack_func0((ao_func0_t) ao_alarm);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_sys_lock_pps(ao_sys_lock_pps_t * x)
{
    ao_assert(x);

    uint32_t t1 = x->io & _CFGCON_IOLOCK_MASK;

    uint32_t t2 = CFGCON & ~_CFGCON_IOLOCK_MASK;

    CFGCON = t1 | t2;

    ao_sys_lock_device(&x->device);
}

void ao_sys_unlock_pps(ao_sys_lock_pps_t * x)
{
    ao_assert(x);

    ao_sys_unlock_device(&x->device);

    uint32_t i = CFGCON;

    CFGCON = i & ~_CFGCON_IOLOCK_MASK;

    x->io = i;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK

// ----------------------------------------------------------------------------

static  void    ao_task_stack_check();

// ----------------------------------------------------------------------------

AO_IR_CS1_ATTRIBUTE
void ao_ir_cs1()
{
    // Prolog.

    // Interrupts are disabled, because Status.EXL == 1.

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Make room for the context.

    asm volatile ("addiu $sp, $sp, -%0" :: "K" (sizeof(ao_task_context_data_t)));

    // Save s0.
    // Save s1.
    // Save s2.
    // Save s3.
    // Save s8.

    asm volatile ("sw $s0, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s0)));
    asm volatile ("sw $s1, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s1)));
    asm volatile ("sw $s2, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s2)));
    asm volatile ("sw $s3, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s3)));
    asm volatile ("sw $s8, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s8)));

    // s1 = sp

    asm volatile ("addu $s1, $sp, $zero");

    // Switch to the interrupt stack.

    // We can safely use k0 and k1, because interrupts are disabled.

    // s0 = &ao_ir_stack

    asm volatile ("la $s0, ao_ir_stack");

    // k1 = 1

    asm volatile ("addiu $k1, $zero, 1");

    // sp = ao_ir_stack.sp

    asm volatile ("lw $sp, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, sp)));

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // s8 = sp

    asm volatile ("addu $s8, $sp, $zero");

#if AO_IR_STACK_DEPTH_MAX

    // k0 = ao_ir_stack.depth_max

    asm volatile ("lw $k0, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    // k0 = k0 - 1

    asm volatile ("addiu $k0, $k0, -1");

    // if (k0 >= 0) then goto 1

    asm volatile ("bgez $k0, 1f");
    asm volatile ("nop");

    // ao_ir_stack.depth_max = k1

    asm volatile ("sw $k1, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    asm volatile ("1:");

#endif

    // k1 = EPC

    asm volatile ("mfc0 $k1, $%0, %1" :: "K" (_CP0_EPC), "K" (_CP0_EPC_SELECT));

    // k0 = Status

    asm volatile ("mfc0 $k0, $%0, %1" :: "K" (_CP0_STATUS), "K" (_CP0_STATUS_SELECT));

    // Save EPC.

    asm volatile ("sw $k1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, epc)));

    // Save Status.

    asm volatile ("sw $k0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, status)));

    // Manipulate the Status value contained in k0.

    // Status.IPL = AO_IR_CS1_PRIO
    // Status.EXL = 0
    // Status.ERL = 0
    // Status.UM  = 0

    // k1 = AO_IR_CS1_PRIO

    asm volatile ("addiu $k1, $zero, %0" :: "K" (AO_IR_CS1_PRIO));

    // k0.IPL = k1

    asm volatile ("ins $k0, $k1, %0, %1" :: "K" (_CP0_STATUS_IPL_POSITION), "K" (_CP0_STATUS_IPL_LENGTH));

    // k0.EXL = 0
    // k0.ERL = 0
    // k0.UM  = 0

    asm volatile ("ins $k0, $zero, %0, %1" :: "K" (_CP0_STATUS_EXL_POSITION), "K" (_CP0_STATUS_UM_POSITION - _CP0_STATUS_EXL_POSITION + 1));

    // Enable interrupts whose priority is greater than the switch priority.

    // Status = k0

    asm volatile ("mtc0 $k0, $%0, %1" :: "K" (_CP0_STATUS), "K" (_CP0_STATUS_SELECT));

    // Interrupts are enabled now.

    // Therefore, we must not use k0 and k1 anymore.

    // Save GPR.

    asm volatile ("sw $a0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a0)));
    asm volatile ("sw $a1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a1)));
    asm volatile ("sw $a2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a2)));
    asm volatile ("sw $a3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a3)));
    asm volatile ("sw $at, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, at)));
    asm volatile ("sw $ra, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, ra)));
    asm volatile ("sw $s4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s4)));
    asm volatile ("sw $s5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s5)));
    asm volatile ("sw $s6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s6)));
    asm volatile ("sw $s7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s7)));
    asm volatile ("sw $t0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t0)));
    asm volatile ("sw $t1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t1)));
    asm volatile ("sw $t2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t2)));
    asm volatile ("sw $t3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t3)));
    asm volatile ("sw $t4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t4)));
    asm volatile ("sw $t5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t5)));
    asm volatile ("sw $t6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t6)));
    asm volatile ("sw $t7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t7)));
    asm volatile ("sw $t8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t8)));
    asm volatile ("sw $t9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t9)));
    asm volatile ("sw $v0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v0)));
    asm volatile ("sw $v1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v1)));

    // Save hi.
    // Save lo.

    asm volatile ("mfhi $s2");
    asm volatile ("mflo $s3");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo)));

    // Save hi1.
    // Save lo1.

    asm volatile ("mfhi $s2, $ac1");
    asm volatile ("mflo $s3, $ac1");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi1)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo1)));

    // Save hi2.
    // Save lo2.

    asm volatile ("mfhi $s2, $ac2");
    asm volatile ("mflo $s3, $ac2");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi2)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo2)));

    // Save hi3.
    // Save lo3.

    asm volatile ("mfhi $s2, $ac3");
    asm volatile ("mflo $s3, $ac3");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi3)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo3)));

    // Save DSPControl.

    asm volatile ("rddsp $s2");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, dsp_control)));

    // Save FCSR.

    asm volatile ("cfc1 $s2, $f31");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, fcsr)));

    // Save f0 .. f31.

    asm volatile ("sdc1 $f0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f0)));
    asm volatile ("sdc1 $f1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f1)));
    asm volatile ("sdc1 $f2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f2)));
    asm volatile ("sdc1 $f3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f3)));
    asm volatile ("sdc1 $f4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f4)));
    asm volatile ("sdc1 $f5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f5)));
    asm volatile ("sdc1 $f6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f6)));
    asm volatile ("sdc1 $f7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f7)));
    asm volatile ("sdc1 $f8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f8)));
    asm volatile ("sdc1 $f9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f9)));
    asm volatile ("sdc1 $f10, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f10)));
    asm volatile ("sdc1 $f11, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f11)));
    asm volatile ("sdc1 $f12, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f12)));
    asm volatile ("sdc1 $f13, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f13)));
    asm volatile ("sdc1 $f14, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f14)));
    asm volatile ("sdc1 $f15, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f15)));
    asm volatile ("sdc1 $f16, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f16)));
    asm volatile ("sdc1 $f17, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f17)));
    asm volatile ("sdc1 $f18, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f18)));
    asm volatile ("sdc1 $f19, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f19)));
    asm volatile ("sdc1 $f20, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f20)));
    asm volatile ("sdc1 $f21, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f21)));
    asm volatile ("sdc1 $f22, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f22)));
    asm volatile ("sdc1 $f23, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f23)));
    asm volatile ("sdc1 $f24, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f24)));
    asm volatile ("sdc1 $f25, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f25)));
    asm volatile ("sdc1 $f26, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f26)));
    asm volatile ("sdc1 $f27, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f27)));
    asm volatile ("sdc1 $f28, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f28)));
    asm volatile ("sdc1 $f29, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f29)));
    asm volatile ("sdc1 $f30, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f30)));
    asm volatile ("sdc1 $f31, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f31)));

    // Body.

    // s2 = &ao_task_running

    asm volatile ("la $s2, ao_task_running");

    // s3 = ao_task_running[0]

    asm volatile ("lw $s3, 0($s2)");

    // ao_task_running[0]->context.ptr = s1

    asm volatile ("sw $s1, %0($s3)" :: "K" (offsetof(ao_task_t, context.ptr)));

#if AO_TASK_STACK_CHECK

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jal ao_task_stack_check");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

#else

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jal ao_task_switch");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

#endif

    // s3 = ao_task_running[0]

    asm volatile ("lw $s3, 0($s2)");

    // s1 = ao_task_running[0]->context.ptr

    asm volatile ("lw $s1, %0($s3)" :: "K" (offsetof(ao_task_t, context.ptr)));

    // Epilog.

    // Restore GPR.

    asm volatile ("lw $a0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a0)));
    asm volatile ("lw $a1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a1)));
    asm volatile ("lw $a2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a2)));
    asm volatile ("lw $a3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a3)));
    asm volatile ("lw $at, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, at)));
    asm volatile ("lw $ra, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, ra)));
    asm volatile ("lw $s4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s4)));
    asm volatile ("lw $s5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s5)));
    asm volatile ("lw $s6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s6)));
    asm volatile ("lw $s7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s7)));
    asm volatile ("lw $t0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t0)));
    asm volatile ("lw $t1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t1)));
    asm volatile ("lw $t2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t2)));
    asm volatile ("lw $t3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t3)));
    asm volatile ("lw $t4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t4)));
    asm volatile ("lw $t5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t5)));
    asm volatile ("lw $t6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t6)));
    asm volatile ("lw $t7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t7)));
    asm volatile ("lw $t8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t8)));
    asm volatile ("lw $t9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t9)));
    asm volatile ("lw $v0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v0)));
    asm volatile ("lw $v1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v1)));

    // Restore hi.
    // Restore lo.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo)));
    asm volatile ("mthi $s2");
    asm volatile ("mtlo $s3");

    // Restore hi1.
    // Restore lo1.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi1)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo1)));
    asm volatile ("mthi $s2, $ac1");
    asm volatile ("mtlo $s3, $ac1");

    // Restore hi2.
    // Restore lo2.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi2)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo2)));
    asm volatile ("mthi $s2, $ac2");
    asm volatile ("mtlo $s3, $ac2");

    // Restore hi3.
    // Restore lo3.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi3)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo3)));
    asm volatile ("mthi $s2, $ac3");
    asm volatile ("mtlo $s3, $ac3");

    // Restore DSPControl.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, dsp_control)));
    asm volatile ("wrdsp $s2");

    // Restore FCSR.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, fcsr)));
    asm volatile ("ctc1 $s2, $f31");

    // Restore f0 .. f31.

    asm volatile ("ldc1 $f0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f0)));
    asm volatile ("ldc1 $f1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f1)));
    asm volatile ("ldc1 $f2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f2)));
    asm volatile ("ldc1 $f3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f3)));
    asm volatile ("ldc1 $f4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f4)));
    asm volatile ("ldc1 $f5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f5)));
    asm volatile ("ldc1 $f6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f6)));
    asm volatile ("ldc1 $f7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f7)));
    asm volatile ("ldc1 $f8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f8)));
    asm volatile ("ldc1 $f9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f9)));
    asm volatile ("ldc1 $f10, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f10)));
    asm volatile ("ldc1 $f11, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f11)));
    asm volatile ("ldc1 $f12, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f12)));
    asm volatile ("ldc1 $f13, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f13)));
    asm volatile ("ldc1 $f14, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f14)));
    asm volatile ("ldc1 $f15, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f15)));
    asm volatile ("ldc1 $f16, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f16)));
    asm volatile ("ldc1 $f17, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f17)));
    asm volatile ("ldc1 $f18, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f18)));
    asm volatile ("ldc1 $f19, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f19)));
    asm volatile ("ldc1 $f20, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f20)));
    asm volatile ("ldc1 $f21, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f21)));
    asm volatile ("ldc1 $f22, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f22)));
    asm volatile ("ldc1 $f23, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f23)));
    asm volatile ("ldc1 $f24, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f24)));
    asm volatile ("ldc1 $f25, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f25)));
    asm volatile ("ldc1 $f26, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f26)));
    asm volatile ("ldc1 $f27, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f27)));
    asm volatile ("ldc1 $f28, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f28)));
    asm volatile ("ldc1 $f29, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f29)));
    asm volatile ("ldc1 $f30, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f30)));
    asm volatile ("ldc1 $f31, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f31)));

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = EPC

    asm volatile ("lw $k0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, epc)));

    // k1 = Status

    asm volatile ("lw $k1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, status)));

    // Restore EPC.

    asm volatile ("mtc0 $k0, $%0, %1" :: "K" (_CP0_EPC), "K" (_CP0_EPC_SELECT));

    // Restore Status.

    asm volatile ("mtc0 $k1, $%0, %1" :: "K" (_CP0_STATUS), "K" (_CP0_STATUS_SELECT));

    // ao_ir_stack.depth = 0

    asm volatile ("sw $zero, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // sp = s1

    asm volatile ("addu $sp, $s1, $zero");

    // Restore s0.
    // Restore s1.
    // Restore s2.
    // Restore s3.
    // Restore s8.

    asm volatile ("lw $s0, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s0)));
    asm volatile ("lw $s1, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s1)));
    asm volatile ("lw $s2, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s2)));
    asm volatile ("lw $s3, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s3)));
    asm volatile ("lw $s8, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s8)));

    // Restore sp.

    asm volatile ("addiu $sp, $sp, %0" :: "K" (sizeof(ao_task_context_data_t)));

    // Return from exception.

    asm volatile ("eret");
    asm volatile ("nop");

    asm volatile (".set reorder");
    asm volatile (".set at");
}

// ----------------------------------------------------------------------------

void ao_task_start_context(ao_task_t * T)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(T);


    // Variables.

    void * b;

    ao_task_context_data_t * D;

    void * e;

    uint32_t * p;

    size_t s;


    // Ready.

    // Stack.

    b = ao_task_get_stack_beginning_locked(T);

    ao_assert(b);

    s = ao_task_get_stack_size_locked(T);

    e = ao_stack_get_end(b, s);

    // Stack pointer.

    p = e;

    // Stack pointer must be properly aligned.

    ao_assert(ao_is_aligned((uintptr_t) p, AO_STACK_ALIGN));

    // According to the MIPS O32 calling convention, the stack frame of the
    // caller must have an argument section. The argument section must contain
    // enough space for all the arguments of the callee, but at least four
    // words.

    p = p - 4;

    // Make room for the context.

    p = p - sizeof(ao_task_context_data_t) / 4;

    // Stack pointer must not overflow.

    ao_assert(p >= (uint32_t *) b);

    // Context.

    D = (ao_task_context_data_t *) p;

    D->a0 = (uint32_t) T;

    D->dsp_control = 0;

    D->epc = (uint32_t) ao_task_entry;

    D->fcsr = 0x01600000;

    // When generating interrupt handlers, the XC32 compiler assumes that both DSP and FPU are usable.

    // Therefore, the Status register bits CU1 and MX must always be set.

    D->status =
        _CP0_STATUS_CU1_MASK |
        _CP0_STATUS_EXL_MASK |
        _CP0_STATUS_FR_MASK  |
        _CP0_STATUS_IE_MASK  |
        _CP0_STATUS_MX_MASK;

    T->context.ptr = D;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK && AO_TASK_STACK_CHECK

// ----------------------------------------------------------------------------

void ao_task_stack_check()
{
    // Notes.

    // This function is called by the task switch interrupt handler.

    // The kernel is not locked.


    // Variables.

    void * b;

    void * e;

    void * p;

    size_t s1;

    size_t s2;

    ao_task_t * T;

    ptrdiff_t t3;


    // Ready.

    T = ao_task_running[0];

    ao_assert(T);

    p = T->context.ptr;

    if (p == NULL)
    {
        ao_task_stack_null(T);
    }

    else
    {
        // The kernel is not locked.

        // But, the task stack must not change while the task is started.

        // Therefore, we can read the task stack properties as if the kernel was locked.

        b = ao_task_get_stack_beginning_locked(T);

        ao_assert(b);

        if (p < b)
        {
            ao_task_stack_overflow(T);
        }

        else
        {
            s1 = ao_task_get_stack_size_locked(T);

            ao_assert(s1 > 0);

            e = ao_stack_get_end(b, s1);

            if (p >= e)
            {
                ao_task_stack_underflow(T);
            }

            else
            {
                s2 = (size_t) ((uint8_t *) e - (uint8_t *) p);

                s2 = s2 * 100 / s1;

                if (s2 >= AO_TASK_STACK_THRESHOLD)
                {
                    ao_task_stack_threshold(T, s2);
                }
            }
        }
    }

    ao_task_switch();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MK_GP

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t r = ao_sys_id_revision();

    uint32_t w;


    // Ready.

    ao_sys_kseg0_cacheable_write_back_alloc();

    // DS80000737.

    // Silicon Errata Issue 51.

    if (r == AO_SYS_ID_REVISION_A1) { }

    else
    {
        // DS60001402.

        // Section 10. Prefetch Module.

        w = (AO_SYS_SYSCLK <= 60000000UL) ? 1 : 3;

        ao_sys_pfm_ws_set(w);

        ao_sys_pref_enable_cacheable();
    }
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MK_GPG

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t w;


    // Ready.

    // DS60001570.

    // Section 9. Prefetch Module.

    // ECC disabled.

    if (DEVCFG0bits.FECCCON & 0x10)
    {
        w = (AO_SYS_SYSCLK <= 116000000UL) ? 1 : 2;
    }

    // ECC enabled.

    else
    {
        w = (AO_SYS_SYSCLK <=  96000000UL) ? 1 : 2;
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable_write_back_alloc();

    ao_sys_pref_enable_cacheable();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MK_GPK

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t w;


    // Ready.

    // DS60001519.

    // Section 10. Prefetch Module.

    // ECC disabled.

    if (DEVCFG0bits.FECCCON & 0x10)
    {
        w = (AO_SYS_SYSCLK <= 110000000UL) ? 1 : 2;
    }

    // ECC enabled.

    else
    {
        w = (AO_SYS_SYSCLK <= 96000000UL) ? 1 : 2;
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable_write_back_alloc();

    ao_sys_pref_enable_cacheable();
}

// ----------------------------------------------------------------------------

#endif

#endif

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32MX

#if defined AO_ALARM

// ----------------------------------------------------------------------------

AO_IR_CT_ATTRIBUTE
void ao_ir_ct()
{
    ao_ir_stack_func0((ao_func0_t) ao_alarm);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK

// ----------------------------------------------------------------------------

static  void    ao_task_stack_check();

// ----------------------------------------------------------------------------

AO_IR_CS1_ATTRIBUTE
void ao_ir_cs1()
{
    // Prolog.

    // Interrupts are disabled, because Status.EXL == 1.

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Make room for the context.

    asm volatile ("addiu $sp, $sp, -%0" :: "K" (sizeof(ao_task_context_data_t)));

    // Save s0.
    // Save s1.
    // Save s8.

    asm volatile ("sw $s0, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s0)));
    asm volatile ("sw $s1, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s1)));
    asm volatile ("sw $s8, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s8)));

    // s1 = sp

    asm volatile ("addu $s1, $sp, $zero");

    // Switch to the interrupt stack.

    // We can safely use k0 and k1, because interrupts are disabled.

    // s0 = &ao_ir_stack

    asm volatile ("la $s0, ao_ir_stack");

    // k1 = 1

    asm volatile ("addiu $k1, $zero, 1");

    // sp = ao_ir_stack.sp

    asm volatile ("lw $sp, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, sp)));

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // s8 = sp

    asm volatile ("addu $s8, $sp, $zero");

#if AO_IR_STACK_DEPTH_MAX

    // k0 = ao_ir_stack.depth_max

    asm volatile ("lw $k0, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    // k0 = k0 - 1

    asm volatile ("addiu $k0, $k0, -1");

    // if (k0 >= 0) then goto 1

    asm volatile ("bgez $k0, 1f");
    asm volatile ("nop");

    // ao_ir_stack.depth_max = k1

    asm volatile ("sw $k1, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    asm volatile ("1:");

#endif

    // k1 = EPC

    asm volatile ("mfc0 $k1, $%0, %1" :: "K" (_CP0_EPC), "K" (_CP0_EPC_SELECT));

    // k0 = Status

    asm volatile ("mfc0 $k0, $%0, %1" :: "K" (_CP0_STATUS), "K" (_CP0_STATUS_SELECT));

    // Save EPC.

    asm volatile ("sw $k1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, epc)));

    // Save Status.

    asm volatile ("sw $k0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, status)));

    // Manipulate the Status value contained in k0.

    // Status.IPL = AO_IR_CS1_PRIO
    // Status.EXL = 0
    // Status.ERL = 0
    // Status.UM  = 0

    // k1 = AO_IR_CS1_PRIO

    asm volatile ("addiu $k1, $zero, %0" :: "K" (AO_IR_CS1_PRIO));

    // k0.IPL = k1

    asm volatile ("ins $k0, $k1, %0, %1" :: "K" (_CP0_STATUS_IPL_POSITION), "K" (_CP0_STATUS_IPL_LENGTH));

    // k0.EXL = 0
    // k0.ERL = 0
    // k0.UM  = 0

    asm volatile ("ins $k0, $zero, %0, %1" :: "K" (_CP0_STATUS_EXL_POSITION), "K" (_CP0_STATUS_UM_POSITION - _CP0_STATUS_EXL_POSITION + 1));

    // Enable interrupts whose priority is greater than the switch priority.

    // Status = k0

    asm volatile ("mtc0 $k0, $%0, %1" :: "K" (_CP0_STATUS), "K" (_CP0_STATUS_SELECT));

    // Interrupts are enabled now.

    // Therefore, we must not use k0 and k1 anymore.

    // Save GPR.

    asm volatile ("sw $a0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a0)));
    asm volatile ("sw $a1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a1)));
    asm volatile ("sw $a2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a2)));
    asm volatile ("sw $a3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a3)));
    asm volatile ("sw $at, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, at)));
    asm volatile ("sw $ra, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, ra)));
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s2)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s3)));
    asm volatile ("sw $s4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s4)));
    asm volatile ("sw $s5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s5)));
    asm volatile ("sw $s6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s6)));
    asm volatile ("sw $s7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s7)));
    asm volatile ("sw $t0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t0)));
    asm volatile ("sw $t1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t1)));
    asm volatile ("sw $t2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t2)));
    asm volatile ("sw $t3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t3)));
    asm volatile ("sw $t4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t4)));
    asm volatile ("sw $t5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t5)));
    asm volatile ("sw $t6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t6)));
    asm volatile ("sw $t7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t7)));
    asm volatile ("sw $t8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t8)));
    asm volatile ("sw $t9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t9)));
    asm volatile ("sw $v0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v0)));
    asm volatile ("sw $v1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v1)));

    // Save hi.
    // Save lo.

    asm volatile ("mfhi $s2");
    asm volatile ("mflo $s3");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo)));

    // Body.

    // s2 = &ao_task_running

    asm volatile ("la $s2, ao_task_running");

    // s3 = ao_task_running[0]

    asm volatile ("lw $s3, 0($s2)");

    // ao_task_running[0]->context.ptr = s1

    asm volatile ("sw $s1, %0($s3)" :: "K" (offsetof(ao_task_t, context.ptr)));

#if AO_TASK_STACK_CHECK

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jal ao_task_stack_check");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

#else

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jal ao_task_switch");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

#endif

    // s3 = ao_task_running[0]

    asm volatile ("lw $s3, 0($s2)");

    // s1 = ao_task_running[0]->context.ptr

    asm volatile ("lw $s1, %0($s3)" :: "K" (offsetof(ao_task_t, context.ptr)));

    // Epilog.

    // Restore hi.
    // Restore lo.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo)));
    asm volatile ("mthi $s2");
    asm volatile ("mtlo $s3");

    // Restore GPR.

    asm volatile ("lw $a0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a0)));
    asm volatile ("lw $a1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a1)));
    asm volatile ("lw $a2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a2)));
    asm volatile ("lw $a3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a3)));
    asm volatile ("lw $at, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, at)));
    asm volatile ("lw $ra, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, ra)));
    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s2)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s3)));
    asm volatile ("lw $s4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s4)));
    asm volatile ("lw $s5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s5)));
    asm volatile ("lw $s6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s6)));
    asm volatile ("lw $s7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s7)));
    asm volatile ("lw $t0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t0)));
    asm volatile ("lw $t1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t1)));
    asm volatile ("lw $t2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t2)));
    asm volatile ("lw $t3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t3)));
    asm volatile ("lw $t4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t4)));
    asm volatile ("lw $t5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t5)));
    asm volatile ("lw $t6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t6)));
    asm volatile ("lw $t7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t7)));
    asm volatile ("lw $t8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t8)));
    asm volatile ("lw $t9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t9)));
    asm volatile ("lw $v0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v0)));
    asm volatile ("lw $v1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v1)));

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = EPC

    asm volatile ("lw $k0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, epc)));

    // k1 = Status

    asm volatile ("lw $k1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, status)));

    // Restore EPC.

    asm volatile ("mtc0 $k0, $%0, %1" :: "K" (_CP0_EPC), "K" (_CP0_EPC_SELECT));

    // Restore Status.

    asm volatile ("mtc0 $k1, $%0, %1" :: "K" (_CP0_STATUS), "K" (_CP0_STATUS_SELECT));

    // ao_ir_stack.depth = 0

    asm volatile ("sw $zero, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // sp = s1

    asm volatile ("addu $sp, $s1, $zero");

    // Restore s0.
    // Restore s1.
    // Restore s8.

    asm volatile ("lw $s0, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s0)));
    asm volatile ("lw $s1, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s1)));
    asm volatile ("lw $s8, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s8)));

    // Restore sp.

    asm volatile ("addiu $sp, $sp, %0" :: "K" (sizeof(ao_task_context_data_t)));

    // Return from exception.

    asm volatile ("eret");
    asm volatile ("nop");

    asm volatile (".set reorder");
    asm volatile (".set at");
}

// ----------------------------------------------------------------------------

void ao_task_start_context(ao_task_t * T)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(T);


    // Variables.

    void * b;

    ao_task_context_data_t * D;

    void * e;

    uint32_t * p;

    size_t s;


    // Ready.

    // Stack.

    b = ao_task_get_stack_beginning_locked(T);

    ao_assert(b);

    s = ao_task_get_stack_size_locked(T);

    e = ao_stack_get_end(b, s);

    // Stack pointer.

    p = e;

    // Stack pointer must be properly aligned.

    ao_assert(ao_is_aligned((uintptr_t) p, AO_STACK_ALIGN));

    // According to the MIPS O32 calling convention, the stack frame of the
    // caller must have an argument section. The argument section must contain
    // enough space for all the arguments of the callee, but at least four
    // words.

    p = p - 4;

    // Make room for the context.

    p = p - sizeof(ao_task_context_data_t) / 4;

    // Stack pointer must not overflow.

    ao_assert(p >= (uint32_t *) b);

    // Context.

    D = (ao_task_context_data_t *) p;

    D->a0 = (uint32_t) T;

    D->epc = (uint32_t) ao_task_entry;

    D->status =
        _CP0_STATUS_EXL_MASK  |
        _CP0_STATUS_IE_MASK;

    T->context.ptr = D;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK && AO_TASK_STACK_CHECK

// ----------------------------------------------------------------------------

void ao_task_stack_check()
{
    // Notes.

    // This function is called by the task switch interrupt handler.

    // The kernel is not locked.


    // Variables.

    void * b;

    void * e;

    void * p;

    size_t s1;

    size_t s2;

    ao_task_t * T;

    ptrdiff_t t3;


    // Ready.

    T = ao_task_running[0];

    ao_assert(T);

    p = T->context.ptr;

    if (p == NULL)
    {
        ao_task_stack_null(T);
    }

    else
    {
        // The kernel is not locked.

        // But, the task stack must not change while the task is started.

        // Therefore, we can read the task stack properties as if the kernel was locked.

        b = ao_task_get_stack_beginning_locked(T);

        ao_assert(b);

        if (p < b)
        {
            ao_task_stack_overflow(T);
        }

        else
        {
            s1 = ao_task_get_stack_size_locked(T);

            ao_assert(s1 > 0);

            e = ao_stack_get_end(b, s1);

            if (p >= e)
            {
                ao_task_stack_underflow(T);
            }

            else
            {
                s2 = (size_t) ((uint8_t *) e - (uint8_t *) p);

                s2 = s2 * 100 / s1;

                if (s2 >= AO_TASK_STACK_THRESHOLD)
                {
                    ao_task_stack_threshold(T, s2);
                }
            }
        }
    }

    ao_task_switch();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MX_1XX

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    ao_sys_kseg0_cacheable();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MX_1XX_64_100

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    ao_sys_kseg0_cacheable();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MX_1XX_XLP

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t w;


    // Ready.

    // DS60001404.

    // Section 33. Electrical Characteristics.

    if (AO_SYS_SYSCLK < 19000000UL)
    {
        w = 0;
    }

    else if (AO_SYS_SYSCLK < 37000000UL)
    {
        w = 1;
    }

    else if (AO_SYS_SYSCLK < 55000000UL)
    {
        w = 2;
    }

    else
    {
        w = 3;
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable();

    ao_sys_pref_enable_cacheable();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MX_330

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t w;


    // Ready.

    // DS60001185.

    // Section 31. Electrical Characteristics.

    if (AO_SYS_SYSCLK < 31000000UL)
    {
        w = 0;
    }

    else if (AO_SYS_SYSCLK < 61000000UL)
    {
        w = 1;
    }

    else if (AO_SYS_SYSCLK < 101000000UL)
    {
        w = 2;
    }

    else
    {
        w = 3;
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable();

    ao_sys_pref_enable_cacheable();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MX_3XX

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t w;


    // Ready.

    // DS61143.

    // Section 29. Electrical Characteristics.

    if (AO_SYS_SYSCLK < 31000000UL)
    {
        w = 0;
    }

    else if (AO_SYS_SYSCLK < 61000000UL)
    {
        w = 1;
    }

    else
    {
        w = 2;
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable();

    ao_sys_pref_enable_cacheable();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MX_5XX

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t w;


    // Ready.

    // DS60001156.

    // Section 32. Electrical Characteristics.

    if (AO_SYS_SYSCLK < 31000000UL)
    {
        w = 0;
    }

    else if (AO_SYS_SYSCLK < 61000000UL)
    {
        w = 1;
    }

    else
    {
        w = 2;
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable();

    ao_sys_pref_enable_cacheable();
}

// ----------------------------------------------------------------------------

#endif

#endif

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32MZ

#if defined AO_ALARM

// ----------------------------------------------------------------------------

AO_IR_CT_ATTRIBUTE
void ao_ir_ct()
{
    ao_ir_stack_func0((ao_func0_t) ao_alarm);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_sys_lock_pps(ao_sys_lock_pps_t * x)
{
    ao_assert(x);

    uint32_t t1 = x->io & _CFGCON_IOLOCK_MASK;

    uint32_t t2 = CFGCON & ~_CFGCON_IOLOCK_MASK;

    CFGCON = t1 | t2;

    ao_sys_lock_device(&x->device);
}

void ao_sys_unlock_pps(ao_sys_lock_pps_t * x)
{
    ao_assert(x);

    ao_sys_unlock_device(&x->device);

    uint32_t i = CFGCON;

    CFGCON = i & ~_CFGCON_IOLOCK_MASK;

    x->io = i;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK

// ----------------------------------------------------------------------------

static  void    ao_task_stack_check();

// ----------------------------------------------------------------------------

AO_IR_CS1_ATTRIBUTE
void ao_ir_cs1()
{
    // Prolog.

    // Interrupts are disabled, because Status.EXL == 1.

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

    // Make room for the context.

    asm volatile ("addiu $sp, $sp, -%0" :: "K" (sizeof(ao_task_context_data_t)));

    // Save s0.
    // Save s1.
    // Save s2.
    // Save s3.
    // Save s8.

    asm volatile ("sw $s0, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s0)));
    asm volatile ("sw $s1, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s1)));
    asm volatile ("sw $s2, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s2)));
    asm volatile ("sw $s3, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s3)));
    asm volatile ("sw $s8, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s8)));

    // s1 = sp

    asm volatile ("addu $s1, $sp, $zero");

    // Switch to the interrupt stack.

    // We can safely use k0 and k1, because interrupts are disabled.

    // s0 = &ao_ir_stack

    asm volatile ("la $s0, ao_ir_stack");

    // k1 = 1

    asm volatile ("addiu $k1, $zero, 1");

    // sp = ao_ir_stack.sp

    asm volatile ("lw $sp, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, sp)));

    // ao_ir_stack.depth = k1

    asm volatile ("sw $k1, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // s8 = sp

    asm volatile ("addu $s8, $sp, $zero");

#if AO_IR_STACK_DEPTH_MAX

    // k0 = ao_ir_stack.depth_max

    asm volatile ("lw $k0, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    // k0 = k0 - 1

    asm volatile ("addiu $k0, $k0, -1");

    // if (k0 >= 0) then goto 1

    asm volatile ("bgez $k0, 1f");
    asm volatile ("nop");

    // ao_ir_stack.depth_max = k1

    asm volatile ("sw $k1, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth_max)));

    asm volatile ("1:");

#endif

    // k1 = EPC

    asm volatile ("mfc0 $k1, $%0, %1" :: "K" (_CP0_EPC), "K" (_CP0_EPC_SELECT));

    // k0 = Status

    asm volatile ("mfc0 $k0, $%0, %1" :: "K" (_CP0_STATUS), "K" (_CP0_STATUS_SELECT));

    // save EPC

    asm volatile ("sw $k1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, epc)));

    // save Status

    asm volatile ("sw $k0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, status)));

    // Manipulate the Status value contained in k0.

    // Status.IPL = AO_IR_CS1_PRIO
    // Status.EXL = 0
    // Status.ERL = 0
    // Status.UM  = 0

    // k1 = AO_IR_CS1_PRIO

    asm volatile ("addiu $k1, $zero, %0" :: "K" (AO_IR_CS1_PRIO));

    // k0.IPL = k1

    asm volatile ("ins $k0, $k1, %0, %1" :: "K" (_CP0_STATUS_IPL_POSITION), "K" (_CP0_STATUS_IPL_LENGTH));

    // k0.EXL = 0
    // k0.ERL = 0
    // k0.UM  = 0

    asm volatile ("ins $k0, $zero, %0, %1" :: "K" (_CP0_STATUS_EXL_POSITION), "K" (_CP0_STATUS_UM_POSITION - _CP0_STATUS_EXL_POSITION + 1));

    // Enable interrupts whose priority is greater than the switch priority.

    // Status = k0

    asm volatile ("mtc0 $k0, $%0, %1" :: "K" (_CP0_STATUS), "K" (_CP0_STATUS_SELECT));

    // Interrupts are enabled now.

    // Therefore, we must not use k0 and k1 anymore.

    // Save GPR.

    asm volatile ("sw $a0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a0)));
    asm volatile ("sw $a1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a1)));
    asm volatile ("sw $a2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a2)));
    asm volatile ("sw $a3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a3)));
    asm volatile ("sw $at, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, at)));
    asm volatile ("sw $ra, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, ra)));
    asm volatile ("sw $s4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s4)));
    asm volatile ("sw $s5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s5)));
    asm volatile ("sw $s6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s6)));
    asm volatile ("sw $s7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s7)));
    asm volatile ("sw $t0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t0)));
    asm volatile ("sw $t1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t1)));
    asm volatile ("sw $t2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t2)));
    asm volatile ("sw $t3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t3)));
    asm volatile ("sw $t4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t4)));
    asm volatile ("sw $t5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t5)));
    asm volatile ("sw $t6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t6)));
    asm volatile ("sw $t7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t7)));
    asm volatile ("sw $t8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t8)));
    asm volatile ("sw $t9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t9)));
    asm volatile ("sw $v0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v0)));
    asm volatile ("sw $v1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v1)));

    // Save hi.
    // Save lo.

    asm volatile ("mfhi $s2");
    asm volatile ("mflo $s3");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo)));

    // Save hi1.
    // Save lo1.

    asm volatile ("mfhi $s2, $ac1");
    asm volatile ("mflo $s3, $ac1");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi1)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo1)));

    // Save hi2.
    // Save lo2.

    asm volatile ("mfhi $s2, $ac2");
    asm volatile ("mflo $s3, $ac2");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi2)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo2)));

    // Save hi3.
    // Save lo3.

    asm volatile ("mfhi $s2, $ac3");
    asm volatile ("mflo $s3, $ac3");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi3)));
    asm volatile ("sw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo3)));

    // Save DSPControl.

    asm volatile ("rddsp $s2");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, dsp_control)));

    // Save FCSR.

    asm volatile ("cfc1 $s2, $f31");
    asm volatile ("sw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, fcsr)));

    // Save f0 .. f31.

    asm volatile ("sdc1 $f0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f0)));
    asm volatile ("sdc1 $f1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f1)));
    asm volatile ("sdc1 $f2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f2)));
    asm volatile ("sdc1 $f3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f3)));
    asm volatile ("sdc1 $f4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f4)));
    asm volatile ("sdc1 $f5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f5)));
    asm volatile ("sdc1 $f6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f6)));
    asm volatile ("sdc1 $f7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f7)));
    asm volatile ("sdc1 $f8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f8)));
    asm volatile ("sdc1 $f9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f9)));
    asm volatile ("sdc1 $f10, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f10)));
    asm volatile ("sdc1 $f11, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f11)));
    asm volatile ("sdc1 $f12, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f12)));
    asm volatile ("sdc1 $f13, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f13)));
    asm volatile ("sdc1 $f14, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f14)));
    asm volatile ("sdc1 $f15, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f15)));
    asm volatile ("sdc1 $f16, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f16)));
    asm volatile ("sdc1 $f17, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f17)));
    asm volatile ("sdc1 $f18, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f18)));
    asm volatile ("sdc1 $f19, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f19)));
    asm volatile ("sdc1 $f20, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f20)));
    asm volatile ("sdc1 $f21, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f21)));
    asm volatile ("sdc1 $f22, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f22)));
    asm volatile ("sdc1 $f23, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f23)));
    asm volatile ("sdc1 $f24, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f24)));
    asm volatile ("sdc1 $f25, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f25)));
    asm volatile ("sdc1 $f26, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f26)));
    asm volatile ("sdc1 $f27, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f27)));
    asm volatile ("sdc1 $f28, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f28)));
    asm volatile ("sdc1 $f29, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f29)));
    asm volatile ("sdc1 $f30, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f30)));
    asm volatile ("sdc1 $f31, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f31)));

    // Body.

    // s2 = &ao_task_running

    asm volatile ("la $s2, ao_task_running");

    // s3 = ao_task_running[0]

    asm volatile ("lw $s3, 0($s2)");

    // ao_task_running[0]->context.ptr = s1

    asm volatile ("sw $s1, %0($s3)" :: "K" (offsetof(ao_task_t, context.ptr)));

#if AO_TASK_STACK_CHECK

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jal ao_task_stack_check");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

#else

    asm volatile (".set reorder");
    asm volatile (".set at");

    asm volatile ("jal ao_task_switch");
    asm volatile ("nop");

    asm volatile (".set nomips16");
    asm volatile (".set noreorder");
    asm volatile (".set noat");

#endif

    // s3 = ao_task_running[0]

    asm volatile ("lw $s3, 0($s2)");

    // s1 = ao_task_running[0]->context.ptr

    asm volatile ("lw $s1, %0($s3)" :: "K" (offsetof(ao_task_t, context.ptr)));

    // Epilog.

    // Restore GPR.

    asm volatile ("lw $a0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a0)));
    asm volatile ("lw $a1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a1)));
    asm volatile ("lw $a2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a2)));
    asm volatile ("lw $a3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, a3)));
    asm volatile ("lw $at, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, at)));
    asm volatile ("lw $ra, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, ra)));
    asm volatile ("lw $s4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s4)));
    asm volatile ("lw $s5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s5)));
    asm volatile ("lw $s6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s6)));
    asm volatile ("lw $s7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, s7)));
    asm volatile ("lw $t0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t0)));
    asm volatile ("lw $t1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t1)));
    asm volatile ("lw $t2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t2)));
    asm volatile ("lw $t3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t3)));
    asm volatile ("lw $t4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t4)));
    asm volatile ("lw $t5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t5)));
    asm volatile ("lw $t6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t6)));
    asm volatile ("lw $t7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t7)));
    asm volatile ("lw $t8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t8)));
    asm volatile ("lw $t9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, t9)));
    asm volatile ("lw $v0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v0)));
    asm volatile ("lw $v1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, v1)));

    // Restore hi.
    // Restore lo.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo)));
    asm volatile ("mthi $s2");
    asm volatile ("mtlo $s3");

    // Restore hi1.
    // Restore lo1.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi1)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo1)));
    asm volatile ("mthi $s2, $ac1");
    asm volatile ("mtlo $s3, $ac1");

    // Restore hi2.
    // Restore lo2.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi2)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo2)));
    asm volatile ("mthi $s2, $ac2");
    asm volatile ("mtlo $s3, $ac2");

    // Restore hi3.
    // Restore lo3.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, hi3)));
    asm volatile ("lw $s3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, lo3)));
    asm volatile ("mthi $s2, $ac3");
    asm volatile ("mtlo $s3, $ac3");

    // Restore DSPControl.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, dsp_control)));
    asm volatile ("wrdsp $s2");

    // Restore FCSR.

    asm volatile ("lw $s2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, fcsr)));
    asm volatile ("ctc1 $s2, $f31");

    // Restore f0 .. f31.

    asm volatile ("ldc1 $f0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f0)));
    asm volatile ("ldc1 $f1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f1)));
    asm volatile ("ldc1 $f2, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f2)));
    asm volatile ("ldc1 $f3, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f3)));
    asm volatile ("ldc1 $f4, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f4)));
    asm volatile ("ldc1 $f5, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f5)));
    asm volatile ("ldc1 $f6, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f6)));
    asm volatile ("ldc1 $f7, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f7)));
    asm volatile ("ldc1 $f8, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f8)));
    asm volatile ("ldc1 $f9, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f9)));
    asm volatile ("ldc1 $f10, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f10)));
    asm volatile ("ldc1 $f11, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f11)));
    asm volatile ("ldc1 $f12, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f12)));
    asm volatile ("ldc1 $f13, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f13)));
    asm volatile ("ldc1 $f14, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f14)));
    asm volatile ("ldc1 $f15, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f15)));
    asm volatile ("ldc1 $f16, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f16)));
    asm volatile ("ldc1 $f17, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f17)));
    asm volatile ("ldc1 $f18, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f18)));
    asm volatile ("ldc1 $f19, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f19)));
    asm volatile ("ldc1 $f20, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f20)));
    asm volatile ("ldc1 $f21, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f21)));
    asm volatile ("ldc1 $f22, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f22)));
    asm volatile ("ldc1 $f23, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f23)));
    asm volatile ("ldc1 $f24, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f24)));
    asm volatile ("ldc1 $f25, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f25)));
    asm volatile ("ldc1 $f26, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f26)));
    asm volatile ("ldc1 $f27, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f27)));
    asm volatile ("ldc1 $f28, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f28)));
    asm volatile ("ldc1 $f29, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f29)));
    asm volatile ("ldc1 $f30, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f30)));
    asm volatile ("ldc1 $f31, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, f31)));

    // Disable interrupts.

    asm volatile ("di");
    asm volatile ("ehb");

    // k0 = EPC

    asm volatile ("lw $k0, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, epc)));

    // k1 = Status

    asm volatile ("lw $k1, %0($s1)" :: "K" (offsetof(ao_task_context_data_t, status)));

    // Restore EPC.

    asm volatile ("mtc0 $k0, $%0, %1" :: "K" (_CP0_EPC), "K" (_CP0_EPC_SELECT));

    // Restore Status.

    asm volatile ("mtc0 $k1, $%0, %1" :: "K" (_CP0_STATUS), "K" (_CP0_STATUS_SELECT));

    // ao_ir_stack.depth = 0

    asm volatile ("sw $zero, %0($s0)" :: "K" (offsetof(ao_ir_stack_t, depth)));

    // sp = s1

    asm volatile ("addu $sp, $s1, $zero");

    // Restore s0.
    // Restore s1.
    // Restore s2.
    // Restore s3.
    // Restore s8.

    asm volatile ("lw $s0, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s0)));
    asm volatile ("lw $s1, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s1)));
    asm volatile ("lw $s2, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s2)));
    asm volatile ("lw $s3, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s3)));
    asm volatile ("lw $s8, %0($sp)" :: "K" (offsetof(ao_task_context_data_t, s8)));

    // Restore sp.

    asm volatile ("addiu $sp, $sp, %0" :: "K" (sizeof(ao_task_context_data_t)));

    // Return from exception.

    asm volatile ("eret");
    asm volatile ("nop");

    asm volatile (".set reorder");
    asm volatile (".set at");
}

// ----------------------------------------------------------------------------

void ao_task_start_context(ao_task_t * T)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(T);


    // Variables.

    void * b;

    ao_task_context_data_t * D;

    void * e;

    uint32_t * p;

    size_t s;


    // Ready.

    // Stack.

    b = ao_task_get_stack_beginning_locked(T);

    ao_assert(b);

    s = ao_task_get_stack_size_locked(T);

    e = ao_stack_get_end(b, s);

    // Stack pointer.

    p = e;

    // Stack pointer must be properly aligned.

    ao_assert(ao_is_aligned((uintptr_t) p, AO_STACK_ALIGN));

    // According to the MIPS O32 calling convention, the stack frame of the
    // caller must have an argument section. The argument section must contain
    // enough space for all the arguments of the callee, but at least four
    // words.

    p = p - 4;

    // Make room for the context.

    p = p - sizeof(ao_task_context_data_t) / 4;

    // Stack pointer must not overflow.

    ao_assert(p >= (uint32_t *) b);

    // Context.

    D = (ao_task_context_data_t *) p;

    D->a0 = (uint32_t) T;

    D->dsp_control = 0;

    D->epc = (uint32_t) ao_task_entry;

    D->fcsr = 0x01600000;

    // When generating interrupt handlers, the XC32 compiler assumes that both DSP and FPU are usable.

    // Therefore, the Status register bits CU1 and MX must always be set.

    D->status =
        _CP0_STATUS_CU1_MASK |
        _CP0_STATUS_EXL_MASK |
        _CP0_STATUS_FR_MASK  |
        _CP0_STATUS_IE_MASK  |
        _CP0_STATUS_MX_MASK;

    T->context.ptr = D;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK && AO_TASK_STACK_CHECK

// ----------------------------------------------------------------------------

void ao_task_stack_check()
{
    // Notes.

    // This function is called by the task switch interrupt handler.

    // The kernel is not locked.


    // Variables.

    void * b;

    void * e;

    void * p;

    size_t s1;

    size_t s2;

    ao_task_t * T;

    ptrdiff_t t3;


    // Ready.

    T = ao_task_running[0];

    ao_assert(T);

    p = T->context.ptr;

    if (p == NULL)
    {
        ao_task_stack_null(T);
    }

    else
    {
        // The kernel is not locked.

        // But, the task stack must not change while the task is started.

        // Therefore, we can read the task stack properties as if the kernel was locked.

        b = ao_task_get_stack_beginning_locked(T);

        ao_assert(b);

        if (p < b)
        {
            ao_task_stack_overflow(T);
        }

        else
        {
            s1 = ao_task_get_stack_size_locked(T);

            ao_assert(s1 > 0);

            e = ao_stack_get_end(b, s1);

            if (p >= e)
            {
                ao_task_stack_underflow(T);
            }

            else
            {
                s2 = (size_t) ((uint8_t *) e - (uint8_t *) p);

                s2 = s2 * 100 / s1;

                if (s2 >= AO_TASK_STACK_THRESHOLD)
                {
                    ao_task_stack_threshold(T, s2);
                }
            }
        }
    }

    ao_task_switch();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MZ_DA

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t w;


    // Ready.

    // DS60001361.

    // Section 44. Electrical Characteristics.

    // ECC disabled.

    if (DEVCFG0bits.FECCCON & 0x10)
    {
        if (AO_SYS_SYSCLK <= 74000000UL)
        {
            w = 0;
        }

        else if (AO_SYS_SYSCLK <= 140000000UL)
        {
            w = 1;
        }

        else
        {
            w = 2;
        }
    }

    // ECC enabled.

    else
    {
        if (AO_SYS_SYSCLK <= 60000000UL)
        {
            w = 0;
        }

        else if (AO_SYS_SYSCLK <= 120000000UL)
        {
            w = 1;
        }

        else
        {
            w = 2;
        }
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable_write_back_alloc();

    ao_sys_pref_enable_instructions_and_data();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MZ_DAK

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t w;


    // Ready.

    // DS60001565.

    // Section 44. Electrical Characteristics.

    // ECC disabled.

    if (DEVCFG0bits.FECCCON & 0x10)
    {
        if (AO_SYS_SYSCLK <= 74000000UL)
        {
            w = 0;
        }

        else if (AO_SYS_SYSCLK <= 140000000UL)
        {
            w = 1;
        }

        else
        {
            w = 2;
        }
    }

    // ECC enabled.

    else
    {
        if (AO_SYS_SYSCLK <= 60000000UL)
        {
            w = 0;
        }

        else if (AO_SYS_SYSCLK <= 120000000UL)
        {
            w = 1;
        }

        else
        {
            w = 2;
        }
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable_write_back_alloc();

    ao_sys_pref_enable_instructions_and_data();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MZ_EC

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t w;


    // Ready.

    // DS60001191.

    // Section 37. Electrical Characteristics.

    // DS80000588.

    // Silicon Errata Issue 2.

    // ECC disabled.

    if (DEVCFG0bits.FECCCON & 0x10)
    {
        if (AO_SYS_SYSCLK <= 74000000UL)
        {
            w = 0;
        }

        else if (AO_SYS_SYSCLK <= 140000000UL)
        {
            w = 1;
        }

        else
        {
            w = 2;
        }
    }

    // ECC enabled.

    else
    {
        if (AO_SYS_SYSCLK <= 60000000UL)
        {
            w = 0;
        }

        else if (AO_SYS_SYSCLK <= 120000000UL)
        {
            w = 1;
        }

        else
        {
            w = 2;
        }
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable_write_back_alloc();

    ao_sys_pref_enable_instructions_and_data();
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MZ_EF

#if defined AO_SYS

// ----------------------------------------------------------------------------

void ao_boot_sys_pcache()
{
    // Variables.

    uint32_t r;

    uint32_t w;


    // Ready.

    // DS60001320.

    // Section 37. Electrical Characteristics.

    // ECC disabled.

    if (DEVCFG0bits.FECCCON & 0x10)
    {
        if (AO_SYS_SYSCLK <= 74000000UL)
        {
            w = 0;
        }

        else if (AO_SYS_SYSCLK <= 140000000UL)
        {
            w = 1;
        }

        else
        {
            // DS80000663.

            // Silicon Errata Issue 38.

            r = ao_sys_id_revision();

            if (r == AO_SYS_ID_REVISION_B2)
            {
                if (AO_SYS_SYSCLK <= 184000000UL)
                {
                    w = 2;
                }

                else
                {
                    w = 3;
                }
            }

            else
            {
                w = 2;
            }
        }
    }

    // ECC enabled.

    else
    {
        if (AO_SYS_SYSCLK <= 60000000UL)
        {
            w = 0;
        }

        else if (AO_SYS_SYSCLK <= 120000000UL)
        {
            w = 1;
        }

        else
        {
            // DS80000663.

            // Silicon Errata Issue 38.

            r = ao_sys_id_revision();

            if (r == AO_SYS_ID_REVISION_B2)
            {
                if (AO_SYS_SYSCLK <= 184000000UL)
                {
                    w = 2;
                }

                else
                {
                    w = 3;
                }
            }

            else
            {
                w = 2;
            }
        }
    }

    ao_sys_pfm_ws_set(w);

    ao_sys_kseg0_cacheable_write_back_alloc();

    ao_sys_pref_enable_instructions_and_data();
}

// ----------------------------------------------------------------------------

#endif

#endif

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32_CAN

#if defined AO_CAN

// ----------------------------------------------------------------------------

static  void    ao_can_ir_1();

static  void    ao_can_ir_2();

static  void    ao_can_ir_3();

static  void    ao_can_ir_4();

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32

// ----------------------------------------------------------------------------

#if defined AO_CAN

// ----------------------------------------------------------------------------

void ao_can_baud(ao_can_baud_t * x)
{
    // Assert.

    ao_assert(x);

    ao_assert(x->f_pbclk > 0);

    ao_assert(x->f >= ao_can_baud_min(x->f_pbclk));
    ao_assert(x->f <= ao_can_baud_max(x->f_pbclk));

    ao_assert(x->sample >=  50);
    ao_assert(x->sample <= 100);

    ao_assert(x->sjw >= 1);
    ao_assert(x->sjw <= 4);


    // Variables.

    uint32_t            brp;

    uint32_t            f                   = x->f;

    uint32_t            f_error;

    uint32_t            f_error_min         = UINT32_MAX;

    uint32_t            f_max;

    uint32_t            f_min;

    uint32_t            f_pbclk             = x->f_pbclk;

    uint32_t            f_real;

    uint32_t            n                   = 8;

    uint32_t            n1;

    uint32_t            n2;

    uint32_t            np;

    uint32_t            ns                  = 1;

    uint32_t            nx;

    ao_can_reg_cfg_t    r;

    uint32_t            sample              = x->sample * 1000;

    uint32_t            sample_error;

    uint32_t            sample_error_min;

    uint32_t            sample_real;

    bool                sample_thrice       = x->sample_thrice;

    bool                sample_thrice_real;

    uint32_t            sjw                 = x->sjw;

    bool                wake_up_filter      = x->wake_up_filter;


    // Ready.

    x->result = false;

    do
    {
        // Maximum and minimum baud rate.

        f_max = f_pbclk / (2 * n);

        f_min = (f_pbclk - 1) / (128 * n) + 1;

        if
        (
            f >= f_min &&
            f <= f_max
        )
        {
            // Baud rate prescaler bits.

            brp = f_pbclk / (2 * n * f);

            ao_assert(brp >=  1);
            ao_assert(brp <= 64);

            // Baud rate.

            f_real = f_pbclk / (2 * n * brp);

            ao_assert(f_real >= f_pbclk / (128 * n));
            ao_assert(f_real <= f_pbclk / (  2 * n));

            // Baud rate error.

            if (f_real >= f)    { f_error = f_real - f; }

            else                { f_error = f - f_real; }

            if (f_error <= f_error_min)
            {
                if (f_error < f_error_min)
                {
                    sample_error_min = UINT32_MAX;
                }

                n2 = sjw;

                nx = n - ns - n2;

                if (nx > 16)
                {
                    n2 = n2 + (nx - 16);
                    nx = 16;
                }

                ao_assert(n2 >= sjw);

                ao_assert(n2 >= 1);
                ao_assert(n2 <= 8);

                ao_assert(nx >= 1);
                ao_assert(nx <= 16);

                while (n2 <= nx && n2 <= 8 && sample_error_min != 0)
                {
                    // Sample.

                    sample_real = 100000 * (ns + nx) / n;

                    // Sample error.

                    if (sample_real >= sample)  { sample_error = sample_real - sample; }

                    else                        { sample_error = sample - sample_real; }

                    if (sample_error < sample_error_min)
                    {
                        np = nx / 2;

                        n1 = nx - np;

                        sample_thrice_real = brp <= 3 ? 0 : sample_thrice;

                        r.reg = 0;

                        r.bits.brp = brp - 1;

                        r.bits.prseg = np - 1;

                        r.bits.sam = sample_thrice_real ? 1 : 0;

                        r.bits.seg1ph = n1 - 1;

                        r.bits.seg2ph = n2 - 1;

                        r.bits.seg2phts = 1;

                        r.bits.sjw = sjw - 1;

                        r.bits.wakfil = wake_up_filter ? 1 : 0;

                        x->brp = brp;

                        x->cfg = r.reg;

                        x->f_error = f_error;

                        x->f_real = f_real;

                        x->n = n;

                        x->n1 = n1;

                        x->n2 = n2;

                        x->np = np;

                        x->result = true;

                        x->sample_error = sample_error * 0.001;

                        x->sample_real = sample_real * 0.001;

                        x->sample_thrice_real = sample_thrice_real;

                        sample_error_min = sample_error;
                    }

                    n2++;
                    nx--;
                }

                f_error_min = f_error;
            }
        }

        n++;
    }
    while (n <= 25 && (f_error_min != 0 || sample_error_min != 0));
}

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#if defined AO_CAN_1 && AO_CAN_1

// ----------------------------------------------------------------------------

#if AO_CAN_BAUD_1 < AO_CAN_BAUD_MIN_1

#error Invalid configuration.

#endif

#if AO_CAN_BAUD_1 > AO_CAN_BAUD_MAX_1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_1 > 0  && AO_CAN_BUFFERS_1_0  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 1  && AO_CAN_BUFFERS_1_1  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 2  && AO_CAN_BUFFERS_1_2  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 3  && AO_CAN_BUFFERS_1_3  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 4  && AO_CAN_BUFFERS_1_4  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 5  && AO_CAN_BUFFERS_1_5  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 6  && AO_CAN_BUFFERS_1_6  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 7  && AO_CAN_BUFFERS_1_7  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 8  && AO_CAN_BUFFERS_1_8  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 9  && AO_CAN_BUFFERS_1_9  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 10 && AO_CAN_BUFFERS_1_10 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 11 && AO_CAN_BUFFERS_1_11 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 12 && AO_CAN_BUFFERS_1_12 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 13 && AO_CAN_BUFFERS_1_13 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 14 && AO_CAN_BUFFERS_1_14 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 15 && AO_CAN_BUFFERS_1_15 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 16 && AO_CAN_BUFFERS_1_16 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 17 && AO_CAN_BUFFERS_1_17 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 18 && AO_CAN_BUFFERS_1_18 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 19 && AO_CAN_BUFFERS_1_19 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 20 && AO_CAN_BUFFERS_1_20 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 21 && AO_CAN_BUFFERS_1_21 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 22 && AO_CAN_BUFFERS_1_22 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 23 && AO_CAN_BUFFERS_1_23 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 24 && AO_CAN_BUFFERS_1_24 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 25 && AO_CAN_BUFFERS_1_25 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 26 && AO_CAN_BUFFERS_1_26 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 27 && AO_CAN_BUFFERS_1_27 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 28 && AO_CAN_BUFFERS_1_28 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 29 && AO_CAN_BUFFERS_1_29 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 30 && AO_CAN_BUFFERS_1_30 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 31 && AO_CAN_BUFFERS_1_31 < 1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_1 > 0  && AO_CAN_BUFFERS_1_0  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 1  && AO_CAN_BUFFERS_1_1  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 2  && AO_CAN_BUFFERS_1_2  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 3  && AO_CAN_BUFFERS_1_3  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 4  && AO_CAN_BUFFERS_1_4  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 5  && AO_CAN_BUFFERS_1_5  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 6  && AO_CAN_BUFFERS_1_6  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 7  && AO_CAN_BUFFERS_1_7  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 8  && AO_CAN_BUFFERS_1_8  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 9  && AO_CAN_BUFFERS_1_9  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 10 && AO_CAN_BUFFERS_1_10 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 11 && AO_CAN_BUFFERS_1_11 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 12 && AO_CAN_BUFFERS_1_12 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 13 && AO_CAN_BUFFERS_1_13 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 14 && AO_CAN_BUFFERS_1_14 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 15 && AO_CAN_BUFFERS_1_15 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 16 && AO_CAN_BUFFERS_1_16 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 17 && AO_CAN_BUFFERS_1_17 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 18 && AO_CAN_BUFFERS_1_18 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 19 && AO_CAN_BUFFERS_1_19 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 20 && AO_CAN_BUFFERS_1_20 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 21 && AO_CAN_BUFFERS_1_21 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 22 && AO_CAN_BUFFERS_1_22 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 23 && AO_CAN_BUFFERS_1_23 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 24 && AO_CAN_BUFFERS_1_24 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 25 && AO_CAN_BUFFERS_1_25 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 26 && AO_CAN_BUFFERS_1_26 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 27 && AO_CAN_BUFFERS_1_27 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 28 && AO_CAN_BUFFERS_1_28 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 29 && AO_CAN_BUFFERS_1_29 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 30 && AO_CAN_BUFFERS_1_30 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_1 > 31 && AO_CAN_BUFFERS_1_31 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_1 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_RX_1 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_TX_1 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_EID_1_0  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_1  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_2  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_3  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_4  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_5  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_6  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_7  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_8  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_9  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_10 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_11 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_12 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_13 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_14 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_15 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_16 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_17 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_18 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_19 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_20 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_21 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_22 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_23 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_24 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_25 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_26 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_27 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_28 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_29 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_30 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_1_31 > 0x3FFFF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_FIFO_1_0  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_1  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_2  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_3  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_4  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_5  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_6  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_7  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_8  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_9  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_10 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_11 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_12 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_13 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_14 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_15 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_16 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_17 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_18 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_19 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_20 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_21 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_22 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_23 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_24 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_25 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_26 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_27 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_28 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_29 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_30 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_1_31 > 31

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_IDE_1_0  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_1  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_2  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_3  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_4  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_5  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_6  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_7  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_8  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_9  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_10 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_11 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_12 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_13 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_14 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_15 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_16 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_17 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_18 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_19 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_20 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_21 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_22 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_23 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_24 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_25 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_26 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_27 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_28 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_29 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_30 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_1_31 > 0x1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_1_0  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_1  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_2  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_3  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_4  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_5  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_6  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_7  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_8  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_9  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_10 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_11 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_12 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_13 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_14 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_15 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_16 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_17 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_18 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_19 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_20 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_21 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_22 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_23 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_24 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_25 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_26 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_27 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_28 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_29 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_30 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_1_31 > 3

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_EID_1_0 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_1_1 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_1_2 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_1_3 > 0x3FFFF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_IDE_1_0 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_1_1 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_1_2 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_1_3 > 0x1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_SID_1_0 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_1_1 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_1_2 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_1_3 > 0x7FF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_SID_1_0  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_1  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_2  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_3  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_4  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_5  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_6  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_7  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_8  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_9  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_10 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_11 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_12 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_13 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_14 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_15 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_16 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_17 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_18 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_19 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_20 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_21 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_22 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_23 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_24 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_25 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_26 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_27 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_28 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_29 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_30 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_1_31 > 0x7FF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#define AO_CAN_RXOF_1           ((AO_CAN_RX_1)      && (AO_CAN_OVERFLOW_1))

#define AO_CAN_TXST_1           ((AO_CAN_TX_1)      && (AO_CAN_SENT_1))

#define AO_CAN_TXUF_1           ((AO_CAN_TX_1)      && (AO_CAN_UNDERFLOW_1))

// ----------------------------------------------------------------------------

#define AO_CAN_RBOV_1           ((AO_CAN_RXOF_1)    || (AO_CAN_TXUF_1))

// ----------------------------------------------------------------------------

static  void                    ao_can_change_1(    uint32_t mode);

static  void                    ao_can_started_1();

static  void                    ao_can_starting_1();

static  void                    ao_can_stopping_1();

static  void                    ao_can_task_proc_1( void * x);

// ----------------------------------------------------------------------------

        ao_can_t                ao_can_buffers_1    [AO_CAN_BUFFERS_1];

// ----------------------------------------------------------------------------

#if AO_CAN_BUS_1

static  ao_can_bus_info_t       ao_can_bus_info_1;

#endif

#if AO_CAN_INVALID_1

static  ao_can_invalid_info_t   ao_can_invalid_info_1;

#endif

#if AO_CAN_MODE_1

static  ao_can_mode_info_t      ao_can_mode_info_1;

#endif

#if AO_CAN_RXOF_1

static  ao_can_overflow_info_t  ao_can_overflow_info_1;

#endif

#if AO_CAN_SYSTEM_1

static  ao_can_system_info_t    ao_can_system_info_1;

#endif

#if AO_CAN_TIMER_1

static  ao_can_timer_info_t     ao_can_timer_info_1;

#endif

#if AO_CAN_TXST_1

static  ao_can_sent_info_t      ao_can_sent_info_1;

#endif

#if AO_CAN_TXUF_1

static  ao_can_underflow_info_t ao_can_underflow_info_1;

#endif

#if AO_CAN_WAKE_UP_1

static  ao_can_wake_up_info_t   ao_can_wake_up_info_1;

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_RX_1

// ----------------------------------------------------------------------------

static  ao_can_t                ao_can_in_can_1     [AO_CAN_FIFOS_RX_1];

        ao_send_obj_t           ao_can_in_1         [AO_CAN_FIFOS_RX_1] =
{

#if AO_CAN_FIFOS_RX_1 >  0

#if AO_CAN_FIFOS_RX_1 >  0

{
        .ptr                    = ao_can_in_can_1 +  0
},

#endif

#if AO_CAN_FIFOS_RX_1 >  1

{
        .ptr                    = ao_can_in_can_1 +  1
},

#endif

#if AO_CAN_FIFOS_RX_1 >  2

{
        .ptr                    = ao_can_in_can_1 +  2
},

#endif

#if AO_CAN_FIFOS_RX_1 >  3

{
        .ptr                    = ao_can_in_can_1 +  3
},

#endif

#if AO_CAN_FIFOS_RX_1 >  4

{
        .ptr                    = ao_can_in_can_1 +  4
},

#endif

#if AO_CAN_FIFOS_RX_1 >  5

{
        .ptr                    = ao_can_in_can_1 +  5
},

#endif

#if AO_CAN_FIFOS_RX_1 >  6

{
        .ptr                    = ao_can_in_can_1 +  6
},

#endif

#if AO_CAN_FIFOS_RX_1 >  7

{
        .ptr                    = ao_can_in_can_1 +  7
},

#endif

#if AO_CAN_FIFOS_RX_1 >  8

{
        .ptr                    = ao_can_in_can_1 +  8
},

#endif

#if AO_CAN_FIFOS_RX_1 >  9

{
        .ptr                    = ao_can_in_can_1 +  9
},

#endif

#if AO_CAN_FIFOS_RX_1 > 10

{
        .ptr                    = ao_can_in_can_1 + 10
},

#endif

#if AO_CAN_FIFOS_RX_1 > 11

{
        .ptr                    = ao_can_in_can_1 + 11
},

#endif

#if AO_CAN_FIFOS_RX_1 > 12

{
        .ptr                    = ao_can_in_can_1 + 12
},

#endif

#if AO_CAN_FIFOS_RX_1 > 13

{
        .ptr                    = ao_can_in_can_1 + 13
},

#endif

#if AO_CAN_FIFOS_RX_1 > 14

{
        .ptr                    = ao_can_in_can_1 + 14
},

#endif

#if AO_CAN_FIFOS_RX_1 > 15

{
        .ptr                    = ao_can_in_can_1 + 15
},

#endif

#if AO_CAN_FIFOS_RX_1 > 16

{
        .ptr                    = ao_can_in_can_1 + 16
},

#endif

#if AO_CAN_FIFOS_RX_1 > 17

{
        .ptr                    = ao_can_in_can_1 + 17
},

#endif

#if AO_CAN_FIFOS_RX_1 > 18

{
        .ptr                    = ao_can_in_can_1 + 18
},

#endif

#if AO_CAN_FIFOS_RX_1 > 19

{
        .ptr                    = ao_can_in_can_1 + 19
},

#endif

#if AO_CAN_FIFOS_RX_1 > 20

{
        .ptr                    = ao_can_in_can_1 + 20
},

#endif

#if AO_CAN_FIFOS_RX_1 > 21

{
        .ptr                    = ao_can_in_can_1 + 21
},

#endif

#if AO_CAN_FIFOS_RX_1 > 22

{
        .ptr                    = ao_can_in_can_1 + 22
},

#endif

#if AO_CAN_FIFOS_RX_1 > 23

{
        .ptr                    = ao_can_in_can_1 + 23
},

#endif

#if AO_CAN_FIFOS_RX_1 > 24

{
        .ptr                    = ao_can_in_can_1 + 24
},

#endif

#if AO_CAN_FIFOS_RX_1 > 25

{
        .ptr                    = ao_can_in_can_1 + 25
},

#endif

#if AO_CAN_FIFOS_RX_1 > 26

{
        .ptr                    = ao_can_in_can_1 + 26
},

#endif

#if AO_CAN_FIFOS_RX_1 > 27

{
        .ptr                    = ao_can_in_can_1 + 27
},

#endif

#if AO_CAN_FIFOS_RX_1 > 28

{
        .ptr                    = ao_can_in_can_1 + 28
},

#endif

#if AO_CAN_FIFOS_RX_1 > 29

{
        .ptr                    = ao_can_in_can_1 + 29
},

#endif

#if AO_CAN_FIFOS_RX_1 > 30

{
        .ptr                    = ao_can_in_can_1 + 30
},

#endif

#if AO_CAN_FIFOS_RX_1 > 31

{
        .ptr                    = ao_can_in_can_1 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

#endif

#if AO_CAN_TX_1

// ----------------------------------------------------------------------------

static  ao_can_t                ao_can_out_can_1    [AO_CAN_FIFOS_TX_1];

        ao_recv_obj_t           ao_can_out_1        [AO_CAN_FIFOS_TX_1] =
{

#if AO_CAN_FIFOS_TX_1 >  0

#if AO_CAN_FIFOS_TX_1 >  0

{
        .ptr                    = ao_can_out_can_1 +  0
},

#endif

#if AO_CAN_FIFOS_TX_1 >  1

{
        .ptr                    = ao_can_out_can_1 +  1
},

#endif

#if AO_CAN_FIFOS_TX_1 >  2

{
        .ptr                    = ao_can_out_can_1 +  2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  3

{
        .ptr                    = ao_can_out_can_1 +  3
},

#endif

#if AO_CAN_FIFOS_TX_1 >  4

{
        .ptr                    = ao_can_out_can_1 +  4
},

#endif

#if AO_CAN_FIFOS_TX_1 >  5

{
        .ptr                    = ao_can_out_can_1 +  5
},

#endif

#if AO_CAN_FIFOS_TX_1 >  6

{
        .ptr                    = ao_can_out_can_1 +  6
},

#endif

#if AO_CAN_FIFOS_TX_1 >  7

{
        .ptr                    = ao_can_out_can_1 +  7
},

#endif

#if AO_CAN_FIFOS_TX_1 >  8

{
        .ptr                    = ao_can_out_can_1 +  8
},

#endif

#if AO_CAN_FIFOS_TX_1 >  9

{
        .ptr                    = ao_can_out_can_1 +  9
},

#endif

#if AO_CAN_FIFOS_TX_1 > 10

{
        .ptr                    = ao_can_out_can_1 + 10
},

#endif

#if AO_CAN_FIFOS_TX_1 > 11

{
        .ptr                    = ao_can_out_can_1 + 11
},

#endif

#if AO_CAN_FIFOS_TX_1 > 12

{
        .ptr                    = ao_can_out_can_1 + 12
},

#endif

#if AO_CAN_FIFOS_TX_1 > 13

{
        .ptr                    = ao_can_out_can_1 + 13
},

#endif

#if AO_CAN_FIFOS_TX_1 > 14

{
        .ptr                    = ao_can_out_can_1 + 14
},

#endif

#if AO_CAN_FIFOS_TX_1 > 15

{
        .ptr                    = ao_can_out_can_1 + 15
},

#endif

#if AO_CAN_FIFOS_TX_1 > 16

{
        .ptr                    = ao_can_out_can_1 + 16
},

#endif

#if AO_CAN_FIFOS_TX_1 > 17

{
        .ptr                    = ao_can_out_can_1 + 17
},

#endif

#if AO_CAN_FIFOS_TX_1 > 18

{
        .ptr                    = ao_can_out_can_1 + 18
},

#endif

#if AO_CAN_FIFOS_TX_1 > 19

{
        .ptr                    = ao_can_out_can_1 + 19
},

#endif

#if AO_CAN_FIFOS_TX_1 > 20

{
        .ptr                    = ao_can_out_can_1 + 20
},

#endif

#if AO_CAN_FIFOS_TX_1 > 21

{
        .ptr                    = ao_can_out_can_1 + 21
},

#endif

#if AO_CAN_FIFOS_TX_1 > 22

{
        .ptr                    = ao_can_out_can_1 + 22
},

#endif

#if AO_CAN_FIFOS_TX_1 > 23

{
        .ptr                    = ao_can_out_can_1 + 23
},

#endif

#if AO_CAN_FIFOS_TX_1 > 24

{
        .ptr                    = ao_can_out_can_1 + 24
},

#endif

#if AO_CAN_FIFOS_TX_1 > 25

{
        .ptr                    = ao_can_out_can_1 + 25
},

#endif

#if AO_CAN_FIFOS_TX_1 > 26

{
        .ptr                    = ao_can_out_can_1 + 26
},

#endif

#if AO_CAN_FIFOS_TX_1 > 27

{
        .ptr                    = ao_can_out_can_1 + 27
},

#endif

#if AO_CAN_FIFOS_TX_1 > 28

{
        .ptr                    = ao_can_out_can_1 + 28
},

#endif

#if AO_CAN_FIFOS_TX_1 > 29

{
        .ptr                    = ao_can_out_can_1 + 29
},

#endif

#if AO_CAN_FIFOS_TX_1 > 30

{
        .ptr                    = ao_can_out_can_1 + 30
},

#endif

#if AO_CAN_FIFOS_TX_1 > 31

{
        .ptr                    = ao_can_out_can_1 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_change_1;

static  ao_cond_wait_t          ao_can_cond_change_wait_1 =
{
        .cond                   = &ao_can_cond_change_1
};

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_changed_1;

static  ao_cond_wait_t          ao_can_cond_changed_wait_1 =
{
        .cond                   = &ao_can_cond_changed_1
};

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_not_full_1      [AO_CAN_FIFOS_TX_1];

static  ao_cond_wait_t          ao_can_cond_not_full_wait_1 [AO_CAN_FIFOS_TX_1] =
{

#if AO_CAN_FIFOS_TX_1 >  0

#if AO_CAN_FIFOS_TX_1 >  0

{
        .cond                   = ao_can_cond_not_full_1 +  0
},

#endif

#if AO_CAN_FIFOS_TX_1 >  1

{
        .cond                   = ao_can_cond_not_full_1 +  1
},

#endif

#if AO_CAN_FIFOS_TX_1 >  2

{
        .cond                   = ao_can_cond_not_full_1 +  2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  3

{
        .cond                   = ao_can_cond_not_full_1 +  3
},

#endif

#if AO_CAN_FIFOS_TX_1 >  4

{
        .cond                   = ao_can_cond_not_full_1 +  4
},

#endif

#if AO_CAN_FIFOS_TX_1 >  5

{
        .cond                   = ao_can_cond_not_full_1 +  5
},

#endif

#if AO_CAN_FIFOS_TX_1 >  6

{
        .cond                   = ao_can_cond_not_full_1 +  6
},

#endif

#if AO_CAN_FIFOS_TX_1 >  7

{
        .cond                   = ao_can_cond_not_full_1 +  7
},

#endif

#if AO_CAN_FIFOS_TX_1 >  8

{
        .cond                   = ao_can_cond_not_full_1 +  8
},

#endif

#if AO_CAN_FIFOS_TX_1 >  9

{
        .cond                   = ao_can_cond_not_full_1 +  9
},

#endif

#if AO_CAN_FIFOS_TX_1 > 10

{
        .cond                   = ao_can_cond_not_full_1 + 10
},

#endif

#if AO_CAN_FIFOS_TX_1 > 11

{
        .cond                   = ao_can_cond_not_full_1 + 11
},

#endif

#if AO_CAN_FIFOS_TX_1 > 12

{
        .cond                   = ao_can_cond_not_full_1 + 12
},

#endif

#if AO_CAN_FIFOS_TX_1 > 13

{
        .cond                   = ao_can_cond_not_full_1 + 13
},

#endif

#if AO_CAN_FIFOS_TX_1 > 14

{
        .cond                   = ao_can_cond_not_full_1 + 14
},

#endif

#if AO_CAN_FIFOS_TX_1 > 15

{
        .cond                   = ao_can_cond_not_full_1 + 15
},

#endif

#if AO_CAN_FIFOS_TX_1 > 16

{
        .cond                   = ao_can_cond_not_full_1 + 16
},

#endif

#if AO_CAN_FIFOS_TX_1 > 17

{
        .cond                   = ao_can_cond_not_full_1 + 17
},

#endif

#if AO_CAN_FIFOS_TX_1 > 18

{
        .cond                   = ao_can_cond_not_full_1 + 18
},

#endif

#if AO_CAN_FIFOS_TX_1 > 19

{
        .cond                   = ao_can_cond_not_full_1 + 19
},

#endif

#if AO_CAN_FIFOS_TX_1 > 20

{
        .cond                   = ao_can_cond_not_full_1 + 20
},

#endif

#if AO_CAN_FIFOS_TX_1 > 21

{
        .cond                   = ao_can_cond_not_full_1 + 21
},

#endif

#if AO_CAN_FIFOS_TX_1 > 22

{
        .cond                   = ao_can_cond_not_full_1 + 22
},

#endif

#if AO_CAN_FIFOS_TX_1 > 23

{
        .cond                   = ao_can_cond_not_full_1 + 23
},

#endif

#if AO_CAN_FIFOS_TX_1 > 24

{
        .cond                   = ao_can_cond_not_full_1 + 24
},

#endif

#if AO_CAN_FIFOS_TX_1 > 25

{
        .cond                   = ao_can_cond_not_full_1 + 25
},

#endif

#if AO_CAN_FIFOS_TX_1 > 26

{
        .cond                   = ao_can_cond_not_full_1 + 26
},

#endif

#if AO_CAN_FIFOS_TX_1 > 27

{
        .cond                   = ao_can_cond_not_full_1 + 27
},

#endif

#if AO_CAN_FIFOS_TX_1 > 28

{
        .cond                   = ao_can_cond_not_full_1 + 28
},

#endif

#if AO_CAN_FIFOS_TX_1 > 29

{
        .cond                   = ao_can_cond_not_full_1 + 29
},

#endif

#if AO_CAN_FIFOS_TX_1 > 30

{
        .cond                   = ao_can_cond_not_full_1 + 30
},

#endif

#if AO_CAN_FIFOS_TX_1 > 31

{
        .cond                   = ao_can_cond_not_full_1 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

static  ao_sem_t                ao_can_sem_1;

static  ao_sem_take_t           ao_can_sem_take_1 =
{
        .count                  = 1,

        .sem                    = &ao_can_sem_1
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_can_task_1 =
{
        .proc                   = ao_can_task_proc_1
};

// ----------------------------------------------------------------------------

static  uint32_t    volatile    ao_can_var_mode_1 = 0;

static  bool        volatile    ao_can_var_started_1 = false;

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_change_store_1 [2] =
{
        &ao_can_cond_changed_wait_1.async,

        &ao_can_sem_take_1.async
};

static  ao_async_any_t          ao_can_async_change_1 =
{
        .store                  = ao_can_async_change_store_1,

        .count                  = 2
};

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_send_store_1   [AO_CAN_FIFOS_TX_1 * 2] =
{

#if AO_CAN_FIFOS_TX_1 >  0

#if AO_CAN_FIFOS_TX_1 >  0

        &ao_can_cond_not_full_wait_1[ 0].async,

        &ao_can_out_1               [ 0].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  1

        &ao_can_cond_not_full_wait_1[ 1].async,

        &ao_can_out_1               [ 1].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  2

        &ao_can_cond_not_full_wait_1[ 2].async,

        &ao_can_out_1               [ 2].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  3

        &ao_can_cond_not_full_wait_1[ 3].async,

        &ao_can_out_1               [ 3].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  4

        &ao_can_cond_not_full_wait_1[ 4].async,

        &ao_can_out_1               [ 4].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  5

        &ao_can_cond_not_full_wait_1[ 5].async,

        &ao_can_out_1               [ 5].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  6

        &ao_can_cond_not_full_wait_1[ 6].async,

        &ao_can_out_1               [ 6].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  7

        &ao_can_cond_not_full_wait_1[ 7].async,

        &ao_can_out_1               [ 7].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  8

        &ao_can_cond_not_full_wait_1[ 8].async,

        &ao_can_out_1               [ 8].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  9

        &ao_can_cond_not_full_wait_1[ 9].async,

        &ao_can_out_1               [ 9].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 10

        &ao_can_cond_not_full_wait_1[10].async,

        &ao_can_out_1               [10].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 11

        &ao_can_cond_not_full_wait_1[11].async,

        &ao_can_out_1               [11].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 12

        &ao_can_cond_not_full_wait_1[12].async,

        &ao_can_out_1               [12].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 13

        &ao_can_cond_not_full_wait_1[13].async,

        &ao_can_out_1               [13].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 14

        &ao_can_cond_not_full_wait_1[14].async,

        &ao_can_out_1               [14].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 15

        &ao_can_cond_not_full_wait_1[15].async,

        &ao_can_out_1               [15].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 16

        &ao_can_cond_not_full_wait_1[16].async,

        &ao_can_out_1               [16].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 17

        &ao_can_cond_not_full_wait_1[17].async,

        &ao_can_out_1               [17].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 18

        &ao_can_cond_not_full_wait_1[18].async,

        &ao_can_out_1               [18].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 19

        &ao_can_cond_not_full_wait_1[19].async,

        &ao_can_out_1               [19].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 20

        &ao_can_cond_not_full_wait_1[20].async,

        &ao_can_out_1               [20].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 21

        &ao_can_cond_not_full_wait_1[21].async,

        &ao_can_out_1               [21].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 22

        &ao_can_cond_not_full_wait_1[22].async,

        &ao_can_out_1               [22].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 23

        &ao_can_cond_not_full_wait_1[23].async,

        &ao_can_out_1               [23].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 24

        &ao_can_cond_not_full_wait_1[24].async,

        &ao_can_out_1               [24].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 25

        &ao_can_cond_not_full_wait_1[25].async,

        &ao_can_out_1               [25].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 26

        &ao_can_cond_not_full_wait_1[26].async,

        &ao_can_out_1               [26].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 27

        &ao_can_cond_not_full_wait_1[27].async,

        &ao_can_out_1               [27].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 28

        &ao_can_cond_not_full_wait_1[28].async,

        &ao_can_out_1               [28].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 29

        &ao_can_cond_not_full_wait_1[29].async,

        &ao_can_out_1               [29].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 30

        &ao_can_cond_not_full_wait_1[30].async,

        &ao_can_out_1               [30].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 31

        &ao_can_cond_not_full_wait_1[31].async,

        &ao_can_out_1               [31].async,

#endif

#endif

};

static  ao_async_all_t          ao_can_async_send_1         [AO_CAN_FIFOS_TX_1] =
{

#if AO_CAN_FIFOS_TX_1 >  0

#if AO_CAN_FIFOS_TX_1 >  0

{
        .store                  = ao_can_async_send_store_1 +  0 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  1

{
        .store                  = ao_can_async_send_store_1 +  1 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  2

{
        .store                  = ao_can_async_send_store_1 +  2 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  3

{
        .store                  = ao_can_async_send_store_1 +  3 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  4

{
        .store                  = ao_can_async_send_store_1 +  4 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  5

{
        .store                  = ao_can_async_send_store_1 +  5 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  6

{
        .store                  = ao_can_async_send_store_1 +  6 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  7

{
        .store                  = ao_can_async_send_store_1 +  7 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  8

{
        .store                  = ao_can_async_send_store_1 +  8 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 >  9

{
        .store                  = ao_can_async_send_store_1 +  9 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 10

{
        .store                  = ao_can_async_send_store_1 + 10 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 11

{
        .store                  = ao_can_async_send_store_1 + 11 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 12

{
        .store                  = ao_can_async_send_store_1 + 12 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 13

{
        .store                  = ao_can_async_send_store_1 + 13 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 14

{
        .store                  = ao_can_async_send_store_1 + 14 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 15

{
        .store                  = ao_can_async_send_store_1 + 15 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 16

{
        .store                  = ao_can_async_send_store_1 + 16 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 17

{
        .store                  = ao_can_async_send_store_1 + 17 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 18

{
        .store                  = ao_can_async_send_store_1 + 18 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 19

{
        .store                  = ao_can_async_send_store_1 + 19 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 20

{
        .store                  = ao_can_async_send_store_1 + 20 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 21

{
        .store                  = ao_can_async_send_store_1 + 21 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 22

{
        .store                  = ao_can_async_send_store_1 + 22 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 23

{
        .store                  = ao_can_async_send_store_1 + 23 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 24

{
        .store                  = ao_can_async_send_store_1 + 24 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 25

{
        .store                  = ao_can_async_send_store_1 + 25 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 26

{
        .store                  = ao_can_async_send_store_1 + 26 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 27

{
        .store                  = ao_can_async_send_store_1 + 27 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 28

{
        .store                  = ao_can_async_send_store_1 + 28 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 29

{
        .store                  = ao_can_async_send_store_1 + 29 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 30

{
        .store                  = ao_can_async_send_store_1 + 30 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_1 > 31

{
        .store                  = ao_can_async_send_store_1 + 31 * 2,

        .count                  = 2
},

#endif

#endif

};

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_started_store_1[AO_CAN_FIFOS_TX_1 + 2] =
{
        &ao_can_cond_change_wait_1.async,

        &ao_can_sem_take_1.async,

#if AO_CAN_FIFOS_TX_1 >  0

#if AO_CAN_FIFOS_TX_1 >  0

        &ao_can_async_send_1[ 0].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  1

        &ao_can_async_send_1[ 1].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  2

        &ao_can_async_send_1[ 2].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  3

        &ao_can_async_send_1[ 3].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  4

        &ao_can_async_send_1[ 4].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  5

        &ao_can_async_send_1[ 5].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  6

        &ao_can_async_send_1[ 6].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  7

        &ao_can_async_send_1[ 7].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  8

        &ao_can_async_send_1[ 8].async,

#endif

#if AO_CAN_FIFOS_TX_1 >  9

        &ao_can_async_send_1[ 9].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 10

        &ao_can_async_send_1[10].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 11

        &ao_can_async_send_1[11].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 12

        &ao_can_async_send_1[12].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 13

        &ao_can_async_send_1[13].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 14

        &ao_can_async_send_1[14].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 15

        &ao_can_async_send_1[15].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 16

        &ao_can_async_send_1[16].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 17

        &ao_can_async_send_1[17].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 18

        &ao_can_async_send_1[18].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 19

        &ao_can_async_send_1[19].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 20

        &ao_can_async_send_1[20].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 21

        &ao_can_async_send_1[21].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 22

        &ao_can_async_send_1[22].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 23

        &ao_can_async_send_1[23].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 24

        &ao_can_async_send_1[24].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 25

        &ao_can_async_send_1[25].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 26

        &ao_can_async_send_1[26].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 27

        &ao_can_async_send_1[27].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 28

        &ao_can_async_send_1[28].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 29

        &ao_can_async_send_1[29].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 30

        &ao_can_async_send_1[30].async,

#endif

#if AO_CAN_FIFOS_TX_1 > 31

        &ao_can_async_send_1[31].async,

#endif

#endif

};

static  ao_async_any_t          ao_can_async_started_1 =
{
        .store                  = ao_can_async_started_store_1,

        .count                  = 2 + AO_CAN_FIFOS_TX_1
};

// ----------------------------------------------------------------------------

void ao_can_change_1(uint32_t mode)
{
    // Assert.

    ao_assert
    (
        mode == 0 ||
        mode == 2 ||
        mode == 3 ||
        mode == 4 ||
        mode == 7
    );


    // Variables.

    ao_can_reg_t * const reg = ao_can_reg_1();


    // Ready.

    while (reg->con.bits.opmod != mode)
    {
        // Request.

        ao_cond_clear(&ao_can_cond_changed_1);

        reg->con.bits.reqop = mode;


        // Await.

        ao_cond_wait_begin( &ao_can_cond_changed_wait_1);

        ao_sem_take_begin(  &ao_can_sem_take_1);

        ao_await_any_forever
        (
            &ao_can_async_change_1
        );

        ao_sem_take_end(    &ao_can_sem_take_1);

        ao_cond_wait_end(   &ao_can_cond_changed_wait_1);


        // Stop.

        if (ao_can_sem_take_1.result)
        {
            ao_can_var_started_1 = false;
        }
    }
}

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_can_config_1()
{
    ao_can_config_baud_1();

    ao_can_config_fifos_1();

    ao_can_config_filter_masks_1();

    ao_can_config_filters_1();
}

__attribute__ ((weak))
void ao_can_config_baud_1()
{
    // Variables.

    ao_can_baud_t x;


    // Ready.

    x.f                 = AO_CAN_BAUD_1;

    x.f_pbclk           = AO_SYS_CLOCK_CAN1;

    x.sample            = AO_CAN_BAUD_SAMPLE_1;

    x.sample_thrice     = AO_CAN_BAUD_SAMPLE_THRICE_1;

    x.sjw               = AO_CAN_BAUD_SJW_1;

    x.wake_up_filter    = AO_CAN_BAUD_WAKE_UP_FILTER_1;

    ao_can_baud(&x);

    ao_assert(x.result);

    C1CFG = x.cfg;
}

__attribute__ ((weak))
void ao_can_config_fifos_1()
{
    // Fifo base address.

    C1FIFOBA = KVA_TO_PA(ao_can_buffers_1);


    // Fifos.

#if AO_CAN_FIFOS_1 > 0

#if AO_CAN_FIFOS_1 > 0

    C1FIFOCON0bits.FSIZE = AO_CAN_BUFFERS_1_0 - 1;

#endif

#if AO_CAN_FIFOS_1 > 1

    C1FIFOCON1bits.FSIZE = AO_CAN_BUFFERS_1_1 - 1;

#endif

#if AO_CAN_FIFOS_1 > 2

    C1FIFOCON2bits.FSIZE = AO_CAN_BUFFERS_1_2 - 1;

#endif

#if AO_CAN_FIFOS_1 > 3

    C1FIFOCON3bits.FSIZE = AO_CAN_BUFFERS_1_3 - 1;

#endif

#if AO_CAN_FIFOS_1 > 4

    C1FIFOCON4bits.FSIZE = AO_CAN_BUFFERS_1_4 - 1;

#endif

#if AO_CAN_FIFOS_1 > 5

    C1FIFOCON5bits.FSIZE = AO_CAN_BUFFERS_1_5 - 1;

#endif

#if AO_CAN_FIFOS_1 > 6

    C1FIFOCON6bits.FSIZE = AO_CAN_BUFFERS_1_6 - 1;

#endif

#if AO_CAN_FIFOS_1 > 7

    C1FIFOCON7bits.FSIZE = AO_CAN_BUFFERS_1_7 - 1;

#endif

#if AO_CAN_FIFOS_1 > 8

    C1FIFOCON8bits.FSIZE = AO_CAN_BUFFERS_1_8 - 1;

#endif

#if AO_CAN_FIFOS_1 > 9

    C1FIFOCON9bits.FSIZE = AO_CAN_BUFFERS_1_9 - 1;

#endif

#if AO_CAN_FIFOS_1 > 10

    C1FIFOCON10bits.FSIZE = AO_CAN_BUFFERS_1_10 - 1;

#endif

#if AO_CAN_FIFOS_1 > 11

    C1FIFOCON11bits.FSIZE = AO_CAN_BUFFERS_1_11 - 1;

#endif

#if AO_CAN_FIFOS_1 > 12

    C1FIFOCON12bits.FSIZE = AO_CAN_BUFFERS_1_12 - 1;

#endif

#if AO_CAN_FIFOS_1 > 13

    C1FIFOCON13bits.FSIZE = AO_CAN_BUFFERS_1_13 - 1;

#endif

#if AO_CAN_FIFOS_1 > 14

    C1FIFOCON14bits.FSIZE = AO_CAN_BUFFERS_1_14 - 1;

#endif

#if AO_CAN_FIFOS_1 > 15

    C1FIFOCON15bits.FSIZE = AO_CAN_BUFFERS_1_15 - 1;

#endif

#if AO_CAN_FIFOS_1 > 16

    C1FIFOCON16bits.FSIZE = AO_CAN_BUFFERS_1_16 - 1;

#endif

#if AO_CAN_FIFOS_1 > 17

    C1FIFOCON17bits.FSIZE = AO_CAN_BUFFERS_1_17 - 1;

#endif

#if AO_CAN_FIFOS_1 > 18

    C1FIFOCON18bits.FSIZE = AO_CAN_BUFFERS_1_18 - 1;

#endif

#if AO_CAN_FIFOS_1 > 19

    C1FIFOCON19bits.FSIZE = AO_CAN_BUFFERS_1_19 - 1;

#endif

#if AO_CAN_FIFOS_1 > 20

    C1FIFOCON20bits.FSIZE = AO_CAN_BUFFERS_1_20 - 1;

#endif

#if AO_CAN_FIFOS_1 > 21

    C1FIFOCON21bits.FSIZE = AO_CAN_BUFFERS_1_21 - 1;

#endif

#if AO_CAN_FIFOS_1 > 22

    C1FIFOCON22bits.FSIZE = AO_CAN_BUFFERS_1_22 - 1;

#endif

#if AO_CAN_FIFOS_1 > 23

    C1FIFOCON23bits.FSIZE = AO_CAN_BUFFERS_1_23 - 1;

#endif

#if AO_CAN_FIFOS_1 > 24

    C1FIFOCON24bits.FSIZE = AO_CAN_BUFFERS_1_24 - 1;

#endif

#if AO_CAN_FIFOS_1 > 25

    C1FIFOCON25bits.FSIZE = AO_CAN_BUFFERS_1_25 - 1;

#endif

#if AO_CAN_FIFOS_1 > 26

    C1FIFOCON26bits.FSIZE = AO_CAN_BUFFERS_1_26 - 1;

#endif

#if AO_CAN_FIFOS_1 > 27

    C1FIFOCON27bits.FSIZE = AO_CAN_BUFFERS_1_27 - 1;

#endif

#if AO_CAN_FIFOS_1 > 28

    C1FIFOCON28bits.FSIZE = AO_CAN_BUFFERS_1_28 - 1;

#endif

#if AO_CAN_FIFOS_1 > 29

    C1FIFOCON29bits.FSIZE = AO_CAN_BUFFERS_1_29 - 1;

#endif

#if AO_CAN_FIFOS_1 > 30

    C1FIFOCON30bits.FSIZE = AO_CAN_BUFFERS_1_30 - 1;

#endif

#if AO_CAN_FIFOS_1 > 31

    C1FIFOCON31bits.FSIZE = AO_CAN_BUFFERS_1_31 - 1;

#endif

#endif

}

__attribute__ ((weak))
void ao_can_config_filter_masks_1()
{
    C1RXM0bits.EID  = AO_CAN_FILTER_MASK_EID_1_0;
    C1RXM0bits.MIDE = AO_CAN_FILTER_MASK_IDE_1_0;
    C1RXM0bits.SID  = AO_CAN_FILTER_MASK_SID_1_0;

    C1RXM1bits.EID  = AO_CAN_FILTER_MASK_EID_1_1;
    C1RXM1bits.MIDE = AO_CAN_FILTER_MASK_IDE_1_1;
    C1RXM1bits.SID  = AO_CAN_FILTER_MASK_SID_1_1;

    C1RXM2bits.EID  = AO_CAN_FILTER_MASK_EID_1_2;
    C1RXM2bits.MIDE = AO_CAN_FILTER_MASK_IDE_1_2;
    C1RXM2bits.SID  = AO_CAN_FILTER_MASK_SID_1_2;

    C1RXM3bits.EID  = AO_CAN_FILTER_MASK_EID_1_3;
    C1RXM3bits.MIDE = AO_CAN_FILTER_MASK_IDE_1_3;
    C1RXM3bits.SID  = AO_CAN_FILTER_MASK_SID_1_3;
}

__attribute__ ((weak))
void ao_can_config_filters_1()
{

#if AO_CAN_FILTER_ENABLE_1_0

    C1RXF0bits.EID          = AO_CAN_FILTER_EID_1_0;
    C1RXF0bits.EXID         = AO_CAN_FILTER_IDE_1_0;
    C1RXF0bits.SID          = AO_CAN_FILTER_SID_1_0;
    C1FLTCON0bits.FSEL0     = AO_CAN_FILTER_FIFO_1_0;
    C1FLTCON0bits.MSEL0     = AO_CAN_FILTER_MASK_1_0;
    C1FLTCON0bits.FLTEN0    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_1

    C1RXF1bits.EID          = AO_CAN_FILTER_EID_1_1;
    C1RXF1bits.EXID         = AO_CAN_FILTER_IDE_1_1;
    C1RXF1bits.SID          = AO_CAN_FILTER_SID_1_1;
    C1FLTCON0bits.FSEL1     = AO_CAN_FILTER_FIFO_1_1;
    C1FLTCON0bits.MSEL1     = AO_CAN_FILTER_MASK_1_1;
    C1FLTCON0bits.FLTEN1    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_2

    C1RXF2bits.EID          = AO_CAN_FILTER_EID_1_2;
    C1RXF2bits.EXID         = AO_CAN_FILTER_IDE_1_2;
    C1RXF2bits.SID          = AO_CAN_FILTER_SID_1_2;
    C1FLTCON0bits.FSEL2     = AO_CAN_FILTER_FIFO_1_2;
    C1FLTCON0bits.MSEL2     = AO_CAN_FILTER_MASK_1_2;
    C1FLTCON0bits.FLTEN2    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_3

    C1RXF3bits.EID          = AO_CAN_FILTER_EID_1_3;
    C1RXF3bits.EXID         = AO_CAN_FILTER_IDE_1_3;
    C1RXF3bits.SID          = AO_CAN_FILTER_SID_1_3;
    C1FLTCON0bits.FSEL3     = AO_CAN_FILTER_FIFO_1_3;
    C1FLTCON0bits.MSEL3     = AO_CAN_FILTER_MASK_1_3;
    C1FLTCON0bits.FLTEN3    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_4

    C1RXF4bits.EID          = AO_CAN_FILTER_EID_1_4;
    C1RXF4bits.EXID         = AO_CAN_FILTER_IDE_1_4;
    C1RXF4bits.SID          = AO_CAN_FILTER_SID_1_4;
    C1FLTCON1bits.FSEL4     = AO_CAN_FILTER_FIFO_1_4;
    C1FLTCON1bits.MSEL4     = AO_CAN_FILTER_MASK_1_4;
    C1FLTCON1bits.FLTEN4    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_5

    C1RXF5bits.EID          = AO_CAN_FILTER_EID_1_5;
    C1RXF5bits.EXID         = AO_CAN_FILTER_IDE_1_5;
    C1RXF5bits.SID          = AO_CAN_FILTER_SID_1_5;
    C1FLTCON1bits.FSEL5     = AO_CAN_FILTER_FIFO_1_5;
    C1FLTCON1bits.MSEL5     = AO_CAN_FILTER_MASK_1_5;
    C1FLTCON1bits.FLTEN5    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_6

    C1RXF6bits.EID          = AO_CAN_FILTER_EID_1_6;
    C1RXF6bits.EXID         = AO_CAN_FILTER_IDE_1_6;
    C1RXF6bits.SID          = AO_CAN_FILTER_SID_1_6;
    C1FLTCON1bits.FSEL6     = AO_CAN_FILTER_FIFO_1_6;
    C1FLTCON1bits.MSEL6     = AO_CAN_FILTER_MASK_1_6;
    C1FLTCON1bits.FLTEN6    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_7

    C1RXF7bits.EID          = AO_CAN_FILTER_EID_1_7;
    C1RXF7bits.EXID         = AO_CAN_FILTER_IDE_1_7;
    C1RXF7bits.SID          = AO_CAN_FILTER_SID_1_7;
    C1FLTCON1bits.FSEL7     = AO_CAN_FILTER_FIFO_1_7;
    C1FLTCON1bits.MSEL7     = AO_CAN_FILTER_MASK_1_7;
    C1FLTCON1bits.FLTEN7    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_8

    C1RXF8bits.EID          = AO_CAN_FILTER_EID_1_8;
    C1RXF8bits.EXID         = AO_CAN_FILTER_IDE_1_8;
    C1RXF8bits.SID          = AO_CAN_FILTER_SID_1_8;
    C1FLTCON2bits.FSEL8     = AO_CAN_FILTER_FIFO_1_8;
    C1FLTCON2bits.MSEL8     = AO_CAN_FILTER_MASK_1_8;
    C1FLTCON2bits.FLTEN8    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_9

    C1RXF9bits.EID          = AO_CAN_FILTER_EID_1_9;
    C1RXF9bits.EXID         = AO_CAN_FILTER_IDE_1_9;
    C1RXF9bits.SID          = AO_CAN_FILTER_SID_1_9;
    C1FLTCON2bits.FSEL9     = AO_CAN_FILTER_FIFO_1_9;
    C1FLTCON2bits.MSEL9     = AO_CAN_FILTER_MASK_1_9;
    C1FLTCON2bits.FLTEN9    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_10

    C1RXF10bits.EID         = AO_CAN_FILTER_EID_1_10;
    C1RXF10bits.EXID        = AO_CAN_FILTER_IDE_1_10;
    C1RXF10bits.SID         = AO_CAN_FILTER_SID_1_10;
    C1FLTCON2bits.FSEL10    = AO_CAN_FILTER_FIFO_1_10;
    C1FLTCON2bits.MSEL10    = AO_CAN_FILTER_MASK_1_10;
    C1FLTCON2bits.FLTEN10   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_11

    C1RXF11bits.EID         = AO_CAN_FILTER_EID_1_11;
    C1RXF11bits.EXID        = AO_CAN_FILTER_IDE_1_11;
    C1RXF11bits.SID         = AO_CAN_FILTER_SID_1_11;
    C1FLTCON2bits.FSEL11    = AO_CAN_FILTER_FIFO_1_11;
    C1FLTCON2bits.MSEL11    = AO_CAN_FILTER_MASK_1_11;
    C1FLTCON2bits.FLTEN11   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_12

    C1RXF12bits.EID         = AO_CAN_FILTER_EID_1_12;
    C1RXF12bits.EXID        = AO_CAN_FILTER_IDE_1_12;
    C1RXF12bits.SID         = AO_CAN_FILTER_SID_1_12;
    C1FLTCON3bits.FSEL12    = AO_CAN_FILTER_FIFO_1_12;
    C1FLTCON3bits.MSEL12    = AO_CAN_FILTER_MASK_1_12;
    C1FLTCON3bits.FLTEN12   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_13

    C1RXF13bits.EID         = AO_CAN_FILTER_EID_1_13;
    C1RXF13bits.EXID        = AO_CAN_FILTER_IDE_1_13;
    C1RXF13bits.SID         = AO_CAN_FILTER_SID_1_13;
    C1FLTCON3bits.FSEL13    = AO_CAN_FILTER_FIFO_1_13;
    C1FLTCON3bits.MSEL13    = AO_CAN_FILTER_MASK_1_13;
    C1FLTCON3bits.FLTEN13   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_14

    C1RXF14bits.EID         = AO_CAN_FILTER_EID_1_14;
    C1RXF14bits.EXID        = AO_CAN_FILTER_IDE_1_14;
    C1RXF14bits.SID         = AO_CAN_FILTER_SID_1_14;
    C1FLTCON3bits.FSEL14    = AO_CAN_FILTER_FIFO_1_14;
    C1FLTCON3bits.MSEL14    = AO_CAN_FILTER_MASK_1_14;
    C1FLTCON3bits.FLTEN14   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_15

    C1RXF15bits.EID         = AO_CAN_FILTER_EID_1_15;
    C1RXF15bits.EXID        = AO_CAN_FILTER_IDE_1_15;
    C1RXF15bits.SID         = AO_CAN_FILTER_SID_1_15;
    C1FLTCON3bits.FSEL15    = AO_CAN_FILTER_FIFO_1_15;
    C1FLTCON3bits.MSEL15    = AO_CAN_FILTER_MASK_1_15;
    C1FLTCON3bits.FLTEN15   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_16

    C1RXF16bits.EID         = AO_CAN_FILTER_EID_1_16;
    C1RXF16bits.EXID        = AO_CAN_FILTER_IDE_1_16;
    C1RXF16bits.SID         = AO_CAN_FILTER_SID_1_16;
    C1FLTCON4bits.FSEL16    = AO_CAN_FILTER_FIFO_1_16;
    C1FLTCON4bits.MSEL16    = AO_CAN_FILTER_MASK_1_16;
    C1FLTCON4bits.FLTEN16   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_17

    C1RXF17bits.EID         = AO_CAN_FILTER_EID_1_17;
    C1RXF17bits.EXID        = AO_CAN_FILTER_IDE_1_17;
    C1RXF17bits.SID         = AO_CAN_FILTER_SID_1_17;
    C1FLTCON4bits.FSEL17    = AO_CAN_FILTER_FIFO_1_17;
    C1FLTCON4bits.MSEL17    = AO_CAN_FILTER_MASK_1_17;
    C1FLTCON4bits.FLTEN17   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_18

    C1RXF18bits.EID         = AO_CAN_FILTER_EID_1_18;
    C1RXF18bits.EXID        = AO_CAN_FILTER_IDE_1_18;
    C1RXF18bits.SID         = AO_CAN_FILTER_SID_1_18;
    C1FLTCON4bits.FSEL18    = AO_CAN_FILTER_FIFO_1_18;
    C1FLTCON4bits.MSEL18    = AO_CAN_FILTER_MASK_1_18;
    C1FLTCON4bits.FLTEN18   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_19

    C1RXF19bits.EID         = AO_CAN_FILTER_EID_1_19;
    C1RXF19bits.EXID        = AO_CAN_FILTER_IDE_1_19;
    C1RXF19bits.SID         = AO_CAN_FILTER_SID_1_19;
    C1FLTCON4bits.FSEL19    = AO_CAN_FILTER_FIFO_1_19;
    C1FLTCON4bits.MSEL19    = AO_CAN_FILTER_MASK_1_19;
    C1FLTCON4bits.FLTEN19   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_20

    C1RXF20bits.EID         = AO_CAN_FILTER_EID_1_20;
    C1RXF20bits.EXID        = AO_CAN_FILTER_IDE_1_20;
    C1RXF20bits.SID         = AO_CAN_FILTER_SID_1_20;
    C1FLTCON5bits.FSEL20    = AO_CAN_FILTER_FIFO_1_20;
    C1FLTCON5bits.MSEL20    = AO_CAN_FILTER_MASK_1_20;
    C1FLTCON5bits.FLTEN20   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_21

    C1RXF21bits.EID         = AO_CAN_FILTER_EID_1_21;
    C1RXF21bits.EXID        = AO_CAN_FILTER_IDE_1_21;
    C1RXF21bits.SID         = AO_CAN_FILTER_SID_1_21;
    C1FLTCON5bits.FSEL21    = AO_CAN_FILTER_FIFO_1_21;
    C1FLTCON5bits.MSEL21    = AO_CAN_FILTER_MASK_1_21;
    C1FLTCON5bits.FLTEN21   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_22

    C1RXF22bits.EID         = AO_CAN_FILTER_EID_1_22;
    C1RXF22bits.EXID        = AO_CAN_FILTER_IDE_1_22;
    C1RXF22bits.SID         = AO_CAN_FILTER_SID_1_22;
    C1FLTCON5bits.FSEL22    = AO_CAN_FILTER_FIFO_1_22;
    C1FLTCON5bits.MSEL22    = AO_CAN_FILTER_MASK_1_22;
    C1FLTCON5bits.FLTEN22   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_23

    C1RXF23bits.EID         = AO_CAN_FILTER_EID_1_23;
    C1RXF23bits.EXID        = AO_CAN_FILTER_IDE_1_23;
    C1RXF23bits.SID         = AO_CAN_FILTER_SID_1_23;
    C1FLTCON5bits.FSEL23    = AO_CAN_FILTER_FIFO_1_23;
    C1FLTCON5bits.MSEL23    = AO_CAN_FILTER_MASK_1_23;
    C1FLTCON5bits.FLTEN23   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_24

    C1RXF24bits.EID         = AO_CAN_FILTER_EID_1_24;
    C1RXF24bits.EXID        = AO_CAN_FILTER_IDE_1_24;
    C1RXF24bits.SID         = AO_CAN_FILTER_SID_1_24;
    C1FLTCON6bits.FSEL24    = AO_CAN_FILTER_FIFO_1_24;
    C1FLTCON6bits.MSEL24    = AO_CAN_FILTER_MASK_1_24;
    C1FLTCON6bits.FLTEN24   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_25

    C1RXF25bits.EID         = AO_CAN_FILTER_EID_1_25;
    C1RXF25bits.EXID        = AO_CAN_FILTER_IDE_1_25;
    C1RXF25bits.SID         = AO_CAN_FILTER_SID_1_25;
    C1FLTCON6bits.FSEL25    = AO_CAN_FILTER_FIFO_1_25;
    C1FLTCON6bits.MSEL25    = AO_CAN_FILTER_MASK_1_25;
    C1FLTCON6bits.FLTEN25   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_26

    C1RXF26bits.EID         = AO_CAN_FILTER_EID_1_26;
    C1RXF26bits.EXID        = AO_CAN_FILTER_IDE_1_26;
    C1RXF26bits.SID         = AO_CAN_FILTER_SID_1_26;
    C1FLTCON6bits.FSEL26    = AO_CAN_FILTER_FIFO_1_26;
    C1FLTCON6bits.MSEL26    = AO_CAN_FILTER_MASK_1_26;
    C1FLTCON6bits.FLTEN26   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_27

    C1RXF27bits.EID         = AO_CAN_FILTER_EID_1_27;
    C1RXF27bits.EXID        = AO_CAN_FILTER_IDE_1_27;
    C1RXF27bits.SID         = AO_CAN_FILTER_SID_1_27;
    C1FLTCON6bits.FSEL27    = AO_CAN_FILTER_FIFO_1_27;
    C1FLTCON6bits.MSEL27    = AO_CAN_FILTER_MASK_1_27;
    C1FLTCON6bits.FLTEN27   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_28

    C1RXF28bits.EID         = AO_CAN_FILTER_EID_1_28;
    C1RXF28bits.EXID        = AO_CAN_FILTER_IDE_1_28;
    C1RXF28bits.SID         = AO_CAN_FILTER_SID_1_28;
    C1FLTCON7bits.FSEL28    = AO_CAN_FILTER_FIFO_1_28;
    C1FLTCON7bits.MSEL28    = AO_CAN_FILTER_MASK_1_28;
    C1FLTCON7bits.FLTEN28   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_29

    C1RXF29bits.EID         = AO_CAN_FILTER_EID_1_29;
    C1RXF29bits.EXID        = AO_CAN_FILTER_IDE_1_29;
    C1RXF29bits.SID         = AO_CAN_FILTER_SID_1_29;
    C1FLTCON7bits.FSEL29    = AO_CAN_FILTER_FIFO_1_29;
    C1FLTCON7bits.MSEL29    = AO_CAN_FILTER_MASK_1_29;
    C1FLTCON7bits.FLTEN29   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_30

    C1RXF30bits.EID         = AO_CAN_FILTER_EID_1_30;
    C1RXF30bits.EXID        = AO_CAN_FILTER_IDE_1_30;
    C1RXF30bits.SID         = AO_CAN_FILTER_SID_1_30;
    C1FLTCON7bits.FSEL30    = AO_CAN_FILTER_FIFO_1_30;
    C1FLTCON7bits.MSEL30    = AO_CAN_FILTER_MASK_1_30;
    C1FLTCON7bits.FLTEN30   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_1_31

    C1RXF31bits.EID         = AO_CAN_FILTER_EID_1_31;
    C1RXF31bits.EXID        = AO_CAN_FILTER_IDE_1_31;
    C1RXF31bits.SID         = AO_CAN_FILTER_SID_1_31;
    C1FLTCON7bits.FSEL31    = AO_CAN_FILTER_FIFO_1_31;
    C1FLTCON7bits.MSEL31    = AO_CAN_FILTER_MASK_1_31;
    C1FLTCON7bits.FLTEN31   = 1;

#endif

}

// ----------------------------------------------------------------------------

void ao_can_ir_1()
{
    // Variables.

    ao_can_t *          c1;
    ao_can_t *          c2;

    ao_can_fifo_flags_t f;

    uint32_t            i1;
    uint32_t            i2;

    uint32_t            m;

    uint32_t            r;

    ao_can_reg_t *      reg = ao_can_reg_1();

    ao_time_t           t;


    // Ready.

    do
    {
        t = ao_now();

        i1 = reg->vec.bits.icode;

        ao_ir_can1_reply();

        switch (i1)
        {

#if AO_CAN_INVALID_1

            case 0b1001000:

                // Invalid message received.

                ao_can_invalid_1(&ao_can_invalid_info_1);

                reg->intx.bits.ivrif = 0;

                break;

#endif

                // Mode changed.

            case 0b1000111:

#if AO_CAN_MODE_1

                ao_can_mode_1(&ao_can_mode_info_1);

#endif

                ao_cond_set(&ao_can_cond_changed_1);

                reg->intx.bits.modif = 0;

                break;

#if AO_CAN_TIMER_1

            case 0b1000110:

                // Timer.

                ao_can_timer_1(&ao_can_timer_info_1);

                reg->intx.bits.ctmrif = 0;

                break;

#endif

            case 0b1000101:
            case 0b1000100:

                // System error.

#if AO_CAN_SYSTEM_1

                ao_can_system_info_1.flags = (ao_can_system_flags_t) i1;

                ao_can_system_1(&ao_can_system_info_1);

#endif

                reg->con.bits.on = 0;

                while (reg->con.bits.canbusy) { }

                reg->con.bits.on = 1;

                break;

#if AO_CAN_RBOV_1

            case 0b1000011:

                // Receive buffer overrun.

                r = reg->rxovf.reg;

                m = (AO_CAN_FIFOS_TX_1 == 32) ? UINT32_MAX : (1 << AO_CAN_FIFOS_TX_1) - 1;

#if AO_CAN_RXOF_1

                f = (ao_can_fifo_flags_t) (r & ~m);

                if (f != AO_CAN_FIFO_FLAGS_NONE)
                {
                    ao_can_overflow_info_1.fifos = f;

                    ao_can_overflow_info_1.fifos_rx = (ao_can_fifo_flags_t) ((uint32_t) f >> AO_CAN_FIFOS_TX_1);

                    ao_can_overflow_1(&ao_can_overflow_info_1);
                }

#endif

#if AO_CAN_TXUF_1

                f = (ao_can_fifo_flags_t) (r & m);

                if (f != AO_CAN_FIFO_FLAGS_NONE)
                {
                    ao_can_underflow_info_1.fifos = f;

                    ao_can_underflow_info_1.fifos_tx = f;

                    ao_can_underflow_1(&ao_can_underflow_info_1);
                }

#endif

                // DS61154.

                // Section 34.12.1.17.

                // Clearing all the CxFIFOINTn.RXOVFLIF bits will automatically
                // clear the CxINT.RBOVIF bit.

                while (r)
                {
                    i2 = ao_ffsu(r);

                    m = 1 << i2;

                    r = r & ~m;

                    reg->fifo[i2].intx.bits.rxovflif = 0;
                }

                // DS61154.

                // Section 34.12.1.17: The CxINT.RBOVIF bit is not directly clearable.

                // Section 34.3.4    : The CxINT.RBOVIF bit is writable.

                reg->intx.bits.rbovif = 0;

                break;

#endif

#if AO_CAN_WAKE_UP_1

            case 0b1000010:

                // Wake up.

                ao_can_wake_up_1(&ao_can_wake_up_info_1);

                reg->intx.bits.wakif = 0;

                break;

#endif

#if AO_CAN_BUS_1

            case 0b1000001:

                // CAN bus error.

                ao_can_bus_info_1.receive_error_counter = reg->trec.bits.rerrcnt;

                if (reg->trec.bits.rxbp)
                {
                    ao_can_bus_info_1.receive_error_state = AO_CAN_BUS_PASSIVE;
                }

                else if (reg->trec.bits.rxwarn)
                {
                    ao_can_bus_info_1.receive_error_state = AO_CAN_BUS_ACTIVE_WARNING;
                }

                else
                {
                    ao_can_bus_info_1.receive_error_state = AO_CAN_BUS_ACTIVE;
                }

                ao_can_bus_info_1.transmit_error_counter = reg->trec.bits.terrcnt;

                if (reg->trec.bits.txbo)
                {
                    ao_can_bus_info_1.transmit_error_state = AO_CAN_BUS_OFF;
                }

                else if (reg->trec.bits.txbp)
                {
                    ao_can_bus_info_1.transmit_error_state = AO_CAN_BUS_PASSIVE;
                }

                else if (reg->trec.bits.txwarn)
                {
                    ao_can_bus_info_1.transmit_error_state = AO_CAN_BUS_ACTIVE_WARNING;
                }

                else
                {
                    ao_can_bus_info_1.transmit_error_state = AO_CAN_BUS_ACTIVE;
                }

                ao_can_bus_1(&ao_can_bus_info_1);

                reg->intx.bits.cerrif = 0;

                break;

#endif

            case 0b1000000:

                // No interrupt.

                break;

#if AO_CAN_RX_1

#if AO_CAN_FIFOS_1 > 31  &&  AO_CAN_FIFOS_TX_1 <= 31

            case 31:

#endif

#if AO_CAN_FIFOS_1 > 30  &&  AO_CAN_FIFOS_TX_1 <= 30

            case 30:

#endif

#if AO_CAN_FIFOS_1 > 29  &&  AO_CAN_FIFOS_TX_1 <= 29

            case 29:

#endif

#if AO_CAN_FIFOS_1 > 28  &&  AO_CAN_FIFOS_TX_1 <= 28

            case 28:

#endif

#if AO_CAN_FIFOS_1 > 27  &&  AO_CAN_FIFOS_TX_1 <= 27

            case 27:

#endif

#if AO_CAN_FIFOS_1 > 26  &&  AO_CAN_FIFOS_TX_1 <= 26

            case 26:

#endif

#if AO_CAN_FIFOS_1 > 25  &&  AO_CAN_FIFOS_TX_1 <= 25

            case 25:

#endif

#if AO_CAN_FIFOS_1 > 24  &&  AO_CAN_FIFOS_TX_1 <= 24

            case 24:

#endif

#if AO_CAN_FIFOS_1 > 23  &&  AO_CAN_FIFOS_TX_1 <= 23

            case 23:

#endif

#if AO_CAN_FIFOS_1 > 22  &&  AO_CAN_FIFOS_TX_1 <= 22

            case 22:

#endif

#if AO_CAN_FIFOS_1 > 21  &&  AO_CAN_FIFOS_TX_1 <= 21

            case 21:

#endif

#if AO_CAN_FIFOS_1 > 20  &&  AO_CAN_FIFOS_TX_1 <= 20

            case 20:

#endif

#if AO_CAN_FIFOS_1 > 19  &&  AO_CAN_FIFOS_TX_1 <= 19

            case 19:

#endif

#if AO_CAN_FIFOS_1 > 18  &&  AO_CAN_FIFOS_TX_1 <= 18

            case 18:

#endif

#if AO_CAN_FIFOS_1 > 17  &&  AO_CAN_FIFOS_TX_1 <= 17

            case 17:

#endif

#if AO_CAN_FIFOS_1 > 16  &&  AO_CAN_FIFOS_TX_1 <= 16

            case 16:

#endif

#if AO_CAN_FIFOS_1 > 15  &&  AO_CAN_FIFOS_TX_1 <= 15

            case 15:

#endif

#if AO_CAN_FIFOS_1 > 14  &&  AO_CAN_FIFOS_TX_1 <= 14

            case 14:

#endif

#if AO_CAN_FIFOS_1 > 13  &&  AO_CAN_FIFOS_TX_1 <= 13

            case 13:

#endif

#if AO_CAN_FIFOS_1 > 12  &&  AO_CAN_FIFOS_TX_1 <= 12

            case 12:

#endif

#if AO_CAN_FIFOS_1 > 11  &&  AO_CAN_FIFOS_TX_1 <= 11

            case 11:

#endif

#if AO_CAN_FIFOS_1 > 10  &&  AO_CAN_FIFOS_TX_1 <= 10

            case 10:

#endif

#if AO_CAN_FIFOS_1 >  9  &&  AO_CAN_FIFOS_TX_1 <=  9

            case  9:

#endif

#if AO_CAN_FIFOS_1 >  8  &&  AO_CAN_FIFOS_TX_1 <=  8

            case  8:

#endif

#if AO_CAN_FIFOS_1 >  7  &&  AO_CAN_FIFOS_TX_1 <=  7

            case  7:

#endif

#if AO_CAN_FIFOS_1 >  6  &&  AO_CAN_FIFOS_TX_1 <=  6

            case  6:

#endif

#if AO_CAN_FIFOS_1 >  5  &&  AO_CAN_FIFOS_TX_1 <=  5

            case  5:

#endif

#if AO_CAN_FIFOS_1 >  4  &&  AO_CAN_FIFOS_TX_1 <=  4

            case  4:

#endif

#if AO_CAN_FIFOS_1 >  3  &&  AO_CAN_FIFOS_TX_1 <=  3

            case  3:

#endif

#if AO_CAN_FIFOS_1 >  2  &&  AO_CAN_FIFOS_TX_1 <=  2

            case  2:

#endif

#if AO_CAN_FIFOS_1 >  1  &&  AO_CAN_FIFOS_TX_1 <=  1

            case  1:

#endif

#if AO_CAN_FIFOS_1 >  0  &&  AO_CAN_FIFOS_TX_1 <=  0

            case  0:

#endif

                c1 = PA_TO_KVA1(reg->fifo[i1].ua.reg);

                c2 = ao_can_in_can_1 + i1 - AO_CAN_FIFOS_TX_1;

                if (reg->fifo[i1].con.bits.donly)
                {
                    c2->cmsgsid = 0;

                    c2->cmsgeid = 0;

                    c2->data = *((uint64_t *) c1);
                }

                else
                {
                    *c2 = *c1;
                }

                if (!c2->ide && c2->srr)
                {
                    c2->rtr = 1;
                }

                ao_send_obj_try(ao_can_in_1 + i1 - AO_CAN_FIFOS_TX_1);

                // DS80000480.

                // The CxFIFOCONn.FRESET bit and the CxFIFOCONn.UINC
                // bit are not settable through a normal Special
                // Function Register (SFR) write.

                // Use the SET register operations to change the state
                // of these bits.

                reg->fifo[i1].con.set = _C1FIFOCON0_UINC_MASK;

                break;

#endif

#if AO_CAN_TX_1

#if AO_CAN_FIFOS_1 > 31  &&  AO_CAN_FIFOS_TX_1 > 31

            case 31:

#endif

#if AO_CAN_FIFOS_1 > 30  &&  AO_CAN_FIFOS_TX_1 > 30

            case 30:

#endif

#if AO_CAN_FIFOS_1 > 29  &&  AO_CAN_FIFOS_TX_1 > 29

            case 29:

#endif

#if AO_CAN_FIFOS_1 > 28  &&  AO_CAN_FIFOS_TX_1 > 28

            case 28:

#endif

#if AO_CAN_FIFOS_1 > 27  &&  AO_CAN_FIFOS_TX_1 > 27

            case 27:

#endif

#if AO_CAN_FIFOS_1 > 26  &&  AO_CAN_FIFOS_TX_1 > 26

            case 26:

#endif

#if AO_CAN_FIFOS_1 > 25  &&  AO_CAN_FIFOS_TX_1 > 25

            case 25:

#endif

#if AO_CAN_FIFOS_1 > 24  &&  AO_CAN_FIFOS_TX_1 > 24

            case 24:

#endif

#if AO_CAN_FIFOS_1 > 23  &&  AO_CAN_FIFOS_TX_1 > 23

            case 23:

#endif

#if AO_CAN_FIFOS_1 > 22  &&  AO_CAN_FIFOS_TX_1 > 22

            case 22:

#endif

#if AO_CAN_FIFOS_1 > 21  &&  AO_CAN_FIFOS_TX_1 > 21

            case 21:

#endif

#if AO_CAN_FIFOS_1 > 20  &&  AO_CAN_FIFOS_TX_1 > 20

            case 20:

#endif

#if AO_CAN_FIFOS_1 > 19  &&  AO_CAN_FIFOS_TX_1 > 19

            case 19:

#endif

#if AO_CAN_FIFOS_1 > 18  &&  AO_CAN_FIFOS_TX_1 > 18

            case 18:

#endif

#if AO_CAN_FIFOS_1 > 17  &&  AO_CAN_FIFOS_TX_1 > 17

            case 17:

#endif

#if AO_CAN_FIFOS_1 > 16  &&  AO_CAN_FIFOS_TX_1 > 16

            case 16:

#endif

#if AO_CAN_FIFOS_1 > 15  &&  AO_CAN_FIFOS_TX_1 > 15

            case 15:

#endif

#if AO_CAN_FIFOS_1 > 14  &&  AO_CAN_FIFOS_TX_1 > 14

            case 14:

#endif

#if AO_CAN_FIFOS_1 > 13  &&  AO_CAN_FIFOS_TX_1 > 13

            case 13:

#endif

#if AO_CAN_FIFOS_1 > 12  &&  AO_CAN_FIFOS_TX_1 > 12

            case 12:

#endif

#if AO_CAN_FIFOS_1 > 11  &&  AO_CAN_FIFOS_TX_1 > 11

            case 11:

#endif

#if AO_CAN_FIFOS_1 > 10  &&  AO_CAN_FIFOS_TX_1 > 10

            case 10:

#endif

#if AO_CAN_FIFOS_1 >  9  &&  AO_CAN_FIFOS_TX_1 >  9

            case  9:

#endif

#if AO_CAN_FIFOS_1 >  8  &&  AO_CAN_FIFOS_TX_1 >  8

            case  8:

#endif

#if AO_CAN_FIFOS_1 >  7  &&  AO_CAN_FIFOS_TX_1 >  7

            case  7:

#endif

#if AO_CAN_FIFOS_1 >  6  &&  AO_CAN_FIFOS_TX_1 >  6

            case  6:

#endif

#if AO_CAN_FIFOS_1 >  5  &&  AO_CAN_FIFOS_TX_1 >  5

            case  5:

#endif

#if AO_CAN_FIFOS_1 >  4  &&  AO_CAN_FIFOS_TX_1 >  4

            case  4:

#endif

#if AO_CAN_FIFOS_1 >  3  &&  AO_CAN_FIFOS_TX_1 >  3

            case  3:

#endif

#if AO_CAN_FIFOS_1 >  2  &&  AO_CAN_FIFOS_TX_1 >  2

            case  2:

#endif

#if AO_CAN_FIFOS_1 >  1  &&  AO_CAN_FIFOS_TX_1 >  1

            case  1:

#endif

#if AO_CAN_FIFOS_1 >  0  &&  AO_CAN_FIFOS_TX_1 >  0

            case  0:

#endif

                // Fifo.

#if AO_CAN_TXST_1

                if
                (
                    reg->fifo[i1].intx.bits.txemptyie &&
                    reg->fifo[i1].intx.bits.txemptyif
                )
                {
                    ao_can_sent_info_1.fifo = i1;

                    ao_can_sent_info_1.fifo_tx = i1;

                    ao_can_sent_1(&ao_can_sent_info_1);

                    reg->fifo[i1].intx.bits.txemptyie = 0;
                }

                if
                (
                    reg->fifo[i1].intx.bits.txnfullie &&
                    reg->fifo[i1].intx.bits.txnfullif
                )
                {

#endif

                    ao_cond_set(ao_can_cond_not_full_1 + i1);

                    reg->fifo[i1].intx.bits.txnfullie = 0;

#if AO_CAN_TXST_1

                }

#endif

                break;

#endif

            default:

                // This really should not have happend.

                ao_assert(false);

                break;
        }
    }
    while (i1 != 0b1000000);
}

// ----------------------------------------------------------------------------

void ao_can_listen_all_1()
{
    ao_can_var_mode_1 = 7;

    ao_cond_set(&ao_can_cond_change_1);
}

void ao_can_listen_only_1()
{
    ao_can_var_mode_1 = 3;

    ao_cond_set(&ao_can_cond_change_1);
}

void ao_can_loopback_1()
{
    ao_can_var_mode_1 = 2;

    ao_cond_set(&ao_can_cond_change_1);
}

void ao_can_normal_1()
{
    ao_can_var_mode_1 = 0;

    ao_cond_set(&ao_can_cond_change_1);
}

// ----------------------------------------------------------------------------

void ao_can_start_1()
{
    ao_task_start(&ao_can_task_1);
}

void ao_can_started_1()
{
    // Variables.

#if AO_CAN_TX_1

    ao_can_t *      c1;
    ao_can_t *      c2;

    size_t          i;

    ao_can_reg_t *  reg = ao_can_reg_1();

#endif


    // Ready.

    while (ao_can_var_started_1)
    {
        // Await begin.

        ao_cond_wait_begin(     &ao_can_cond_change_wait_1);

        ao_sem_take_begin(      &ao_can_sem_take_1);

#if AO_CAN_TX_1

        for (i = 0; i < AO_CAN_FIFOS_TX_1; i++)
        {
            ao_cond_wait_begin( &ao_can_cond_not_full_wait_1[i]);

            ao_recv_obj_begin(  &ao_can_out_1               [i]);

            ao_async_all_begin( &ao_can_async_send_1        [i]);
        }

#endif


        // Await.

        ao_await_any_forever(   &ao_can_async_started_1);


        // Await end.

#if AO_CAN_TX_1

        for (i = 0; i < AO_CAN_FIFOS_TX_1; i++)
        {
            ao_async_all_end(   &ao_can_async_send_1        [i]);

            ao_recv_obj_end(    &ao_can_out_1               [i]);

            ao_cond_wait_end(   &ao_can_cond_not_full_wait_1[i]);
        }

#endif

        ao_sem_take_end(        &ao_can_sem_take_1);

        ao_cond_wait_end(       &ao_can_cond_change_wait_1);


        // Stop.

        if (ao_can_sem_take_1.result)
        {
            ao_can_var_started_1 = false;
        }


        // Change.

        else if (ao_can_cond_change_wait_1.result)
        {
            ao_cond_clear(&ao_can_cond_change_1);

            ao_can_change_1(ao_can_var_mode_1);
        }


        // Out.

#if AO_CAN_TX_1

        else
        {
            for (i = 0; i < AO_CAN_FIFOS_TX_1; i++)
            {
                if
                (
                    ao_can_cond_not_full_wait_1 [i].result &&
                    ao_can_out_1                [i].result
                )
                {
                    c2 = ao_can_out_can_1 + i;

                    c1 = (ao_can_t *) PA_TO_KVA1(reg->fifo[i].ua.reg);

                    *c1 = *c2;


                    // DS61154.

                    // Section 34.7.1.

                    // Format of Transmit Message Buffer.

                    // Unused bits should be clear.

                    // RB0 and RB1 bits must be clear.

                    c1->cmsgeid &= 0x3FFFFE0F;
                    c1->cmsgsid &= 0x000007FF;


                    // In case of an extended message format,
                    // the SRR bit should be set.

                    if (c1->ide)
                    {
                        c1->srr = 1;
                    }


                    // DS80000480.

                    // The CxFIFOCONn.FRESET bit and the CxFIFOCONn.UINC bit
                    // are not settable through a normal Special Function
                    // Register (SFR) write.

                    // Use the SET register operations to change the state of
                    // these bits.

                    reg->fifo[i].con.set = _C1FIFOCON0_UINC_MASK;


#if AO_CAN_TXST_1

                    reg->fifo[i].intx.bits.txemptyie = 1;

#endif

                    if (reg->fifo[i].con.bits.rtren == 0)
                    {
                        if (reg->fifo[i].intx.bits.txnfullif == 0)
                        {
                            ao_cond_clear(ao_can_cond_not_full_1 + i);

                            reg->fifo[i].intx.bits.txnfullie = 1;
                        }

                        reg->fifo[i].con.set = _C1FIFOCON0_TXREQ_MASK;
                    }
                }
            }
        }

#endif

    }
}

void ao_can_starting_1()
{
    // Variables.

    uint32_t mode;


    // Ready.

    ao_can_var_started_1 = true;

    ao_cond_clear(&ao_can_cond_change_1);

    mode = ao_can_var_mode_1;

    ao_assert
    (
        mode == 0 ||
        mode == 2 ||
        mode == 3 ||
        mode == 7
    );

    ao_can_change_1(mode);
}

void ao_can_stop_1()
{
    ao_sem_give(&ao_can_sem_1, 1);
}

void ao_can_stopping_1()
{
    ao_can_change_1(4);
}

// ----------------------------------------------------------------------------

void ao_can_task_proc_1(void * x)
{
    // Variables.

    size_t          i;

    ao_can_reg_t *  reg = ao_can_reg_1();

    (void)          x;


    // Ready.

    while (1)
    {
        // On.

        reg->con.bits.on = 1;

        ao_assert(reg->con.bits.opmod == 4);


        // Configuration.

        ao_can_config_1();


        // Interrupts layer 3.

#if AO_CAN_RX_1

        for (i = AO_CAN_FIFOS_TX_1; i < AO_CAN_FIFOS_TX_1 + AO_CAN_FIFOS_RX_1; i++)
        {
            reg->fifo[i].con.bits.txen = 0;

            reg->fifo[i].intx.bits.rxnemptyie = 1;

#if AO_CAN_RXOF_1

            reg->fifo[i].intx.bits.rxovflie = 1;

#endif

        }

#endif

#if AO_CAN_TX_1

        for (i = 0; i < AO_CAN_FIFOS_TX_1; i++)
        {
            reg->fifo[i].con.bits.txen = 1;

            if (reg->fifo[i].con.bits.rtren)
            {

#if AO_CAN_TXUF_1

                reg->fifo[i].intx.bits.rxovflie = 1;

#endif

                ao_cond_set(&ao_can_cond_not_full_1[i]);
            }

            else
            {
                if (reg->fifo[i].intx.bits.txnfullif == 0)
                {
                    reg->fifo[i].intx.bits.txnfullie = 1;
                }

                else
                {
                    ao_cond_set(&ao_can_cond_not_full_1[i]);
                }
            }

#if AO_CAN_TXST_1

            if (reg->fifo[i].intx.bits.txemptyif) { }

            else
            {
                reg->fifo[i].intx.bits.txemptyie = 1;
            }

#endif

        }

#endif


        // Interrupts layer 2.

        reg->intx.bits.modie = 1;
        reg->intx.bits.serrie = 1;

#if AO_CAN_BUS_1

        reg->intx.bits.cerrie = 1;

#endif

#if AO_CAN_INVALID_1

        reg->intx.bits.ivrie = 1;

#endif

#if AO_CAN_RBOV_1

        reg->intx.bits.rbovie = 1;

#endif

#if AO_CAN_RX_1

        reg->intx.bits.rbie = 1;

#endif

#if AO_CAN_TIMER_1

        reg->intx.bits.ctmrie = 1;

#endif

#if AO_CAN_TX_1

        reg->intx.bits.tbie = 1;

#endif

#if AO_CAN_WAKE_UP_1

        reg->intx.bits.wakie = 1;

#endif


        // Interrupts layer 1.

        ao_ir_can1_enable();


        // Start.

        ao_can_starting_1();

        ao_can_started_1();


        // Stop.

        ao_can_stopping_1();


        // Interrupts layer 1.

        ao_ir_can1_disable();


        // Interrupts layer 2.

        reg->intx.bits.modie = 0;
        reg->intx.bits.serrie = 0;

#if AO_CAN_BUS_1

        reg->intx.bits.cerrie = 0;

#endif

#if AO_CAN_INVALID_1

        reg->intx.bits.ivrie = 0;

#endif

#if AO_CAN_RBOV_1

        reg->intx.bits.rbovie = 0;

#endif

#if AO_CAN_RX_1

        reg->intx.bits.rbie = 0;

#endif

#if AO_CAN_TIMER_1

        reg->intx.bits.ctmrie = 0;

#endif

#if AO_CAN_TX_1

        reg->intx.bits.tbie = 0;

#endif

#if AO_CAN_WAKE_UP_1

        reg->intx.bits.wakie = 0;

#endif


        // Interrupts layer 3.

#if AO_CAN_TX_1

        for (i = 0; i < AO_CAN_FIFOS_TX_1; i++)
        {

            reg->fifo[i].intx.bits.txnfullie = 0;

#if AO_CAN_TXUF_1

            reg->fifo[i].intx.bits.rxovflie = 0;

#endif

#if AO_CAN_TXST_1

            reg->fifo[i].intx.bits.txemptyie = 0;

#endif

        }

#endif

#if AO_CAN_RX_1

        for (i = AO_CAN_FIFOS_TX_1; i < AO_CAN_FIFOS_TX_1 + AO_CAN_FIFOS_RX_1; i++)
        {
            reg->fifo[i].intx.bits.rxnemptyie = 0;

#if AO_CAN_RXOF_1

            reg->fifo[i].intx.bits.rxovflie = 0;

#endif

        }

#endif


        // Off.

        reg->con.bits.on = 0;

        while (reg->con.bits.canbusy) { }


        // Task.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_CAN_2 && AO_CAN_2

// ----------------------------------------------------------------------------

#if AO_CAN_BAUD_2 < AO_CAN_BAUD_MIN_2

#error Invalid configuration.

#endif

#if AO_CAN_BAUD_2 > AO_CAN_BAUD_MAX_2

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_2 > 0  && AO_CAN_BUFFERS_2_0  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 1  && AO_CAN_BUFFERS_2_1  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 2  && AO_CAN_BUFFERS_2_2  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 3  && AO_CAN_BUFFERS_2_3  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 4  && AO_CAN_BUFFERS_2_4  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 5  && AO_CAN_BUFFERS_2_5  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 6  && AO_CAN_BUFFERS_2_6  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 7  && AO_CAN_BUFFERS_2_7  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 8  && AO_CAN_BUFFERS_2_8  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 9  && AO_CAN_BUFFERS_2_9  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 10 && AO_CAN_BUFFERS_2_10 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 11 && AO_CAN_BUFFERS_2_11 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 12 && AO_CAN_BUFFERS_2_12 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 13 && AO_CAN_BUFFERS_2_13 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 14 && AO_CAN_BUFFERS_2_14 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 15 && AO_CAN_BUFFERS_2_15 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 16 && AO_CAN_BUFFERS_2_16 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 17 && AO_CAN_BUFFERS_2_17 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 18 && AO_CAN_BUFFERS_2_18 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 19 && AO_CAN_BUFFERS_2_19 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 20 && AO_CAN_BUFFERS_2_20 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 21 && AO_CAN_BUFFERS_2_21 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 22 && AO_CAN_BUFFERS_2_22 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 23 && AO_CAN_BUFFERS_2_23 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 24 && AO_CAN_BUFFERS_2_24 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 25 && AO_CAN_BUFFERS_2_25 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 26 && AO_CAN_BUFFERS_2_26 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 27 && AO_CAN_BUFFERS_2_27 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 28 && AO_CAN_BUFFERS_2_28 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 29 && AO_CAN_BUFFERS_2_29 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 30 && AO_CAN_BUFFERS_2_30 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 31 && AO_CAN_BUFFERS_2_31 < 1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_2 > 0  && AO_CAN_BUFFERS_2_0  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 1  && AO_CAN_BUFFERS_2_1  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 2  && AO_CAN_BUFFERS_2_2  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 3  && AO_CAN_BUFFERS_2_3  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 4  && AO_CAN_BUFFERS_2_4  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 5  && AO_CAN_BUFFERS_2_5  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 6  && AO_CAN_BUFFERS_2_6  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 7  && AO_CAN_BUFFERS_2_7  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 8  && AO_CAN_BUFFERS_2_8  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 9  && AO_CAN_BUFFERS_2_9  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 10 && AO_CAN_BUFFERS_2_10 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 11 && AO_CAN_BUFFERS_2_11 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 12 && AO_CAN_BUFFERS_2_12 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 13 && AO_CAN_BUFFERS_2_13 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 14 && AO_CAN_BUFFERS_2_14 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 15 && AO_CAN_BUFFERS_2_15 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 16 && AO_CAN_BUFFERS_2_16 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 17 && AO_CAN_BUFFERS_2_17 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 18 && AO_CAN_BUFFERS_2_18 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 19 && AO_CAN_BUFFERS_2_19 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 20 && AO_CAN_BUFFERS_2_20 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 21 && AO_CAN_BUFFERS_2_21 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 22 && AO_CAN_BUFFERS_2_22 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 23 && AO_CAN_BUFFERS_2_23 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 24 && AO_CAN_BUFFERS_2_24 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 25 && AO_CAN_BUFFERS_2_25 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 26 && AO_CAN_BUFFERS_2_26 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 27 && AO_CAN_BUFFERS_2_27 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 28 && AO_CAN_BUFFERS_2_28 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 29 && AO_CAN_BUFFERS_2_29 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 30 && AO_CAN_BUFFERS_2_30 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_2 > 31 && AO_CAN_BUFFERS_2_31 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_2 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_RX_2 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_TX_2 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_EID_2_0  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_1  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_2  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_3  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_4  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_5  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_6  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_7  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_8  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_9  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_10 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_11 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_12 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_13 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_14 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_15 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_16 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_17 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_18 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_19 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_20 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_21 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_22 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_23 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_24 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_25 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_26 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_27 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_28 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_29 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_30 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_2_31 > 0x3FFFF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_FIFO_2_0  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_1  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_2  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_3  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_4  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_5  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_6  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_7  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_8  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_9  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_10 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_11 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_12 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_13 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_14 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_15 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_16 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_17 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_18 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_19 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_20 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_21 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_22 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_23 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_24 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_25 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_26 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_27 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_28 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_29 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_30 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_2_31 > 31

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_IDE_2_0  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_1  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_2  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_3  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_4  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_5  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_6  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_7  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_8  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_9  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_10 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_11 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_12 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_13 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_14 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_15 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_16 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_17 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_18 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_19 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_20 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_21 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_22 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_23 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_24 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_25 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_26 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_27 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_28 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_29 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_30 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_2_31 > 0x1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_2_0  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_1  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_2  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_3  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_4  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_5  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_6  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_7  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_8  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_9  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_10 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_11 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_12 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_13 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_14 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_15 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_16 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_17 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_18 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_19 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_20 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_21 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_22 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_23 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_24 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_25 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_26 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_27 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_28 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_29 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_30 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_2_31 > 3

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_EID_2_0 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_2_1 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_2_2 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_2_3 > 0x3FFFF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_IDE_2_0 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_2_1 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_2_2 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_2_3 > 0x1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_SID_2_0 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_2_1 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_2_2 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_2_3 > 0x7FF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_SID_2_0  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_1  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_2  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_3  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_4  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_5  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_6  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_7  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_8  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_9  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_10 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_11 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_12 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_13 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_14 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_15 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_16 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_17 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_18 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_19 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_20 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_21 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_22 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_23 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_24 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_25 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_26 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_27 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_28 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_29 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_30 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_2_31 > 0x7FF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#define AO_CAN_RXOF_2           ((AO_CAN_RX_2)      && (AO_CAN_OVERFLOW_2))

#define AO_CAN_TXST_2           ((AO_CAN_TX_2)      && (AO_CAN_SENT_2))

#define AO_CAN_TXUF_2           ((AO_CAN_TX_2)      && (AO_CAN_UNDERFLOW_2))

// ----------------------------------------------------------------------------

#define AO_CAN_RBOV_2           ((AO_CAN_RXOF_2)    || (AO_CAN_TXUF_2))

// ----------------------------------------------------------------------------

static  void                    ao_can_change_2(    uint32_t mode);

static  void                    ao_can_started_2();

static  void                    ao_can_starting_2();

static  void                    ao_can_stopping_2();

static  void                    ao_can_task_proc_2( void * x);

// ----------------------------------------------------------------------------

        ao_can_t                ao_can_buffers_2    [AO_CAN_BUFFERS_2];

// ----------------------------------------------------------------------------

#if AO_CAN_BUS_2

static  ao_can_bus_info_t       ao_can_bus_info_2;

#endif

#if AO_CAN_INVALID_2

static  ao_can_invalid_info_t   ao_can_invalid_info_2;

#endif

#if AO_CAN_MODE_2

static  ao_can_mode_info_t      ao_can_mode_info_2;

#endif

#if AO_CAN_RXOF_2

static  ao_can_overflow_info_t  ao_can_overflow_info_2;

#endif

#if AO_CAN_SYSTEM_2

static  ao_can_system_info_t    ao_can_system_info_2;

#endif

#if AO_CAN_TIMER_2

static  ao_can_timer_info_t     ao_can_timer_info_2;

#endif

#if AO_CAN_TXST_2

static  ao_can_sent_info_t      ao_can_sent_info_2;

#endif

#if AO_CAN_TXUF_2

static  ao_can_underflow_info_t ao_can_underflow_info_2;

#endif

#if AO_CAN_WAKE_UP_2

static  ao_can_wake_up_info_t   ao_can_wake_up_info_2;

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_RX_2

// ----------------------------------------------------------------------------

static  ao_can_t                ao_can_in_can_2     [AO_CAN_FIFOS_RX_2];

        ao_send_obj_t           ao_can_in_2         [AO_CAN_FIFOS_RX_2] =
{

#if AO_CAN_FIFOS_RX_2 >  0

#if AO_CAN_FIFOS_RX_2 >  0

{
        .ptr                    = ao_can_in_can_2 +  0
},

#endif

#if AO_CAN_FIFOS_RX_2 >  1

{
        .ptr                    = ao_can_in_can_2 +  1
},

#endif

#if AO_CAN_FIFOS_RX_2 >  2

{
        .ptr                    = ao_can_in_can_2 +  2
},

#endif

#if AO_CAN_FIFOS_RX_2 >  3

{
        .ptr                    = ao_can_in_can_2 +  3
},

#endif

#if AO_CAN_FIFOS_RX_2 >  4

{
        .ptr                    = ao_can_in_can_2 +  4
},

#endif

#if AO_CAN_FIFOS_RX_2 >  5

{
        .ptr                    = ao_can_in_can_2 +  5
},

#endif

#if AO_CAN_FIFOS_RX_2 >  6

{
        .ptr                    = ao_can_in_can_2 +  6
},

#endif

#if AO_CAN_FIFOS_RX_2 >  7

{
        .ptr                    = ao_can_in_can_2 +  7
},

#endif

#if AO_CAN_FIFOS_RX_2 >  8

{
        .ptr                    = ao_can_in_can_2 +  8
},

#endif

#if AO_CAN_FIFOS_RX_2 >  9

{
        .ptr                    = ao_can_in_can_2 +  9
},

#endif

#if AO_CAN_FIFOS_RX_2 > 10

{
        .ptr                    = ao_can_in_can_2 + 10
},

#endif

#if AO_CAN_FIFOS_RX_2 > 11

{
        .ptr                    = ao_can_in_can_2 + 11
},

#endif

#if AO_CAN_FIFOS_RX_2 > 12

{
        .ptr                    = ao_can_in_can_2 + 12
},

#endif

#if AO_CAN_FIFOS_RX_2 > 13

{
        .ptr                    = ao_can_in_can_2 + 13
},

#endif

#if AO_CAN_FIFOS_RX_2 > 14

{
        .ptr                    = ao_can_in_can_2 + 14
},

#endif

#if AO_CAN_FIFOS_RX_2 > 15

{
        .ptr                    = ao_can_in_can_2 + 15
},

#endif

#if AO_CAN_FIFOS_RX_2 > 16

{
        .ptr                    = ao_can_in_can_2 + 16
},

#endif

#if AO_CAN_FIFOS_RX_2 > 17

{
        .ptr                    = ao_can_in_can_2 + 17
},

#endif

#if AO_CAN_FIFOS_RX_2 > 18

{
        .ptr                    = ao_can_in_can_2 + 18
},

#endif

#if AO_CAN_FIFOS_RX_2 > 19

{
        .ptr                    = ao_can_in_can_2 + 19
},

#endif

#if AO_CAN_FIFOS_RX_2 > 20

{
        .ptr                    = ao_can_in_can_2 + 20
},

#endif

#if AO_CAN_FIFOS_RX_2 > 21

{
        .ptr                    = ao_can_in_can_2 + 21
},

#endif

#if AO_CAN_FIFOS_RX_2 > 22

{
        .ptr                    = ao_can_in_can_2 + 22
},

#endif

#if AO_CAN_FIFOS_RX_2 > 23

{
        .ptr                    = ao_can_in_can_2 + 23
},

#endif

#if AO_CAN_FIFOS_RX_2 > 24

{
        .ptr                    = ao_can_in_can_2 + 24
},

#endif

#if AO_CAN_FIFOS_RX_2 > 25

{
        .ptr                    = ao_can_in_can_2 + 25
},

#endif

#if AO_CAN_FIFOS_RX_2 > 26

{
        .ptr                    = ao_can_in_can_2 + 26
},

#endif

#if AO_CAN_FIFOS_RX_2 > 27

{
        .ptr                    = ao_can_in_can_2 + 27
},

#endif

#if AO_CAN_FIFOS_RX_2 > 28

{
        .ptr                    = ao_can_in_can_2 + 28
},

#endif

#if AO_CAN_FIFOS_RX_2 > 29

{
        .ptr                    = ao_can_in_can_2 + 29
},

#endif

#if AO_CAN_FIFOS_RX_2 > 30

{
        .ptr                    = ao_can_in_can_2 + 30
},

#endif

#if AO_CAN_FIFOS_RX_2 > 31

{
        .ptr                    = ao_can_in_can_2 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

#endif

#if AO_CAN_TX_2

// ----------------------------------------------------------------------------

static  ao_can_t                ao_can_out_can_2    [AO_CAN_FIFOS_TX_2];

        ao_recv_obj_t           ao_can_out_2        [AO_CAN_FIFOS_TX_2] =
{

#if AO_CAN_FIFOS_TX_2 >  0

#if AO_CAN_FIFOS_TX_2 >  0

{
        .ptr                    = ao_can_out_can_2 +  0
},

#endif

#if AO_CAN_FIFOS_TX_2 >  1

{
        .ptr                    = ao_can_out_can_2 +  1
},

#endif

#if AO_CAN_FIFOS_TX_2 >  2

{
        .ptr                    = ao_can_out_can_2 +  2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  3

{
        .ptr                    = ao_can_out_can_2 +  3
},

#endif

#if AO_CAN_FIFOS_TX_2 >  4

{
        .ptr                    = ao_can_out_can_2 +  4
},

#endif

#if AO_CAN_FIFOS_TX_2 >  5

{
        .ptr                    = ao_can_out_can_2 +  5
},

#endif

#if AO_CAN_FIFOS_TX_2 >  6

{
        .ptr                    = ao_can_out_can_2 +  6
},

#endif

#if AO_CAN_FIFOS_TX_2 >  7

{
        .ptr                    = ao_can_out_can_2 +  7
},

#endif

#if AO_CAN_FIFOS_TX_2 >  8

{
        .ptr                    = ao_can_out_can_2 +  8
},

#endif

#if AO_CAN_FIFOS_TX_2 >  9

{
        .ptr                    = ao_can_out_can_2 +  9
},

#endif

#if AO_CAN_FIFOS_TX_2 > 10

{
        .ptr                    = ao_can_out_can_2 + 10
},

#endif

#if AO_CAN_FIFOS_TX_2 > 11

{
        .ptr                    = ao_can_out_can_2 + 11
},

#endif

#if AO_CAN_FIFOS_TX_2 > 12

{
        .ptr                    = ao_can_out_can_2 + 12
},

#endif

#if AO_CAN_FIFOS_TX_2 > 13

{
        .ptr                    = ao_can_out_can_2 + 13
},

#endif

#if AO_CAN_FIFOS_TX_2 > 14

{
        .ptr                    = ao_can_out_can_2 + 14
},

#endif

#if AO_CAN_FIFOS_TX_2 > 15

{
        .ptr                    = ao_can_out_can_2 + 15
},

#endif

#if AO_CAN_FIFOS_TX_2 > 16

{
        .ptr                    = ao_can_out_can_2 + 16
},

#endif

#if AO_CAN_FIFOS_TX_2 > 17

{
        .ptr                    = ao_can_out_can_2 + 17
},

#endif

#if AO_CAN_FIFOS_TX_2 > 18

{
        .ptr                    = ao_can_out_can_2 + 18
},

#endif

#if AO_CAN_FIFOS_TX_2 > 19

{
        .ptr                    = ao_can_out_can_2 + 19
},

#endif

#if AO_CAN_FIFOS_TX_2 > 20

{
        .ptr                    = ao_can_out_can_2 + 20
},

#endif

#if AO_CAN_FIFOS_TX_2 > 21

{
        .ptr                    = ao_can_out_can_2 + 21
},

#endif

#if AO_CAN_FIFOS_TX_2 > 22

{
        .ptr                    = ao_can_out_can_2 + 22
},

#endif

#if AO_CAN_FIFOS_TX_2 > 23

{
        .ptr                    = ao_can_out_can_2 + 23
},

#endif

#if AO_CAN_FIFOS_TX_2 > 24

{
        .ptr                    = ao_can_out_can_2 + 24
},

#endif

#if AO_CAN_FIFOS_TX_2 > 25

{
        .ptr                    = ao_can_out_can_2 + 25
},

#endif

#if AO_CAN_FIFOS_TX_2 > 26

{
        .ptr                    = ao_can_out_can_2 + 26
},

#endif

#if AO_CAN_FIFOS_TX_2 > 27

{
        .ptr                    = ao_can_out_can_2 + 27
},

#endif

#if AO_CAN_FIFOS_TX_2 > 28

{
        .ptr                    = ao_can_out_can_2 + 28
},

#endif

#if AO_CAN_FIFOS_TX_2 > 29

{
        .ptr                    = ao_can_out_can_2 + 29
},

#endif

#if AO_CAN_FIFOS_TX_2 > 30

{
        .ptr                    = ao_can_out_can_2 + 30
},

#endif

#if AO_CAN_FIFOS_TX_2 > 31

{
        .ptr                    = ao_can_out_can_2 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_change_2;

static  ao_cond_wait_t          ao_can_cond_change_wait_2 =
{
        .cond                   = &ao_can_cond_change_2
};

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_changed_2;

static  ao_cond_wait_t          ao_can_cond_changed_wait_2 =
{
        .cond                   = &ao_can_cond_changed_2
};

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_not_full_2      [AO_CAN_FIFOS_TX_2];

static  ao_cond_wait_t          ao_can_cond_not_full_wait_2 [AO_CAN_FIFOS_TX_2] =
{

#if AO_CAN_FIFOS_TX_2 >  0

#if AO_CAN_FIFOS_TX_2 >  0

{
        .cond                   = ao_can_cond_not_full_2 +  0
},

#endif

#if AO_CAN_FIFOS_TX_2 >  1

{
        .cond                   = ao_can_cond_not_full_2 +  1
},

#endif

#if AO_CAN_FIFOS_TX_2 >  2

{
        .cond                   = ao_can_cond_not_full_2 +  2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  3

{
        .cond                   = ao_can_cond_not_full_2 +  3
},

#endif

#if AO_CAN_FIFOS_TX_2 >  4

{
        .cond                   = ao_can_cond_not_full_2 +  4
},

#endif

#if AO_CAN_FIFOS_TX_2 >  5

{
        .cond                   = ao_can_cond_not_full_2 +  5
},

#endif

#if AO_CAN_FIFOS_TX_2 >  6

{
        .cond                   = ao_can_cond_not_full_2 +  6
},

#endif

#if AO_CAN_FIFOS_TX_2 >  7

{
        .cond                   = ao_can_cond_not_full_2 +  7
},

#endif

#if AO_CAN_FIFOS_TX_2 >  8

{
        .cond                   = ao_can_cond_not_full_2 +  8
},

#endif

#if AO_CAN_FIFOS_TX_2 >  9

{
        .cond                   = ao_can_cond_not_full_2 +  9
},

#endif

#if AO_CAN_FIFOS_TX_2 > 10

{
        .cond                   = ao_can_cond_not_full_2 + 10
},

#endif

#if AO_CAN_FIFOS_TX_2 > 11

{
        .cond                   = ao_can_cond_not_full_2 + 11
},

#endif

#if AO_CAN_FIFOS_TX_2 > 12

{
        .cond                   = ao_can_cond_not_full_2 + 12
},

#endif

#if AO_CAN_FIFOS_TX_2 > 13

{
        .cond                   = ao_can_cond_not_full_2 + 13
},

#endif

#if AO_CAN_FIFOS_TX_2 > 14

{
        .cond                   = ao_can_cond_not_full_2 + 14
},

#endif

#if AO_CAN_FIFOS_TX_2 > 15

{
        .cond                   = ao_can_cond_not_full_2 + 15
},

#endif

#if AO_CAN_FIFOS_TX_2 > 16

{
        .cond                   = ao_can_cond_not_full_2 + 16
},

#endif

#if AO_CAN_FIFOS_TX_2 > 17

{
        .cond                   = ao_can_cond_not_full_2 + 17
},

#endif

#if AO_CAN_FIFOS_TX_2 > 18

{
        .cond                   = ao_can_cond_not_full_2 + 18
},

#endif

#if AO_CAN_FIFOS_TX_2 > 19

{
        .cond                   = ao_can_cond_not_full_2 + 19
},

#endif

#if AO_CAN_FIFOS_TX_2 > 20

{
        .cond                   = ao_can_cond_not_full_2 + 20
},

#endif

#if AO_CAN_FIFOS_TX_2 > 21

{
        .cond                   = ao_can_cond_not_full_2 + 21
},

#endif

#if AO_CAN_FIFOS_TX_2 > 22

{
        .cond                   = ao_can_cond_not_full_2 + 22
},

#endif

#if AO_CAN_FIFOS_TX_2 > 23

{
        .cond                   = ao_can_cond_not_full_2 + 23
},

#endif

#if AO_CAN_FIFOS_TX_2 > 24

{
        .cond                   = ao_can_cond_not_full_2 + 24
},

#endif

#if AO_CAN_FIFOS_TX_2 > 25

{
        .cond                   = ao_can_cond_not_full_2 + 25
},

#endif

#if AO_CAN_FIFOS_TX_2 > 26

{
        .cond                   = ao_can_cond_not_full_2 + 26
},

#endif

#if AO_CAN_FIFOS_TX_2 > 27

{
        .cond                   = ao_can_cond_not_full_2 + 27
},

#endif

#if AO_CAN_FIFOS_TX_2 > 28

{
        .cond                   = ao_can_cond_not_full_2 + 28
},

#endif

#if AO_CAN_FIFOS_TX_2 > 29

{
        .cond                   = ao_can_cond_not_full_2 + 29
},

#endif

#if AO_CAN_FIFOS_TX_2 > 30

{
        .cond                   = ao_can_cond_not_full_2 + 30
},

#endif

#if AO_CAN_FIFOS_TX_2 > 31

{
        .cond                   = ao_can_cond_not_full_2 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

static  ao_sem_t                ao_can_sem_2;

static  ao_sem_take_t           ao_can_sem_take_2 =
{
        .count                  = 1,

        .sem                    = &ao_can_sem_2
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_can_task_2 =
{
        .proc                   = ao_can_task_proc_2
};

// ----------------------------------------------------------------------------

static  uint32_t    volatile    ao_can_var_mode_2 = 0;

static  bool        volatile    ao_can_var_started_2 = false;

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_change_store_2 [2] =
{
        &ao_can_cond_changed_wait_2.async,

        &ao_can_sem_take_2.async
};

static  ao_async_any_t          ao_can_async_change_2 =
{
        .store                  = ao_can_async_change_store_2,

        .count                  = 2
};

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_send_store_2   [AO_CAN_FIFOS_TX_2 * 2] =
{

#if AO_CAN_FIFOS_TX_2 >  0

#if AO_CAN_FIFOS_TX_2 >  0

        &ao_can_cond_not_full_wait_2[ 0].async,

        &ao_can_out_2               [ 0].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  1

        &ao_can_cond_not_full_wait_2[ 1].async,

        &ao_can_out_2               [ 1].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  2

        &ao_can_cond_not_full_wait_2[ 2].async,

        &ao_can_out_2               [ 2].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  3

        &ao_can_cond_not_full_wait_2[ 3].async,

        &ao_can_out_2               [ 3].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  4

        &ao_can_cond_not_full_wait_2[ 4].async,

        &ao_can_out_2               [ 4].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  5

        &ao_can_cond_not_full_wait_2[ 5].async,

        &ao_can_out_2               [ 5].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  6

        &ao_can_cond_not_full_wait_2[ 6].async,

        &ao_can_out_2               [ 6].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  7

        &ao_can_cond_not_full_wait_2[ 7].async,

        &ao_can_out_2               [ 7].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  8

        &ao_can_cond_not_full_wait_2[ 8].async,

        &ao_can_out_2               [ 8].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  9

        &ao_can_cond_not_full_wait_2[ 9].async,

        &ao_can_out_2               [ 9].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 10

        &ao_can_cond_not_full_wait_2[10].async,

        &ao_can_out_2               [10].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 11

        &ao_can_cond_not_full_wait_2[11].async,

        &ao_can_out_2               [11].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 12

        &ao_can_cond_not_full_wait_2[12].async,

        &ao_can_out_2               [12].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 13

        &ao_can_cond_not_full_wait_2[13].async,

        &ao_can_out_2               [13].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 14

        &ao_can_cond_not_full_wait_2[14].async,

        &ao_can_out_2               [14].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 15

        &ao_can_cond_not_full_wait_2[15].async,

        &ao_can_out_2               [15].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 16

        &ao_can_cond_not_full_wait_2[16].async,

        &ao_can_out_2               [16].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 17

        &ao_can_cond_not_full_wait_2[17].async,

        &ao_can_out_2               [17].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 18

        &ao_can_cond_not_full_wait_2[18].async,

        &ao_can_out_2               [18].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 19

        &ao_can_cond_not_full_wait_2[19].async,

        &ao_can_out_2               [19].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 20

        &ao_can_cond_not_full_wait_2[20].async,

        &ao_can_out_2               [20].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 21

        &ao_can_cond_not_full_wait_2[21].async,

        &ao_can_out_2               [21].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 22

        &ao_can_cond_not_full_wait_2[22].async,

        &ao_can_out_2               [22].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 23

        &ao_can_cond_not_full_wait_2[23].async,

        &ao_can_out_2               [23].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 24

        &ao_can_cond_not_full_wait_2[24].async,

        &ao_can_out_2               [24].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 25

        &ao_can_cond_not_full_wait_2[25].async,

        &ao_can_out_2               [25].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 26

        &ao_can_cond_not_full_wait_2[26].async,

        &ao_can_out_2               [26].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 27

        &ao_can_cond_not_full_wait_2[27].async,

        &ao_can_out_2               [27].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 28

        &ao_can_cond_not_full_wait_2[28].async,

        &ao_can_out_2               [28].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 29

        &ao_can_cond_not_full_wait_2[29].async,

        &ao_can_out_2               [29].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 30

        &ao_can_cond_not_full_wait_2[30].async,

        &ao_can_out_2               [30].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 31

        &ao_can_cond_not_full_wait_2[31].async,

        &ao_can_out_2               [31].async,

#endif

#endif

};

static  ao_async_all_t          ao_can_async_send_2         [AO_CAN_FIFOS_TX_2] =
{

#if AO_CAN_FIFOS_TX_2 >  0

#if AO_CAN_FIFOS_TX_2 >  0

{
        .store                  = ao_can_async_send_store_2 +  0 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  1

{
        .store                  = ao_can_async_send_store_2 +  1 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  2

{
        .store                  = ao_can_async_send_store_2 +  2 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  3

{
        .store                  = ao_can_async_send_store_2 +  3 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  4

{
        .store                  = ao_can_async_send_store_2 +  4 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  5

{
        .store                  = ao_can_async_send_store_2 +  5 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  6

{
        .store                  = ao_can_async_send_store_2 +  6 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  7

{
        .store                  = ao_can_async_send_store_2 +  7 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  8

{
        .store                  = ao_can_async_send_store_2 +  8 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 >  9

{
        .store                  = ao_can_async_send_store_2 +  9 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 10

{
        .store                  = ao_can_async_send_store_2 + 10 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 11

{
        .store                  = ao_can_async_send_store_2 + 11 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 12

{
        .store                  = ao_can_async_send_store_2 + 12 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 13

{
        .store                  = ao_can_async_send_store_2 + 13 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 14

{
        .store                  = ao_can_async_send_store_2 + 14 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 15

{
        .store                  = ao_can_async_send_store_2 + 15 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 16

{
        .store                  = ao_can_async_send_store_2 + 16 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 17

{
        .store                  = ao_can_async_send_store_2 + 17 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 18

{
        .store                  = ao_can_async_send_store_2 + 18 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 19

{
        .store                  = ao_can_async_send_store_2 + 19 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 20

{
        .store                  = ao_can_async_send_store_2 + 20 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 21

{
        .store                  = ao_can_async_send_store_2 + 21 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 22

{
        .store                  = ao_can_async_send_store_2 + 22 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 23

{
        .store                  = ao_can_async_send_store_2 + 23 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 24

{
        .store                  = ao_can_async_send_store_2 + 24 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 25

{
        .store                  = ao_can_async_send_store_2 + 25 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 26

{
        .store                  = ao_can_async_send_store_2 + 26 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 27

{
        .store                  = ao_can_async_send_store_2 + 27 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 28

{
        .store                  = ao_can_async_send_store_2 + 28 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 29

{
        .store                  = ao_can_async_send_store_2 + 29 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 30

{
        .store                  = ao_can_async_send_store_2 + 30 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_2 > 31

{
        .store                  = ao_can_async_send_store_2 + 31 * 2,

        .count                  = 2
},

#endif

#endif

};

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_started_store_2[AO_CAN_FIFOS_TX_2 + 2] =
{
        &ao_can_cond_change_wait_2.async,

        &ao_can_sem_take_2.async,

#if AO_CAN_FIFOS_TX_2 >  0

#if AO_CAN_FIFOS_TX_2 >  0

        &ao_can_async_send_2[ 0].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  1

        &ao_can_async_send_2[ 1].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  2

        &ao_can_async_send_2[ 2].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  3

        &ao_can_async_send_2[ 3].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  4

        &ao_can_async_send_2[ 4].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  5

        &ao_can_async_send_2[ 5].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  6

        &ao_can_async_send_2[ 6].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  7

        &ao_can_async_send_2[ 7].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  8

        &ao_can_async_send_2[ 8].async,

#endif

#if AO_CAN_FIFOS_TX_2 >  9

        &ao_can_async_send_2[ 9].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 10

        &ao_can_async_send_2[10].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 11

        &ao_can_async_send_2[11].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 12

        &ao_can_async_send_2[12].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 13

        &ao_can_async_send_2[13].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 14

        &ao_can_async_send_2[14].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 15

        &ao_can_async_send_2[15].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 16

        &ao_can_async_send_2[16].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 17

        &ao_can_async_send_2[17].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 18

        &ao_can_async_send_2[18].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 19

        &ao_can_async_send_2[19].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 20

        &ao_can_async_send_2[20].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 21

        &ao_can_async_send_2[21].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 22

        &ao_can_async_send_2[22].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 23

        &ao_can_async_send_2[23].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 24

        &ao_can_async_send_2[24].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 25

        &ao_can_async_send_2[25].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 26

        &ao_can_async_send_2[26].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 27

        &ao_can_async_send_2[27].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 28

        &ao_can_async_send_2[28].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 29

        &ao_can_async_send_2[29].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 30

        &ao_can_async_send_2[30].async,

#endif

#if AO_CAN_FIFOS_TX_2 > 31

        &ao_can_async_send_2[31].async,

#endif

#endif

};

static  ao_async_any_t          ao_can_async_started_2 =
{
        .store                  = ao_can_async_started_store_2,

        .count                  = 2 + AO_CAN_FIFOS_TX_2
};

// ----------------------------------------------------------------------------

void ao_can_change_2(uint32_t mode)
{
    // Assert.

    ao_assert
    (
        mode == 0 ||
        mode == 2 ||
        mode == 3 ||
        mode == 4 ||
        mode == 7
    );


    // Variables.

    ao_can_reg_t * const reg = ao_can_reg_2();


    // Ready.

    while (reg->con.bits.opmod != mode)
    {
        // Request.

        ao_cond_clear(&ao_can_cond_changed_2);

        reg->con.bits.reqop = mode;


        // Await.

        ao_cond_wait_begin( &ao_can_cond_changed_wait_2);

        ao_sem_take_begin(  &ao_can_sem_take_2);

        ao_await_any_forever
        (
            &ao_can_async_change_2
        );

        ao_sem_take_end(    &ao_can_sem_take_2);

        ao_cond_wait_end(   &ao_can_cond_changed_wait_2);


        // Stop.

        if (ao_can_sem_take_2.result)
        {
            ao_can_var_started_2 = false;
        }
    }
}

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_can_config_2()
{
    ao_can_config_baud_2();

    ao_can_config_fifos_2();

    ao_can_config_filter_masks_2();

    ao_can_config_filters_2();
}

__attribute__ ((weak))
void ao_can_config_baud_2()
{
    // Variables.

    ao_can_baud_t x;


    // Ready.

    x.f                 = AO_CAN_BAUD_2;

    x.f_pbclk           = AO_SYS_CLOCK_CAN2;

    x.sample            = AO_CAN_BAUD_SAMPLE_2;

    x.sample_thrice     = AO_CAN_BAUD_SAMPLE_THRICE_2;

    x.sjw               = AO_CAN_BAUD_SJW_2;

    x.wake_up_filter    = AO_CAN_BAUD_WAKE_UP_FILTER_2;

    ao_can_baud(&x);

    ao_assert(x.result);

    C2CFG = x.cfg;
}

__attribute__ ((weak))
void ao_can_config_fifos_2()
{
    // Fifo base address.

    C2FIFOBA = KVA_TO_PA(ao_can_buffers_2);


    // Fifos.

#if AO_CAN_FIFOS_2 > 0

#if AO_CAN_FIFOS_2 > 0

    C2FIFOCON0bits.FSIZE = AO_CAN_BUFFERS_2_0 - 1;

#endif

#if AO_CAN_FIFOS_2 > 1

    C2FIFOCON1bits.FSIZE = AO_CAN_BUFFERS_2_1 - 1;

#endif

#if AO_CAN_FIFOS_2 > 2

    C2FIFOCON2bits.FSIZE = AO_CAN_BUFFERS_2_2 - 1;

#endif

#if AO_CAN_FIFOS_2 > 3

    C2FIFOCON3bits.FSIZE = AO_CAN_BUFFERS_2_3 - 1;

#endif

#if AO_CAN_FIFOS_2 > 4

    C2FIFOCON4bits.FSIZE = AO_CAN_BUFFERS_2_4 - 1;

#endif

#if AO_CAN_FIFOS_2 > 5

    C2FIFOCON5bits.FSIZE = AO_CAN_BUFFERS_2_5 - 1;

#endif

#if AO_CAN_FIFOS_2 > 6

    C2FIFOCON6bits.FSIZE = AO_CAN_BUFFERS_2_6 - 1;

#endif

#if AO_CAN_FIFOS_2 > 7

    C2FIFOCON7bits.FSIZE = AO_CAN_BUFFERS_2_7 - 1;

#endif

#if AO_CAN_FIFOS_2 > 8

    C2FIFOCON8bits.FSIZE = AO_CAN_BUFFERS_2_8 - 1;

#endif

#if AO_CAN_FIFOS_2 > 9

    C2FIFOCON9bits.FSIZE = AO_CAN_BUFFERS_2_9 - 1;

#endif

#if AO_CAN_FIFOS_2 > 10

    C2FIFOCON10bits.FSIZE = AO_CAN_BUFFERS_2_10 - 1;

#endif

#if AO_CAN_FIFOS_2 > 11

    C2FIFOCON11bits.FSIZE = AO_CAN_BUFFERS_2_11 - 1;

#endif

#if AO_CAN_FIFOS_2 > 12

    C2FIFOCON12bits.FSIZE = AO_CAN_BUFFERS_2_12 - 1;

#endif

#if AO_CAN_FIFOS_2 > 13

    C2FIFOCON13bits.FSIZE = AO_CAN_BUFFERS_2_13 - 1;

#endif

#if AO_CAN_FIFOS_2 > 14

    C2FIFOCON14bits.FSIZE = AO_CAN_BUFFERS_2_14 - 1;

#endif

#if AO_CAN_FIFOS_2 > 15

    C2FIFOCON15bits.FSIZE = AO_CAN_BUFFERS_2_15 - 1;

#endif

#if AO_CAN_FIFOS_2 > 16

    C2FIFOCON16bits.FSIZE = AO_CAN_BUFFERS_2_16 - 1;

#endif

#if AO_CAN_FIFOS_2 > 17

    C2FIFOCON17bits.FSIZE = AO_CAN_BUFFERS_2_17 - 1;

#endif

#if AO_CAN_FIFOS_2 > 18

    C2FIFOCON18bits.FSIZE = AO_CAN_BUFFERS_2_18 - 1;

#endif

#if AO_CAN_FIFOS_2 > 19

    C2FIFOCON19bits.FSIZE = AO_CAN_BUFFERS_2_19 - 1;

#endif

#if AO_CAN_FIFOS_2 > 20

    C2FIFOCON20bits.FSIZE = AO_CAN_BUFFERS_2_20 - 1;

#endif

#if AO_CAN_FIFOS_2 > 21

    C2FIFOCON21bits.FSIZE = AO_CAN_BUFFERS_2_21 - 1;

#endif

#if AO_CAN_FIFOS_2 > 22

    C2FIFOCON22bits.FSIZE = AO_CAN_BUFFERS_2_22 - 1;

#endif

#if AO_CAN_FIFOS_2 > 23

    C2FIFOCON23bits.FSIZE = AO_CAN_BUFFERS_2_23 - 1;

#endif

#if AO_CAN_FIFOS_2 > 24

    C2FIFOCON24bits.FSIZE = AO_CAN_BUFFERS_2_24 - 1;

#endif

#if AO_CAN_FIFOS_2 > 25

    C2FIFOCON25bits.FSIZE = AO_CAN_BUFFERS_2_25 - 1;

#endif

#if AO_CAN_FIFOS_2 > 26

    C2FIFOCON26bits.FSIZE = AO_CAN_BUFFERS_2_26 - 1;

#endif

#if AO_CAN_FIFOS_2 > 27

    C2FIFOCON27bits.FSIZE = AO_CAN_BUFFERS_2_27 - 1;

#endif

#if AO_CAN_FIFOS_2 > 28

    C2FIFOCON28bits.FSIZE = AO_CAN_BUFFERS_2_28 - 1;

#endif

#if AO_CAN_FIFOS_2 > 29

    C2FIFOCON29bits.FSIZE = AO_CAN_BUFFERS_2_29 - 1;

#endif

#if AO_CAN_FIFOS_2 > 30

    C2FIFOCON30bits.FSIZE = AO_CAN_BUFFERS_2_30 - 1;

#endif

#if AO_CAN_FIFOS_2 > 31

    C2FIFOCON31bits.FSIZE = AO_CAN_BUFFERS_2_31 - 1;

#endif

#endif

}

__attribute__ ((weak))
void ao_can_config_filter_masks_2()
{
    C2RXM0bits.EID  = AO_CAN_FILTER_MASK_EID_2_0;
    C2RXM0bits.MIDE = AO_CAN_FILTER_MASK_IDE_2_0;
    C2RXM0bits.SID  = AO_CAN_FILTER_MASK_SID_2_0;

    C2RXM1bits.EID  = AO_CAN_FILTER_MASK_EID_2_1;
    C2RXM1bits.MIDE = AO_CAN_FILTER_MASK_IDE_2_1;
    C2RXM1bits.SID  = AO_CAN_FILTER_MASK_SID_2_1;

    C2RXM2bits.EID  = AO_CAN_FILTER_MASK_EID_2_2;
    C2RXM2bits.MIDE = AO_CAN_FILTER_MASK_IDE_2_2;
    C2RXM2bits.SID  = AO_CAN_FILTER_MASK_SID_2_2;

    C2RXM3bits.EID  = AO_CAN_FILTER_MASK_EID_2_3;
    C2RXM3bits.MIDE = AO_CAN_FILTER_MASK_IDE_2_3;
    C2RXM3bits.SID  = AO_CAN_FILTER_MASK_SID_2_3;
}

__attribute__ ((weak))
void ao_can_config_filters_2()
{

#if AO_CAN_FILTER_ENABLE_2_0

    C2RXF0bits.EID          = AO_CAN_FILTER_EID_2_0;
    C2RXF0bits.EXID         = AO_CAN_FILTER_IDE_2_0;
    C2RXF0bits.SID          = AO_CAN_FILTER_SID_2_0;
    C2FLTCON0bits.FSEL0     = AO_CAN_FILTER_FIFO_2_0;
    C2FLTCON0bits.MSEL0     = AO_CAN_FILTER_MASK_2_0;
    C2FLTCON0bits.FLTEN0    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_1

    C2RXF1bits.EID          = AO_CAN_FILTER_EID_2_1;
    C2RXF1bits.EXID         = AO_CAN_FILTER_IDE_2_1;
    C2RXF1bits.SID          = AO_CAN_FILTER_SID_2_1;
    C2FLTCON0bits.FSEL1     = AO_CAN_FILTER_FIFO_2_1;
    C2FLTCON0bits.MSEL1     = AO_CAN_FILTER_MASK_2_1;
    C2FLTCON0bits.FLTEN1    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_2

    C2RXF2bits.EID          = AO_CAN_FILTER_EID_2_2;
    C2RXF2bits.EXID         = AO_CAN_FILTER_IDE_2_2;
    C2RXF2bits.SID          = AO_CAN_FILTER_SID_2_2;
    C2FLTCON0bits.FSEL2     = AO_CAN_FILTER_FIFO_2_2;
    C2FLTCON0bits.MSEL2     = AO_CAN_FILTER_MASK_2_2;
    C2FLTCON0bits.FLTEN2    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_3

    C2RXF3bits.EID          = AO_CAN_FILTER_EID_2_3;
    C2RXF3bits.EXID         = AO_CAN_FILTER_IDE_2_3;
    C2RXF3bits.SID          = AO_CAN_FILTER_SID_2_3;
    C2FLTCON0bits.FSEL3     = AO_CAN_FILTER_FIFO_2_3;
    C2FLTCON0bits.MSEL3     = AO_CAN_FILTER_MASK_2_3;
    C2FLTCON0bits.FLTEN3    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_4

    C2RXF4bits.EID          = AO_CAN_FILTER_EID_2_4;
    C2RXF4bits.EXID         = AO_CAN_FILTER_IDE_2_4;
    C2RXF4bits.SID          = AO_CAN_FILTER_SID_2_4;
    C2FLTCON1bits.FSEL4     = AO_CAN_FILTER_FIFO_2_4;
    C2FLTCON1bits.MSEL4     = AO_CAN_FILTER_MASK_2_4;
    C2FLTCON1bits.FLTEN4    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_5

    C2RXF5bits.EID          = AO_CAN_FILTER_EID_2_5;
    C2RXF5bits.EXID         = AO_CAN_FILTER_IDE_2_5;
    C2RXF5bits.SID          = AO_CAN_FILTER_SID_2_5;
    C2FLTCON1bits.FSEL5     = AO_CAN_FILTER_FIFO_2_5;
    C2FLTCON1bits.MSEL5     = AO_CAN_FILTER_MASK_2_5;
    C2FLTCON1bits.FLTEN5    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_6

    C2RXF6bits.EID          = AO_CAN_FILTER_EID_2_6;
    C2RXF6bits.EXID         = AO_CAN_FILTER_IDE_2_6;
    C2RXF6bits.SID          = AO_CAN_FILTER_SID_2_6;
    C2FLTCON1bits.FSEL6     = AO_CAN_FILTER_FIFO_2_6;
    C2FLTCON1bits.MSEL6     = AO_CAN_FILTER_MASK_2_6;
    C2FLTCON1bits.FLTEN6    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_7

    C2RXF7bits.EID          = AO_CAN_FILTER_EID_2_7;
    C2RXF7bits.EXID         = AO_CAN_FILTER_IDE_2_7;
    C2RXF7bits.SID          = AO_CAN_FILTER_SID_2_7;
    C2FLTCON1bits.FSEL7     = AO_CAN_FILTER_FIFO_2_7;
    C2FLTCON1bits.MSEL7     = AO_CAN_FILTER_MASK_2_7;
    C2FLTCON1bits.FLTEN7    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_8

    C2RXF8bits.EID          = AO_CAN_FILTER_EID_2_8;
    C2RXF8bits.EXID         = AO_CAN_FILTER_IDE_2_8;
    C2RXF8bits.SID          = AO_CAN_FILTER_SID_2_8;
    C2FLTCON2bits.FSEL8     = AO_CAN_FILTER_FIFO_2_8;
    C2FLTCON2bits.MSEL8     = AO_CAN_FILTER_MASK_2_8;
    C2FLTCON2bits.FLTEN8    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_9

    C2RXF9bits.EID          = AO_CAN_FILTER_EID_2_9;
    C2RXF9bits.EXID         = AO_CAN_FILTER_IDE_2_9;
    C2RXF9bits.SID          = AO_CAN_FILTER_SID_2_9;
    C2FLTCON2bits.FSEL9     = AO_CAN_FILTER_FIFO_2_9;
    C2FLTCON2bits.MSEL9     = AO_CAN_FILTER_MASK_2_9;
    C2FLTCON2bits.FLTEN9    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_10

    C2RXF10bits.EID         = AO_CAN_FILTER_EID_2_10;
    C2RXF10bits.EXID        = AO_CAN_FILTER_IDE_2_10;
    C2RXF10bits.SID         = AO_CAN_FILTER_SID_2_10;
    C2FLTCON2bits.FSEL10    = AO_CAN_FILTER_FIFO_2_10;
    C2FLTCON2bits.MSEL10    = AO_CAN_FILTER_MASK_2_10;
    C2FLTCON2bits.FLTEN10   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_11

    C2RXF11bits.EID         = AO_CAN_FILTER_EID_2_11;
    C2RXF11bits.EXID        = AO_CAN_FILTER_IDE_2_11;
    C2RXF11bits.SID         = AO_CAN_FILTER_SID_2_11;
    C2FLTCON2bits.FSEL11    = AO_CAN_FILTER_FIFO_2_11;
    C2FLTCON2bits.MSEL11    = AO_CAN_FILTER_MASK_2_11;
    C2FLTCON2bits.FLTEN11   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_12

    C2RXF12bits.EID         = AO_CAN_FILTER_EID_2_12;
    C2RXF12bits.EXID        = AO_CAN_FILTER_IDE_2_12;
    C2RXF12bits.SID         = AO_CAN_FILTER_SID_2_12;
    C2FLTCON3bits.FSEL12    = AO_CAN_FILTER_FIFO_2_12;
    C2FLTCON3bits.MSEL12    = AO_CAN_FILTER_MASK_2_12;
    C2FLTCON3bits.FLTEN12   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_13

    C2RXF13bits.EID         = AO_CAN_FILTER_EID_2_13;
    C2RXF13bits.EXID        = AO_CAN_FILTER_IDE_2_13;
    C2RXF13bits.SID         = AO_CAN_FILTER_SID_2_13;
    C2FLTCON3bits.FSEL13    = AO_CAN_FILTER_FIFO_2_13;
    C2FLTCON3bits.MSEL13    = AO_CAN_FILTER_MASK_2_13;
    C2FLTCON3bits.FLTEN13   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_14

    C2RXF14bits.EID         = AO_CAN_FILTER_EID_2_14;
    C2RXF14bits.EXID        = AO_CAN_FILTER_IDE_2_14;
    C2RXF14bits.SID         = AO_CAN_FILTER_SID_2_14;
    C2FLTCON3bits.FSEL14    = AO_CAN_FILTER_FIFO_2_14;
    C2FLTCON3bits.MSEL14    = AO_CAN_FILTER_MASK_2_14;
    C2FLTCON3bits.FLTEN14   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_15

    C2RXF15bits.EID         = AO_CAN_FILTER_EID_2_15;
    C2RXF15bits.EXID        = AO_CAN_FILTER_IDE_2_15;
    C2RXF15bits.SID         = AO_CAN_FILTER_SID_2_15;
    C2FLTCON3bits.FSEL15    = AO_CAN_FILTER_FIFO_2_15;
    C2FLTCON3bits.MSEL15    = AO_CAN_FILTER_MASK_2_15;
    C2FLTCON3bits.FLTEN15   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_16

    C2RXF16bits.EID         = AO_CAN_FILTER_EID_2_16;
    C2RXF16bits.EXID        = AO_CAN_FILTER_IDE_2_16;
    C2RXF16bits.SID         = AO_CAN_FILTER_SID_2_16;
    C2FLTCON4bits.FSEL16    = AO_CAN_FILTER_FIFO_2_16;
    C2FLTCON4bits.MSEL16    = AO_CAN_FILTER_MASK_2_16;
    C2FLTCON4bits.FLTEN16   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_17

    C2RXF17bits.EID         = AO_CAN_FILTER_EID_2_17;
    C2RXF17bits.EXID        = AO_CAN_FILTER_IDE_2_17;
    C2RXF17bits.SID         = AO_CAN_FILTER_SID_2_17;
    C2FLTCON4bits.FSEL17    = AO_CAN_FILTER_FIFO_2_17;
    C2FLTCON4bits.MSEL17    = AO_CAN_FILTER_MASK_2_17;
    C2FLTCON4bits.FLTEN17   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_18

    C2RXF18bits.EID         = AO_CAN_FILTER_EID_2_18;
    C2RXF18bits.EXID        = AO_CAN_FILTER_IDE_2_18;
    C2RXF18bits.SID         = AO_CAN_FILTER_SID_2_18;
    C2FLTCON4bits.FSEL18    = AO_CAN_FILTER_FIFO_2_18;
    C2FLTCON4bits.MSEL18    = AO_CAN_FILTER_MASK_2_18;
    C2FLTCON4bits.FLTEN18   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_19

    C2RXF19bits.EID         = AO_CAN_FILTER_EID_2_19;
    C2RXF19bits.EXID        = AO_CAN_FILTER_IDE_2_19;
    C2RXF19bits.SID         = AO_CAN_FILTER_SID_2_19;
    C2FLTCON4bits.FSEL19    = AO_CAN_FILTER_FIFO_2_19;
    C2FLTCON4bits.MSEL19    = AO_CAN_FILTER_MASK_2_19;
    C2FLTCON4bits.FLTEN19   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_20

    C2RXF20bits.EID         = AO_CAN_FILTER_EID_2_20;
    C2RXF20bits.EXID        = AO_CAN_FILTER_IDE_2_20;
    C2RXF20bits.SID         = AO_CAN_FILTER_SID_2_20;
    C2FLTCON5bits.FSEL20    = AO_CAN_FILTER_FIFO_2_20;
    C2FLTCON5bits.MSEL20    = AO_CAN_FILTER_MASK_2_20;
    C2FLTCON5bits.FLTEN20   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_21

    C2RXF21bits.EID         = AO_CAN_FILTER_EID_2_21;
    C2RXF21bits.EXID        = AO_CAN_FILTER_IDE_2_21;
    C2RXF21bits.SID         = AO_CAN_FILTER_SID_2_21;
    C2FLTCON5bits.FSEL21    = AO_CAN_FILTER_FIFO_2_21;
    C2FLTCON5bits.MSEL21    = AO_CAN_FILTER_MASK_2_21;
    C2FLTCON5bits.FLTEN21   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_22

    C2RXF22bits.EID         = AO_CAN_FILTER_EID_2_22;
    C2RXF22bits.EXID        = AO_CAN_FILTER_IDE_2_22;
    C2RXF22bits.SID         = AO_CAN_FILTER_SID_2_22;
    C2FLTCON5bits.FSEL22    = AO_CAN_FILTER_FIFO_2_22;
    C2FLTCON5bits.MSEL22    = AO_CAN_FILTER_MASK_2_22;
    C2FLTCON5bits.FLTEN22   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_23

    C2RXF23bits.EID         = AO_CAN_FILTER_EID_2_23;
    C2RXF23bits.EXID        = AO_CAN_FILTER_IDE_2_23;
    C2RXF23bits.SID         = AO_CAN_FILTER_SID_2_23;
    C2FLTCON5bits.FSEL23    = AO_CAN_FILTER_FIFO_2_23;
    C2FLTCON5bits.MSEL23    = AO_CAN_FILTER_MASK_2_23;
    C2FLTCON5bits.FLTEN23   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_24

    C2RXF24bits.EID         = AO_CAN_FILTER_EID_2_24;
    C2RXF24bits.EXID        = AO_CAN_FILTER_IDE_2_24;
    C2RXF24bits.SID         = AO_CAN_FILTER_SID_2_24;
    C2FLTCON6bits.FSEL24    = AO_CAN_FILTER_FIFO_2_24;
    C2FLTCON6bits.MSEL24    = AO_CAN_FILTER_MASK_2_24;
    C2FLTCON6bits.FLTEN24   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_25

    C2RXF25bits.EID         = AO_CAN_FILTER_EID_2_25;
    C2RXF25bits.EXID        = AO_CAN_FILTER_IDE_2_25;
    C2RXF25bits.SID         = AO_CAN_FILTER_SID_2_25;
    C2FLTCON6bits.FSEL25    = AO_CAN_FILTER_FIFO_2_25;
    C2FLTCON6bits.MSEL25    = AO_CAN_FILTER_MASK_2_25;
    C2FLTCON6bits.FLTEN25   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_26

    C2RXF26bits.EID         = AO_CAN_FILTER_EID_2_26;
    C2RXF26bits.EXID        = AO_CAN_FILTER_IDE_2_26;
    C2RXF26bits.SID         = AO_CAN_FILTER_SID_2_26;
    C2FLTCON6bits.FSEL26    = AO_CAN_FILTER_FIFO_2_26;
    C2FLTCON6bits.MSEL26    = AO_CAN_FILTER_MASK_2_26;
    C2FLTCON6bits.FLTEN26   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_27

    C2RXF27bits.EID         = AO_CAN_FILTER_EID_2_27;
    C2RXF27bits.EXID        = AO_CAN_FILTER_IDE_2_27;
    C2RXF27bits.SID         = AO_CAN_FILTER_SID_2_27;
    C2FLTCON6bits.FSEL27    = AO_CAN_FILTER_FIFO_2_27;
    C2FLTCON6bits.MSEL27    = AO_CAN_FILTER_MASK_2_27;
    C2FLTCON6bits.FLTEN27   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_28

    C2RXF28bits.EID         = AO_CAN_FILTER_EID_2_28;
    C2RXF28bits.EXID        = AO_CAN_FILTER_IDE_2_28;
    C2RXF28bits.SID         = AO_CAN_FILTER_SID_2_28;
    C2FLTCON7bits.FSEL28    = AO_CAN_FILTER_FIFO_2_28;
    C2FLTCON7bits.MSEL28    = AO_CAN_FILTER_MASK_2_28;
    C2FLTCON7bits.FLTEN28   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_29

    C2RXF29bits.EID         = AO_CAN_FILTER_EID_2_29;
    C2RXF29bits.EXID        = AO_CAN_FILTER_IDE_2_29;
    C2RXF29bits.SID         = AO_CAN_FILTER_SID_2_29;
    C2FLTCON7bits.FSEL29    = AO_CAN_FILTER_FIFO_2_29;
    C2FLTCON7bits.MSEL29    = AO_CAN_FILTER_MASK_2_29;
    C2FLTCON7bits.FLTEN29   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_30

    C2RXF30bits.EID         = AO_CAN_FILTER_EID_2_30;
    C2RXF30bits.EXID        = AO_CAN_FILTER_IDE_2_30;
    C2RXF30bits.SID         = AO_CAN_FILTER_SID_2_30;
    C2FLTCON7bits.FSEL30    = AO_CAN_FILTER_FIFO_2_30;
    C2FLTCON7bits.MSEL30    = AO_CAN_FILTER_MASK_2_30;
    C2FLTCON7bits.FLTEN30   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_2_31

    C2RXF31bits.EID         = AO_CAN_FILTER_EID_2_31;
    C2RXF31bits.EXID        = AO_CAN_FILTER_IDE_2_31;
    C2RXF31bits.SID         = AO_CAN_FILTER_SID_2_31;
    C2FLTCON7bits.FSEL31    = AO_CAN_FILTER_FIFO_2_31;
    C2FLTCON7bits.MSEL31    = AO_CAN_FILTER_MASK_2_31;
    C2FLTCON7bits.FLTEN31   = 1;

#endif

}

// ----------------------------------------------------------------------------

void ao_can_ir_2()
{
    // Variables.

    ao_can_t *          c1;
    ao_can_t *          c2;

    ao_can_fifo_flags_t f;

    uint32_t            i1;
    uint32_t            i2;

    uint32_t            m;

    uint32_t            r;

    ao_can_reg_t *      reg = ao_can_reg_2();

    ao_time_t           t;


    // Ready.

    do
    {
        t = ao_now();

        i1 = reg->vec.bits.icode;

        ao_ir_can2_reply();

        switch (i1)
        {

#if AO_CAN_INVALID_2

            case 0b1001000:

                // Invalid message received.

                ao_can_invalid_2(&ao_can_invalid_info_2);

                reg->intx.bits.ivrif = 0;

                break;

#endif

                // Mode changed.

            case 0b1000111:

#if AO_CAN_MODE_2

                ao_can_mode_2(&ao_can_mode_info_2);

#endif

                ao_cond_set(&ao_can_cond_changed_2);

                reg->intx.bits.modif = 0;

                break;

#if AO_CAN_TIMER_2

            case 0b1000110:

                // Timer.

                ao_can_timer_2(&ao_can_timer_info_2);

                reg->intx.bits.ctmrif = 0;

                break;

#endif

            case 0b1000101:
            case 0b1000100:

                // System error.

#if AO_CAN_SYSTEM_2

                ao_can_system_info_2.flags = (ao_can_system_flags_t) i1;

                ao_can_system_2(&ao_can_system_info_2);

#endif

                reg->con.bits.on = 0;

                while (reg->con.bits.canbusy) { }

                reg->con.bits.on = 1;

                break;

#if AO_CAN_RBOV_2

            case 0b1000011:

                // Receive buffer overrun.

                r = reg->rxovf.reg;

                m = (AO_CAN_FIFOS_TX_2 == 32) ? UINT32_MAX : (1 << AO_CAN_FIFOS_TX_2) - 1;

#if AO_CAN_RXOF_2

                f = (ao_can_fifo_flags_t) (r & ~m);

                if (f != AO_CAN_FIFO_FLAGS_NONE)
                {
                    ao_can_overflow_info_2.fifos = f;

                    ao_can_overflow_info_2.fifos_rx = (ao_can_fifo_flags_t) ((uint32_t) f >> AO_CAN_FIFOS_TX_2);

                    ao_can_overflow_2(&ao_can_overflow_info_2);
                }

#endif

#if AO_CAN_TXUF_2

                f = (ao_can_fifo_flags_t) (r & m);

                if (f != AO_CAN_FIFO_FLAGS_NONE)
                {
                    ao_can_underflow_info_2.fifos = f;

                    ao_can_underflow_info_2.fifos_tx = f;

                    ao_can_underflow_2(&ao_can_underflow_info_2);
                }

#endif

                // DS61154.

                // Section 34.12.1.17.

                // Clearing all the CxFIFOINTn.RXOVFLIF bits will automatically
                // clear the CxINT.RBOVIF bit.

                while (r)
                {
                    i2 = ao_ffsu(r);

                    m = 1 << i2;

                    r = r & ~m;

                    reg->fifo[i2].intx.bits.rxovflif = 0;
                }

                // DS61154.

                // Section 34.12.1.17: The CxINT.RBOVIF bit is not directly clearable.

                // Section 34.3.4    : The CxINT.RBOVIF bit is writable.

                reg->intx.bits.rbovif = 0;

                break;

#endif

#if AO_CAN_WAKE_UP_2

            case 0b1000010:

                // Wake up.

                ao_can_wake_up_2(&ao_can_wake_up_info_2);

                reg->intx.bits.wakif = 0;

                break;

#endif

#if AO_CAN_BUS_2

            case 0b1000001:

                // CAN bus error.

                ao_can_bus_info_2.receive_error_counter = reg->trec.bits.rerrcnt;

                if (reg->trec.bits.rxbp)
                {
                    ao_can_bus_info_2.receive_error_state = AO_CAN_BUS_PASSIVE;
                }

                else if (reg->trec.bits.rxwarn)
                {
                    ao_can_bus_info_2.receive_error_state = AO_CAN_BUS_ACTIVE_WARNING;
                }

                else
                {
                    ao_can_bus_info_2.receive_error_state = AO_CAN_BUS_ACTIVE;
                }

                ao_can_bus_info_2.transmit_error_counter = reg->trec.bits.terrcnt;

                if (reg->trec.bits.txbo)
                {
                    ao_can_bus_info_2.transmit_error_state = AO_CAN_BUS_OFF;
                }

                else if (reg->trec.bits.txbp)
                {
                    ao_can_bus_info_2.transmit_error_state = AO_CAN_BUS_PASSIVE;
                }

                else if (reg->trec.bits.txwarn)
                {
                    ao_can_bus_info_2.transmit_error_state = AO_CAN_BUS_ACTIVE_WARNING;
                }

                else
                {
                    ao_can_bus_info_2.transmit_error_state = AO_CAN_BUS_ACTIVE;
                }

                ao_can_bus_2(&ao_can_bus_info_2);

                reg->intx.bits.cerrif = 0;

                break;

#endif

            case 0b1000000:

                // No interrupt.

                break;

#if AO_CAN_RX_2

#if AO_CAN_FIFOS_2 > 31  &&  AO_CAN_FIFOS_TX_2 <= 31

            case 31:

#endif

#if AO_CAN_FIFOS_2 > 30  &&  AO_CAN_FIFOS_TX_2 <= 30

            case 30:

#endif

#if AO_CAN_FIFOS_2 > 29  &&  AO_CAN_FIFOS_TX_2 <= 29

            case 29:

#endif

#if AO_CAN_FIFOS_2 > 28  &&  AO_CAN_FIFOS_TX_2 <= 28

            case 28:

#endif

#if AO_CAN_FIFOS_2 > 27  &&  AO_CAN_FIFOS_TX_2 <= 27

            case 27:

#endif

#if AO_CAN_FIFOS_2 > 26  &&  AO_CAN_FIFOS_TX_2 <= 26

            case 26:

#endif

#if AO_CAN_FIFOS_2 > 25  &&  AO_CAN_FIFOS_TX_2 <= 25

            case 25:

#endif

#if AO_CAN_FIFOS_2 > 24  &&  AO_CAN_FIFOS_TX_2 <= 24

            case 24:

#endif

#if AO_CAN_FIFOS_2 > 23  &&  AO_CAN_FIFOS_TX_2 <= 23

            case 23:

#endif

#if AO_CAN_FIFOS_2 > 22  &&  AO_CAN_FIFOS_TX_2 <= 22

            case 22:

#endif

#if AO_CAN_FIFOS_2 > 21  &&  AO_CAN_FIFOS_TX_2 <= 21

            case 21:

#endif

#if AO_CAN_FIFOS_2 > 20  &&  AO_CAN_FIFOS_TX_2 <= 20

            case 20:

#endif

#if AO_CAN_FIFOS_2 > 19  &&  AO_CAN_FIFOS_TX_2 <= 19

            case 19:

#endif

#if AO_CAN_FIFOS_2 > 18  &&  AO_CAN_FIFOS_TX_2 <= 18

            case 18:

#endif

#if AO_CAN_FIFOS_2 > 17  &&  AO_CAN_FIFOS_TX_2 <= 17

            case 17:

#endif

#if AO_CAN_FIFOS_2 > 16  &&  AO_CAN_FIFOS_TX_2 <= 16

            case 16:

#endif

#if AO_CAN_FIFOS_2 > 15  &&  AO_CAN_FIFOS_TX_2 <= 15

            case 15:

#endif

#if AO_CAN_FIFOS_2 > 14  &&  AO_CAN_FIFOS_TX_2 <= 14

            case 14:

#endif

#if AO_CAN_FIFOS_2 > 13  &&  AO_CAN_FIFOS_TX_2 <= 13

            case 13:

#endif

#if AO_CAN_FIFOS_2 > 12  &&  AO_CAN_FIFOS_TX_2 <= 12

            case 12:

#endif

#if AO_CAN_FIFOS_2 > 11  &&  AO_CAN_FIFOS_TX_2 <= 11

            case 11:

#endif

#if AO_CAN_FIFOS_2 > 10  &&  AO_CAN_FIFOS_TX_2 <= 10

            case 10:

#endif

#if AO_CAN_FIFOS_2 >  9  &&  AO_CAN_FIFOS_TX_2 <=  9

            case  9:

#endif

#if AO_CAN_FIFOS_2 >  8  &&  AO_CAN_FIFOS_TX_2 <=  8

            case  8:

#endif

#if AO_CAN_FIFOS_2 >  7  &&  AO_CAN_FIFOS_TX_2 <=  7

            case  7:

#endif

#if AO_CAN_FIFOS_2 >  6  &&  AO_CAN_FIFOS_TX_2 <=  6

            case  6:

#endif

#if AO_CAN_FIFOS_2 >  5  &&  AO_CAN_FIFOS_TX_2 <=  5

            case  5:

#endif

#if AO_CAN_FIFOS_2 >  4  &&  AO_CAN_FIFOS_TX_2 <=  4

            case  4:

#endif

#if AO_CAN_FIFOS_2 >  3  &&  AO_CAN_FIFOS_TX_2 <=  3

            case  3:

#endif

#if AO_CAN_FIFOS_2 >  2  &&  AO_CAN_FIFOS_TX_2 <=  2

            case  2:

#endif

#if AO_CAN_FIFOS_2 >  1  &&  AO_CAN_FIFOS_TX_2 <=  1

            case  1:

#endif

#if AO_CAN_FIFOS_2 >  0  &&  AO_CAN_FIFOS_TX_2 <=  0

            case  0:

#endif

                c1 = PA_TO_KVA1(reg->fifo[i1].ua.reg);

                c2 = ao_can_in_can_2 + i1 - AO_CAN_FIFOS_TX_2;

                if (reg->fifo[i1].con.bits.donly)
                {
                    c2->cmsgsid = 0;

                    c2->cmsgeid = 0;

                    c2->data = *((uint64_t *) c1);
                }

                else
                {
                    *c2 = *c1;
                }

                if (!c2->ide && c2->srr)
                {
                    c2->rtr = 1;
                }

                ao_send_obj_try(ao_can_in_2 + i1 - AO_CAN_FIFOS_TX_2);

                // DS80000480.

                // The CxFIFOCONn.FRESET bit and the CxFIFOCONn.UINC
                // bit are not settable through a normal Special
                // Function Register (SFR) write.

                // Use the SET register operations to change the state
                // of these bits.

                reg->fifo[i1].con.set = _C2FIFOCON0_UINC_MASK;

                break;

#endif

#if AO_CAN_TX_2

#if AO_CAN_FIFOS_2 > 31  &&  AO_CAN_FIFOS_TX_2 > 31

            case 31:

#endif

#if AO_CAN_FIFOS_2 > 30  &&  AO_CAN_FIFOS_TX_2 > 30

            case 30:

#endif

#if AO_CAN_FIFOS_2 > 29  &&  AO_CAN_FIFOS_TX_2 > 29

            case 29:

#endif

#if AO_CAN_FIFOS_2 > 28  &&  AO_CAN_FIFOS_TX_2 > 28

            case 28:

#endif

#if AO_CAN_FIFOS_2 > 27  &&  AO_CAN_FIFOS_TX_2 > 27

            case 27:

#endif

#if AO_CAN_FIFOS_2 > 26  &&  AO_CAN_FIFOS_TX_2 > 26

            case 26:

#endif

#if AO_CAN_FIFOS_2 > 25  &&  AO_CAN_FIFOS_TX_2 > 25

            case 25:

#endif

#if AO_CAN_FIFOS_2 > 24  &&  AO_CAN_FIFOS_TX_2 > 24

            case 24:

#endif

#if AO_CAN_FIFOS_2 > 23  &&  AO_CAN_FIFOS_TX_2 > 23

            case 23:

#endif

#if AO_CAN_FIFOS_2 > 22  &&  AO_CAN_FIFOS_TX_2 > 22

            case 22:

#endif

#if AO_CAN_FIFOS_2 > 21  &&  AO_CAN_FIFOS_TX_2 > 21

            case 21:

#endif

#if AO_CAN_FIFOS_2 > 20  &&  AO_CAN_FIFOS_TX_2 > 20

            case 20:

#endif

#if AO_CAN_FIFOS_2 > 19  &&  AO_CAN_FIFOS_TX_2 > 19

            case 19:

#endif

#if AO_CAN_FIFOS_2 > 18  &&  AO_CAN_FIFOS_TX_2 > 18

            case 18:

#endif

#if AO_CAN_FIFOS_2 > 17  &&  AO_CAN_FIFOS_TX_2 > 17

            case 17:

#endif

#if AO_CAN_FIFOS_2 > 16  &&  AO_CAN_FIFOS_TX_2 > 16

            case 16:

#endif

#if AO_CAN_FIFOS_2 > 15  &&  AO_CAN_FIFOS_TX_2 > 15

            case 15:

#endif

#if AO_CAN_FIFOS_2 > 14  &&  AO_CAN_FIFOS_TX_2 > 14

            case 14:

#endif

#if AO_CAN_FIFOS_2 > 13  &&  AO_CAN_FIFOS_TX_2 > 13

            case 13:

#endif

#if AO_CAN_FIFOS_2 > 12  &&  AO_CAN_FIFOS_TX_2 > 12

            case 12:

#endif

#if AO_CAN_FIFOS_2 > 11  &&  AO_CAN_FIFOS_TX_2 > 11

            case 11:

#endif

#if AO_CAN_FIFOS_2 > 10  &&  AO_CAN_FIFOS_TX_2 > 10

            case 10:

#endif

#if AO_CAN_FIFOS_2 >  9  &&  AO_CAN_FIFOS_TX_2 >  9

            case  9:

#endif

#if AO_CAN_FIFOS_2 >  8  &&  AO_CAN_FIFOS_TX_2 >  8

            case  8:

#endif

#if AO_CAN_FIFOS_2 >  7  &&  AO_CAN_FIFOS_TX_2 >  7

            case  7:

#endif

#if AO_CAN_FIFOS_2 >  6  &&  AO_CAN_FIFOS_TX_2 >  6

            case  6:

#endif

#if AO_CAN_FIFOS_2 >  5  &&  AO_CAN_FIFOS_TX_2 >  5

            case  5:

#endif

#if AO_CAN_FIFOS_2 >  4  &&  AO_CAN_FIFOS_TX_2 >  4

            case  4:

#endif

#if AO_CAN_FIFOS_2 >  3  &&  AO_CAN_FIFOS_TX_2 >  3

            case  3:

#endif

#if AO_CAN_FIFOS_2 >  2  &&  AO_CAN_FIFOS_TX_2 >  2

            case  2:

#endif

#if AO_CAN_FIFOS_2 >  1  &&  AO_CAN_FIFOS_TX_2 >  1

            case  1:

#endif

#if AO_CAN_FIFOS_2 >  0  &&  AO_CAN_FIFOS_TX_2 >  0

            case  0:

#endif

                // Fifo.

#if AO_CAN_TXST_2

                if
                (
                    reg->fifo[i1].intx.bits.txemptyie &&
                    reg->fifo[i1].intx.bits.txemptyif
                )
                {
                    ao_can_sent_info_2.fifo = i1;

                    ao_can_sent_info_2.fifo_tx = i1;

                    ao_can_sent_2(&ao_can_sent_info_2);

                    reg->fifo[i1].intx.bits.txemptyie = 0;
                }

                if
                (
                    reg->fifo[i1].intx.bits.txnfullie &&
                    reg->fifo[i1].intx.bits.txnfullif
                )
                {

#endif

                    ao_cond_set(ao_can_cond_not_full_2 + i1);

                    reg->fifo[i1].intx.bits.txnfullie = 0;

#if AO_CAN_TXST_2

                }

#endif

                break;

#endif

            default:

                // This really should not have happend.

                ao_assert(false);

                break;
        }
    }
    while (i1 != 0b1000000);
}

// ----------------------------------------------------------------------------

void ao_can_listen_all_2()
{
    ao_can_var_mode_2 = 7;

    ao_cond_set(&ao_can_cond_change_2);
}

void ao_can_listen_only_2()
{
    ao_can_var_mode_2 = 3;

    ao_cond_set(&ao_can_cond_change_2);
}

void ao_can_loopback_2()
{
    ao_can_var_mode_2 = 2;

    ao_cond_set(&ao_can_cond_change_2);
}

void ao_can_normal_2()
{
    ao_can_var_mode_2 = 0;

    ao_cond_set(&ao_can_cond_change_2);
}

// ----------------------------------------------------------------------------

void ao_can_start_2()
{
    ao_task_start(&ao_can_task_2);
}

void ao_can_started_2()
{
    // Variables.

#if AO_CAN_TX_2

    ao_can_t *      c1;
    ao_can_t *      c2;

    size_t          i;

    ao_can_reg_t *  reg = ao_can_reg_2();

#endif


    // Ready.

    while (ao_can_var_started_2)
    {
        // Await begin.

        ao_cond_wait_begin(     &ao_can_cond_change_wait_2);

        ao_sem_take_begin(      &ao_can_sem_take_2);

#if AO_CAN_TX_2

        for (i = 0; i < AO_CAN_FIFOS_TX_2; i++)
        {
            ao_cond_wait_begin( &ao_can_cond_not_full_wait_2[i]);

            ao_recv_obj_begin(  &ao_can_out_2               [i]);

            ao_async_all_begin( &ao_can_async_send_2        [i]);
        }

#endif


        // Await.

        ao_await_any_forever(   &ao_can_async_started_2);


        // Await end.

#if AO_CAN_TX_2

        for (i = 0; i < AO_CAN_FIFOS_TX_2; i++)
        {
            ao_async_all_end(   &ao_can_async_send_2        [i]);

            ao_recv_obj_end(    &ao_can_out_2               [i]);

            ao_cond_wait_end(   &ao_can_cond_not_full_wait_2[i]);
        }

#endif

        ao_sem_take_end(        &ao_can_sem_take_2);

        ao_cond_wait_end(       &ao_can_cond_change_wait_2);


        // Stop.

        if (ao_can_sem_take_2.result)
        {
            ao_can_var_started_2 = false;
        }


        // Change.

        else if (ao_can_cond_change_wait_2.result)
        {
            ao_cond_clear(&ao_can_cond_change_2);

            ao_can_change_2(ao_can_var_mode_2);
        }


        // Out.

#if AO_CAN_TX_2

        else
        {
            for (i = 0; i < AO_CAN_FIFOS_TX_2; i++)
            {
                if
                (
                    ao_can_cond_not_full_wait_2 [i].result &&
                    ao_can_out_2                [i].result
                )
                {
                    c2 = ao_can_out_can_2 + i;

                    c1 = (ao_can_t *) PA_TO_KVA1(reg->fifo[i].ua.reg);

                    *c1 = *c2;


                    // DS61154.

                    // Section 34.7.1.

                    // Format of Transmit Message Buffer.

                    // Unused bits should be clear.

                    // RB0 and RB1 bits must be clear.

                    c1->cmsgeid &= 0x3FFFFE0F;
                    c1->cmsgsid &= 0x000007FF;


                    // In case of an extended message format,
                    // the SRR bit should be set.

                    if (c1->ide)
                    {
                        c1->srr = 1;
                    }


                    // DS80000480.

                    // The CxFIFOCONn.FRESET bit and the CxFIFOCONn.UINC bit
                    // are not settable through a normal Special Function
                    // Register (SFR) write.

                    // Use the SET register operations to change the state of
                    // these bits.

                    reg->fifo[i].con.set = _C2FIFOCON0_UINC_MASK;


#if AO_CAN_TXST_2

                    reg->fifo[i].intx.bits.txemptyie = 1;

#endif

                    if (reg->fifo[i].con.bits.rtren == 0)
                    {
                        if (reg->fifo[i].intx.bits.txnfullif == 0)
                        {
                            ao_cond_clear(ao_can_cond_not_full_2 + i);

                            reg->fifo[i].intx.bits.txnfullie = 1;
                        }

                        reg->fifo[i].con.set = _C2FIFOCON0_TXREQ_MASK;
                    }
                }
            }
        }

#endif

    }
}

void ao_can_starting_2()
{
    // Variables.

    uint32_t mode;


    // Ready.

    ao_can_var_started_2 = true;

    ao_cond_clear(&ao_can_cond_change_2);

    mode = ao_can_var_mode_2;

    ao_assert
    (
        mode == 0 ||
        mode == 2 ||
        mode == 3 ||
        mode == 7
    );

    ao_can_change_2(mode);
}

void ao_can_stop_2()
{
    ao_sem_give(&ao_can_sem_2, 1);
}

void ao_can_stopping_2()
{
    ao_can_change_2(4);
}

// ----------------------------------------------------------------------------

void ao_can_task_proc_2(void * x)
{
    // Variables.

    size_t          i;

    ao_can_reg_t *  reg = ao_can_reg_2();

    (void)          x;


    // Ready.

    while (1)
    {
        // On.

        reg->con.bits.on = 1;

        ao_assert(reg->con.bits.opmod == 4);


        // Configuration.

        ao_can_config_2();


        // Interrupts layer 3.

#if AO_CAN_RX_2

        for (i = AO_CAN_FIFOS_TX_2; i < AO_CAN_FIFOS_TX_2 + AO_CAN_FIFOS_RX_2; i++)
        {
            reg->fifo[i].con.bits.txen = 0;

            reg->fifo[i].intx.bits.rxnemptyie = 1;

#if AO_CAN_RXOF_2

            reg->fifo[i].intx.bits.rxovflie = 1;

#endif

        }

#endif

#if AO_CAN_TX_2

        for (i = 0; i < AO_CAN_FIFOS_TX_2; i++)
        {
            reg->fifo[i].con.bits.txen = 1;

            if (reg->fifo[i].con.bits.rtren)
            {

#if AO_CAN_TXUF_2

                reg->fifo[i].intx.bits.rxovflie = 1;

#endif

                ao_cond_set(&ao_can_cond_not_full_2[i]);
            }

            else
            {
                if (reg->fifo[i].intx.bits.txnfullif == 0)
                {
                    reg->fifo[i].intx.bits.txnfullie = 1;
                }

                else
                {
                    ao_cond_set(&ao_can_cond_not_full_2[i]);
                }
            }

#if AO_CAN_TXST_2

            if (reg->fifo[i].intx.bits.txemptyif) { }

            else
            {
                reg->fifo[i].intx.bits.txemptyie = 1;
            }

#endif

        }

#endif


        // Interrupts layer 2.

        reg->intx.bits.modie = 1;
        reg->intx.bits.serrie = 1;

#if AO_CAN_BUS_2

        reg->intx.bits.cerrie = 1;

#endif

#if AO_CAN_INVALID_2

        reg->intx.bits.ivrie = 1;

#endif

#if AO_CAN_RBOV_2

        reg->intx.bits.rbovie = 1;

#endif

#if AO_CAN_RX_2

        reg->intx.bits.rbie = 1;

#endif

#if AO_CAN_TIMER_2

        reg->intx.bits.ctmrie = 1;

#endif

#if AO_CAN_TX_2

        reg->intx.bits.tbie = 1;

#endif

#if AO_CAN_WAKE_UP_2

        reg->intx.bits.wakie = 1;

#endif


        // Interrupts layer 1.

        ao_ir_can2_enable();


        // Start.

        ao_can_starting_2();

        ao_can_started_2();


        // Stop.

        ao_can_stopping_2();


        // Interrupts layer 1.

        ao_ir_can2_disable();


        // Interrupts layer 2.

        reg->intx.bits.modie = 0;
        reg->intx.bits.serrie = 0;

#if AO_CAN_BUS_2

        reg->intx.bits.cerrie = 0;

#endif

#if AO_CAN_INVALID_2

        reg->intx.bits.ivrie = 0;

#endif

#if AO_CAN_RBOV_2

        reg->intx.bits.rbovie = 0;

#endif

#if AO_CAN_RX_2

        reg->intx.bits.rbie = 0;

#endif

#if AO_CAN_TIMER_2

        reg->intx.bits.ctmrie = 0;

#endif

#if AO_CAN_TX_2

        reg->intx.bits.tbie = 0;

#endif

#if AO_CAN_WAKE_UP_2

        reg->intx.bits.wakie = 0;

#endif


        // Interrupts layer 3.

#if AO_CAN_TX_2

        for (i = 0; i < AO_CAN_FIFOS_TX_2; i++)
        {

            reg->fifo[i].intx.bits.txnfullie = 0;

#if AO_CAN_TXUF_2

            reg->fifo[i].intx.bits.rxovflie = 0;

#endif

#if AO_CAN_TXST_2

            reg->fifo[i].intx.bits.txemptyie = 0;

#endif

        }

#endif

#if AO_CAN_RX_2

        for (i = AO_CAN_FIFOS_TX_2; i < AO_CAN_FIFOS_TX_2 + AO_CAN_FIFOS_RX_2; i++)
        {
            reg->fifo[i].intx.bits.rxnemptyie = 0;

#if AO_CAN_RXOF_2

            reg->fifo[i].intx.bits.rxovflie = 0;

#endif

        }

#endif


        // Off.

        reg->con.bits.on = 0;

        while (reg->con.bits.canbusy) { }


        // Task.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_CAN_3 && AO_CAN_3

// ----------------------------------------------------------------------------

#if AO_CAN_BAUD_3 < AO_CAN_BAUD_MIN_3

#error Invalid configuration.

#endif

#if AO_CAN_BAUD_3 > AO_CAN_BAUD_MAX_3

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_3 > 0  && AO_CAN_BUFFERS_3_0  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 1  && AO_CAN_BUFFERS_3_1  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 2  && AO_CAN_BUFFERS_3_2  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 3  && AO_CAN_BUFFERS_3_3  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 4  && AO_CAN_BUFFERS_3_4  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 5  && AO_CAN_BUFFERS_3_5  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 6  && AO_CAN_BUFFERS_3_6  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 7  && AO_CAN_BUFFERS_3_7  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 8  && AO_CAN_BUFFERS_3_8  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 9  && AO_CAN_BUFFERS_3_9  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 10 && AO_CAN_BUFFERS_3_10 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 11 && AO_CAN_BUFFERS_3_11 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 12 && AO_CAN_BUFFERS_3_12 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 13 && AO_CAN_BUFFERS_3_13 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 14 && AO_CAN_BUFFERS_3_14 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 15 && AO_CAN_BUFFERS_3_15 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 16 && AO_CAN_BUFFERS_3_16 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 17 && AO_CAN_BUFFERS_3_17 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 18 && AO_CAN_BUFFERS_3_18 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 19 && AO_CAN_BUFFERS_3_19 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 20 && AO_CAN_BUFFERS_3_20 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 21 && AO_CAN_BUFFERS_3_21 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 22 && AO_CAN_BUFFERS_3_22 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 23 && AO_CAN_BUFFERS_3_23 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 24 && AO_CAN_BUFFERS_3_24 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 25 && AO_CAN_BUFFERS_3_25 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 26 && AO_CAN_BUFFERS_3_26 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 27 && AO_CAN_BUFFERS_3_27 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 28 && AO_CAN_BUFFERS_3_28 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 29 && AO_CAN_BUFFERS_3_29 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 30 && AO_CAN_BUFFERS_3_30 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 31 && AO_CAN_BUFFERS_3_31 < 1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_3 > 0  && AO_CAN_BUFFERS_3_0  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 1  && AO_CAN_BUFFERS_3_1  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 2  && AO_CAN_BUFFERS_3_2  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 3  && AO_CAN_BUFFERS_3_3  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 4  && AO_CAN_BUFFERS_3_4  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 5  && AO_CAN_BUFFERS_3_5  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 6  && AO_CAN_BUFFERS_3_6  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 7  && AO_CAN_BUFFERS_3_7  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 8  && AO_CAN_BUFFERS_3_8  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 9  && AO_CAN_BUFFERS_3_9  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 10 && AO_CAN_BUFFERS_3_10 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 11 && AO_CAN_BUFFERS_3_11 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 12 && AO_CAN_BUFFERS_3_12 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 13 && AO_CAN_BUFFERS_3_13 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 14 && AO_CAN_BUFFERS_3_14 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 15 && AO_CAN_BUFFERS_3_15 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 16 && AO_CAN_BUFFERS_3_16 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 17 && AO_CAN_BUFFERS_3_17 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 18 && AO_CAN_BUFFERS_3_18 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 19 && AO_CAN_BUFFERS_3_19 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 20 && AO_CAN_BUFFERS_3_20 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 21 && AO_CAN_BUFFERS_3_21 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 22 && AO_CAN_BUFFERS_3_22 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 23 && AO_CAN_BUFFERS_3_23 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 24 && AO_CAN_BUFFERS_3_24 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 25 && AO_CAN_BUFFERS_3_25 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 26 && AO_CAN_BUFFERS_3_26 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 27 && AO_CAN_BUFFERS_3_27 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 28 && AO_CAN_BUFFERS_3_28 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 29 && AO_CAN_BUFFERS_3_29 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 30 && AO_CAN_BUFFERS_3_30 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_3 > 31 && AO_CAN_BUFFERS_3_31 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_3 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_RX_3 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_TX_3 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_EID_3_0  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_1  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_2  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_3  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_4  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_5  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_6  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_7  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_8  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_9  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_10 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_11 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_12 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_13 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_14 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_15 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_16 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_17 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_18 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_19 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_20 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_21 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_22 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_23 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_24 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_25 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_26 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_27 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_28 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_29 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_30 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_3_31 > 0x3FFFF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_FIFO_3_0  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_1  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_2  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_3  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_4  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_5  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_6  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_7  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_8  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_9  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_10 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_11 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_12 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_13 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_14 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_15 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_16 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_17 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_18 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_19 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_20 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_21 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_22 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_23 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_24 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_25 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_26 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_27 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_28 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_29 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_30 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_3_31 > 31

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_IDE_3_0  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_1  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_2  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_3  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_4  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_5  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_6  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_7  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_8  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_9  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_10 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_11 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_12 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_13 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_14 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_15 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_16 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_17 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_18 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_19 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_20 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_21 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_22 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_23 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_24 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_25 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_26 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_27 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_28 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_29 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_30 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_3_31 > 0x1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_3_0  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_1  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_2  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_3  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_4  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_5  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_6  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_7  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_8  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_9  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_10 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_11 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_12 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_13 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_14 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_15 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_16 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_17 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_18 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_19 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_20 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_21 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_22 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_23 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_24 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_25 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_26 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_27 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_28 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_29 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_30 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_3_31 > 3

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_EID_3_0 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_3_1 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_3_2 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_3_3 > 0x3FFFF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_IDE_3_0 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_3_1 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_3_2 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_3_3 > 0x1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_SID_3_0 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_3_1 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_3_2 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_3_3 > 0x7FF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_SID_3_0  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_1  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_2  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_3  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_4  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_5  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_6  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_7  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_8  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_9  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_10 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_11 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_12 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_13 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_14 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_15 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_16 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_17 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_18 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_19 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_20 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_21 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_22 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_23 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_24 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_25 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_26 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_27 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_28 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_29 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_30 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_3_31 > 0x7FF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#define AO_CAN_RXOF_3           ((AO_CAN_RX_3)      && (AO_CAN_OVERFLOW_3))

#define AO_CAN_TXST_3           ((AO_CAN_TX_3)      && (AO_CAN_SENT_3))

#define AO_CAN_TXUF_3           ((AO_CAN_TX_3)      && (AO_CAN_UNDERFLOW_3))

// ----------------------------------------------------------------------------

#define AO_CAN_RBOV_3           ((AO_CAN_RXOF_3)    || (AO_CAN_TXUF_3))

// ----------------------------------------------------------------------------

static  void                    ao_can_change_3(    uint32_t mode);

static  void                    ao_can_started_3();

static  void                    ao_can_starting_3();

static  void                    ao_can_stopping_3();

static  void                    ao_can_task_proc_3( void * x);

// ----------------------------------------------------------------------------

        ao_can_t                ao_can_buffers_3    [AO_CAN_BUFFERS_3];

// ----------------------------------------------------------------------------

#if AO_CAN_BUS_3

static  ao_can_bus_info_t       ao_can_bus_info_3;

#endif

#if AO_CAN_INVALID_3

static  ao_can_invalid_info_t   ao_can_invalid_info_3;

#endif

#if AO_CAN_MODE_3

static  ao_can_mode_info_t      ao_can_mode_info_3;

#endif

#if AO_CAN_RXOF_3

static  ao_can_overflow_info_t  ao_can_overflow_info_3;

#endif

#if AO_CAN_SYSTEM_3

static  ao_can_system_info_t    ao_can_system_info_3;

#endif

#if AO_CAN_TIMER_3

static  ao_can_timer_info_t     ao_can_timer_info_3;

#endif

#if AO_CAN_TXST_3

static  ao_can_sent_info_t      ao_can_sent_info_3;

#endif

#if AO_CAN_TXUF_3

static  ao_can_underflow_info_t ao_can_underflow_info_3;

#endif

#if AO_CAN_WAKE_UP_3

static  ao_can_wake_up_info_t   ao_can_wake_up_info_3;

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_RX_3

// ----------------------------------------------------------------------------

static  ao_can_t                ao_can_in_can_3     [AO_CAN_FIFOS_RX_3];

        ao_send_obj_t           ao_can_in_3         [AO_CAN_FIFOS_RX_3] =
{

#if AO_CAN_FIFOS_RX_3 >  0

#if AO_CAN_FIFOS_RX_3 >  0

{
        .ptr                    = ao_can_in_can_3 +  0
},

#endif

#if AO_CAN_FIFOS_RX_3 >  1

{
        .ptr                    = ao_can_in_can_3 +  1
},

#endif

#if AO_CAN_FIFOS_RX_3 >  2

{
        .ptr                    = ao_can_in_can_3 +  2
},

#endif

#if AO_CAN_FIFOS_RX_3 >  3

{
        .ptr                    = ao_can_in_can_3 +  3
},

#endif

#if AO_CAN_FIFOS_RX_3 >  4

{
        .ptr                    = ao_can_in_can_3 +  4
},

#endif

#if AO_CAN_FIFOS_RX_3 >  5

{
        .ptr                    = ao_can_in_can_3 +  5
},

#endif

#if AO_CAN_FIFOS_RX_3 >  6

{
        .ptr                    = ao_can_in_can_3 +  6
},

#endif

#if AO_CAN_FIFOS_RX_3 >  7

{
        .ptr                    = ao_can_in_can_3 +  7
},

#endif

#if AO_CAN_FIFOS_RX_3 >  8

{
        .ptr                    = ao_can_in_can_3 +  8
},

#endif

#if AO_CAN_FIFOS_RX_3 >  9

{
        .ptr                    = ao_can_in_can_3 +  9
},

#endif

#if AO_CAN_FIFOS_RX_3 > 10

{
        .ptr                    = ao_can_in_can_3 + 10
},

#endif

#if AO_CAN_FIFOS_RX_3 > 11

{
        .ptr                    = ao_can_in_can_3 + 11
},

#endif

#if AO_CAN_FIFOS_RX_3 > 12

{
        .ptr                    = ao_can_in_can_3 + 12
},

#endif

#if AO_CAN_FIFOS_RX_3 > 13

{
        .ptr                    = ao_can_in_can_3 + 13
},

#endif

#if AO_CAN_FIFOS_RX_3 > 14

{
        .ptr                    = ao_can_in_can_3 + 14
},

#endif

#if AO_CAN_FIFOS_RX_3 > 15

{
        .ptr                    = ao_can_in_can_3 + 15
},

#endif

#if AO_CAN_FIFOS_RX_3 > 16

{
        .ptr                    = ao_can_in_can_3 + 16
},

#endif

#if AO_CAN_FIFOS_RX_3 > 17

{
        .ptr                    = ao_can_in_can_3 + 17
},

#endif

#if AO_CAN_FIFOS_RX_3 > 18

{
        .ptr                    = ao_can_in_can_3 + 18
},

#endif

#if AO_CAN_FIFOS_RX_3 > 19

{
        .ptr                    = ao_can_in_can_3 + 19
},

#endif

#if AO_CAN_FIFOS_RX_3 > 20

{
        .ptr                    = ao_can_in_can_3 + 20
},

#endif

#if AO_CAN_FIFOS_RX_3 > 21

{
        .ptr                    = ao_can_in_can_3 + 21
},

#endif

#if AO_CAN_FIFOS_RX_3 > 22

{
        .ptr                    = ao_can_in_can_3 + 22
},

#endif

#if AO_CAN_FIFOS_RX_3 > 23

{
        .ptr                    = ao_can_in_can_3 + 23
},

#endif

#if AO_CAN_FIFOS_RX_3 > 24

{
        .ptr                    = ao_can_in_can_3 + 24
},

#endif

#if AO_CAN_FIFOS_RX_3 > 25

{
        .ptr                    = ao_can_in_can_3 + 25
},

#endif

#if AO_CAN_FIFOS_RX_3 > 26

{
        .ptr                    = ao_can_in_can_3 + 26
},

#endif

#if AO_CAN_FIFOS_RX_3 > 27

{
        .ptr                    = ao_can_in_can_3 + 27
},

#endif

#if AO_CAN_FIFOS_RX_3 > 28

{
        .ptr                    = ao_can_in_can_3 + 28
},

#endif

#if AO_CAN_FIFOS_RX_3 > 29

{
        .ptr                    = ao_can_in_can_3 + 29
},

#endif

#if AO_CAN_FIFOS_RX_3 > 30

{
        .ptr                    = ao_can_in_can_3 + 30
},

#endif

#if AO_CAN_FIFOS_RX_3 > 31

{
        .ptr                    = ao_can_in_can_3 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

#endif

#if AO_CAN_TX_3

// ----------------------------------------------------------------------------

static  ao_can_t                ao_can_out_can_3    [AO_CAN_FIFOS_TX_3];

        ao_recv_obj_t           ao_can_out_3        [AO_CAN_FIFOS_TX_3] =
{

#if AO_CAN_FIFOS_TX_3 >  0

#if AO_CAN_FIFOS_TX_3 >  0

{
        .ptr                    = ao_can_out_can_3 +  0
},

#endif

#if AO_CAN_FIFOS_TX_3 >  1

{
        .ptr                    = ao_can_out_can_3 +  1
},

#endif

#if AO_CAN_FIFOS_TX_3 >  2

{
        .ptr                    = ao_can_out_can_3 +  2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  3

{
        .ptr                    = ao_can_out_can_3 +  3
},

#endif

#if AO_CAN_FIFOS_TX_3 >  4

{
        .ptr                    = ao_can_out_can_3 +  4
},

#endif

#if AO_CAN_FIFOS_TX_3 >  5

{
        .ptr                    = ao_can_out_can_3 +  5
},

#endif

#if AO_CAN_FIFOS_TX_3 >  6

{
        .ptr                    = ao_can_out_can_3 +  6
},

#endif

#if AO_CAN_FIFOS_TX_3 >  7

{
        .ptr                    = ao_can_out_can_3 +  7
},

#endif

#if AO_CAN_FIFOS_TX_3 >  8

{
        .ptr                    = ao_can_out_can_3 +  8
},

#endif

#if AO_CAN_FIFOS_TX_3 >  9

{
        .ptr                    = ao_can_out_can_3 +  9
},

#endif

#if AO_CAN_FIFOS_TX_3 > 10

{
        .ptr                    = ao_can_out_can_3 + 10
},

#endif

#if AO_CAN_FIFOS_TX_3 > 11

{
        .ptr                    = ao_can_out_can_3 + 11
},

#endif

#if AO_CAN_FIFOS_TX_3 > 12

{
        .ptr                    = ao_can_out_can_3 + 12
},

#endif

#if AO_CAN_FIFOS_TX_3 > 13

{
        .ptr                    = ao_can_out_can_3 + 13
},

#endif

#if AO_CAN_FIFOS_TX_3 > 14

{
        .ptr                    = ao_can_out_can_3 + 14
},

#endif

#if AO_CAN_FIFOS_TX_3 > 15

{
        .ptr                    = ao_can_out_can_3 + 15
},

#endif

#if AO_CAN_FIFOS_TX_3 > 16

{
        .ptr                    = ao_can_out_can_3 + 16
},

#endif

#if AO_CAN_FIFOS_TX_3 > 17

{
        .ptr                    = ao_can_out_can_3 + 17
},

#endif

#if AO_CAN_FIFOS_TX_3 > 18

{
        .ptr                    = ao_can_out_can_3 + 18
},

#endif

#if AO_CAN_FIFOS_TX_3 > 19

{
        .ptr                    = ao_can_out_can_3 + 19
},

#endif

#if AO_CAN_FIFOS_TX_3 > 20

{
        .ptr                    = ao_can_out_can_3 + 20
},

#endif

#if AO_CAN_FIFOS_TX_3 > 21

{
        .ptr                    = ao_can_out_can_3 + 21
},

#endif

#if AO_CAN_FIFOS_TX_3 > 22

{
        .ptr                    = ao_can_out_can_3 + 22
},

#endif

#if AO_CAN_FIFOS_TX_3 > 23

{
        .ptr                    = ao_can_out_can_3 + 23
},

#endif

#if AO_CAN_FIFOS_TX_3 > 24

{
        .ptr                    = ao_can_out_can_3 + 24
},

#endif

#if AO_CAN_FIFOS_TX_3 > 25

{
        .ptr                    = ao_can_out_can_3 + 25
},

#endif

#if AO_CAN_FIFOS_TX_3 > 26

{
        .ptr                    = ao_can_out_can_3 + 26
},

#endif

#if AO_CAN_FIFOS_TX_3 > 27

{
        .ptr                    = ao_can_out_can_3 + 27
},

#endif

#if AO_CAN_FIFOS_TX_3 > 28

{
        .ptr                    = ao_can_out_can_3 + 28
},

#endif

#if AO_CAN_FIFOS_TX_3 > 29

{
        .ptr                    = ao_can_out_can_3 + 29
},

#endif

#if AO_CAN_FIFOS_TX_3 > 30

{
        .ptr                    = ao_can_out_can_3 + 30
},

#endif

#if AO_CAN_FIFOS_TX_3 > 31

{
        .ptr                    = ao_can_out_can_3 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_change_3;

static  ao_cond_wait_t          ao_can_cond_change_wait_3 =
{
        .cond                   = &ao_can_cond_change_3
};

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_changed_3;

static  ao_cond_wait_t          ao_can_cond_changed_wait_3 =
{
        .cond                   = &ao_can_cond_changed_3
};

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_not_full_3      [AO_CAN_FIFOS_TX_3];

static  ao_cond_wait_t          ao_can_cond_not_full_wait_3 [AO_CAN_FIFOS_TX_3] =
{

#if AO_CAN_FIFOS_TX_3 >  0

#if AO_CAN_FIFOS_TX_3 >  0

{
        .cond                   = ao_can_cond_not_full_3 +  0
},

#endif

#if AO_CAN_FIFOS_TX_3 >  1

{
        .cond                   = ao_can_cond_not_full_3 +  1
},

#endif

#if AO_CAN_FIFOS_TX_3 >  2

{
        .cond                   = ao_can_cond_not_full_3 +  2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  3

{
        .cond                   = ao_can_cond_not_full_3 +  3
},

#endif

#if AO_CAN_FIFOS_TX_3 >  4

{
        .cond                   = ao_can_cond_not_full_3 +  4
},

#endif

#if AO_CAN_FIFOS_TX_3 >  5

{
        .cond                   = ao_can_cond_not_full_3 +  5
},

#endif

#if AO_CAN_FIFOS_TX_3 >  6

{
        .cond                   = ao_can_cond_not_full_3 +  6
},

#endif

#if AO_CAN_FIFOS_TX_3 >  7

{
        .cond                   = ao_can_cond_not_full_3 +  7
},

#endif

#if AO_CAN_FIFOS_TX_3 >  8

{
        .cond                   = ao_can_cond_not_full_3 +  8
},

#endif

#if AO_CAN_FIFOS_TX_3 >  9

{
        .cond                   = ao_can_cond_not_full_3 +  9
},

#endif

#if AO_CAN_FIFOS_TX_3 > 10

{
        .cond                   = ao_can_cond_not_full_3 + 10
},

#endif

#if AO_CAN_FIFOS_TX_3 > 11

{
        .cond                   = ao_can_cond_not_full_3 + 11
},

#endif

#if AO_CAN_FIFOS_TX_3 > 12

{
        .cond                   = ao_can_cond_not_full_3 + 12
},

#endif

#if AO_CAN_FIFOS_TX_3 > 13

{
        .cond                   = ao_can_cond_not_full_3 + 13
},

#endif

#if AO_CAN_FIFOS_TX_3 > 14

{
        .cond                   = ao_can_cond_not_full_3 + 14
},

#endif

#if AO_CAN_FIFOS_TX_3 > 15

{
        .cond                   = ao_can_cond_not_full_3 + 15
},

#endif

#if AO_CAN_FIFOS_TX_3 > 16

{
        .cond                   = ao_can_cond_not_full_3 + 16
},

#endif

#if AO_CAN_FIFOS_TX_3 > 17

{
        .cond                   = ao_can_cond_not_full_3 + 17
},

#endif

#if AO_CAN_FIFOS_TX_3 > 18

{
        .cond                   = ao_can_cond_not_full_3 + 18
},

#endif

#if AO_CAN_FIFOS_TX_3 > 19

{
        .cond                   = ao_can_cond_not_full_3 + 19
},

#endif

#if AO_CAN_FIFOS_TX_3 > 20

{
        .cond                   = ao_can_cond_not_full_3 + 20
},

#endif

#if AO_CAN_FIFOS_TX_3 > 21

{
        .cond                   = ao_can_cond_not_full_3 + 21
},

#endif

#if AO_CAN_FIFOS_TX_3 > 22

{
        .cond                   = ao_can_cond_not_full_3 + 22
},

#endif

#if AO_CAN_FIFOS_TX_3 > 23

{
        .cond                   = ao_can_cond_not_full_3 + 23
},

#endif

#if AO_CAN_FIFOS_TX_3 > 24

{
        .cond                   = ao_can_cond_not_full_3 + 24
},

#endif

#if AO_CAN_FIFOS_TX_3 > 25

{
        .cond                   = ao_can_cond_not_full_3 + 25
},

#endif

#if AO_CAN_FIFOS_TX_3 > 26

{
        .cond                   = ao_can_cond_not_full_3 + 26
},

#endif

#if AO_CAN_FIFOS_TX_3 > 27

{
        .cond                   = ao_can_cond_not_full_3 + 27
},

#endif

#if AO_CAN_FIFOS_TX_3 > 28

{
        .cond                   = ao_can_cond_not_full_3 + 28
},

#endif

#if AO_CAN_FIFOS_TX_3 > 29

{
        .cond                   = ao_can_cond_not_full_3 + 29
},

#endif

#if AO_CAN_FIFOS_TX_3 > 30

{
        .cond                   = ao_can_cond_not_full_3 + 30
},

#endif

#if AO_CAN_FIFOS_TX_3 > 31

{
        .cond                   = ao_can_cond_not_full_3 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

static  ao_sem_t                ao_can_sem_3;

static  ao_sem_take_t           ao_can_sem_take_3 =
{
        .count                  = 1,

        .sem                    = &ao_can_sem_3
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_can_task_3 =
{
        .proc                   = ao_can_task_proc_3
};

// ----------------------------------------------------------------------------

static  uint32_t    volatile    ao_can_var_mode_3 = 0;

static  bool        volatile    ao_can_var_started_3 = false;

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_change_store_3 [2] =
{
        &ao_can_cond_changed_wait_3.async,

        &ao_can_sem_take_3.async
};

static  ao_async_any_t          ao_can_async_change_3 =
{
        .store                  = ao_can_async_change_store_3,

        .count                  = 2
};

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_send_store_3   [AO_CAN_FIFOS_TX_3 * 2] =
{

#if AO_CAN_FIFOS_TX_3 >  0

#if AO_CAN_FIFOS_TX_3 >  0

        &ao_can_cond_not_full_wait_3[ 0].async,

        &ao_can_out_3               [ 0].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  1

        &ao_can_cond_not_full_wait_3[ 1].async,

        &ao_can_out_3               [ 1].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  2

        &ao_can_cond_not_full_wait_3[ 2].async,

        &ao_can_out_3               [ 2].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  3

        &ao_can_cond_not_full_wait_3[ 3].async,

        &ao_can_out_3               [ 3].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  4

        &ao_can_cond_not_full_wait_3[ 4].async,

        &ao_can_out_3               [ 4].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  5

        &ao_can_cond_not_full_wait_3[ 5].async,

        &ao_can_out_3               [ 5].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  6

        &ao_can_cond_not_full_wait_3[ 6].async,

        &ao_can_out_3               [ 6].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  7

        &ao_can_cond_not_full_wait_3[ 7].async,

        &ao_can_out_3               [ 7].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  8

        &ao_can_cond_not_full_wait_3[ 8].async,

        &ao_can_out_3               [ 8].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  9

        &ao_can_cond_not_full_wait_3[ 9].async,

        &ao_can_out_3               [ 9].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 10

        &ao_can_cond_not_full_wait_3[10].async,

        &ao_can_out_3               [10].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 11

        &ao_can_cond_not_full_wait_3[11].async,

        &ao_can_out_3               [11].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 12

        &ao_can_cond_not_full_wait_3[12].async,

        &ao_can_out_3               [12].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 13

        &ao_can_cond_not_full_wait_3[13].async,

        &ao_can_out_3               [13].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 14

        &ao_can_cond_not_full_wait_3[14].async,

        &ao_can_out_3               [14].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 15

        &ao_can_cond_not_full_wait_3[15].async,

        &ao_can_out_3               [15].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 16

        &ao_can_cond_not_full_wait_3[16].async,

        &ao_can_out_3               [16].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 17

        &ao_can_cond_not_full_wait_3[17].async,

        &ao_can_out_3               [17].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 18

        &ao_can_cond_not_full_wait_3[18].async,

        &ao_can_out_3               [18].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 19

        &ao_can_cond_not_full_wait_3[19].async,

        &ao_can_out_3               [19].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 20

        &ao_can_cond_not_full_wait_3[20].async,

        &ao_can_out_3               [20].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 21

        &ao_can_cond_not_full_wait_3[21].async,

        &ao_can_out_3               [21].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 22

        &ao_can_cond_not_full_wait_3[22].async,

        &ao_can_out_3               [22].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 23

        &ao_can_cond_not_full_wait_3[23].async,

        &ao_can_out_3               [23].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 24

        &ao_can_cond_not_full_wait_3[24].async,

        &ao_can_out_3               [24].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 25

        &ao_can_cond_not_full_wait_3[25].async,

        &ao_can_out_3               [25].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 26

        &ao_can_cond_not_full_wait_3[26].async,

        &ao_can_out_3               [26].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 27

        &ao_can_cond_not_full_wait_3[27].async,

        &ao_can_out_3               [27].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 28

        &ao_can_cond_not_full_wait_3[28].async,

        &ao_can_out_3               [28].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 29

        &ao_can_cond_not_full_wait_3[29].async,

        &ao_can_out_3               [29].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 30

        &ao_can_cond_not_full_wait_3[30].async,

        &ao_can_out_3               [30].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 31

        &ao_can_cond_not_full_wait_3[31].async,

        &ao_can_out_3               [31].async,

#endif

#endif

};

static  ao_async_all_t          ao_can_async_send_3         [AO_CAN_FIFOS_TX_3] =
{

#if AO_CAN_FIFOS_TX_3 >  0

#if AO_CAN_FIFOS_TX_3 >  0

{
        .store                  = ao_can_async_send_store_3 +  0 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  1

{
        .store                  = ao_can_async_send_store_3 +  1 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  2

{
        .store                  = ao_can_async_send_store_3 +  2 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  3

{
        .store                  = ao_can_async_send_store_3 +  3 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  4

{
        .store                  = ao_can_async_send_store_3 +  4 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  5

{
        .store                  = ao_can_async_send_store_3 +  5 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  6

{
        .store                  = ao_can_async_send_store_3 +  6 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  7

{
        .store                  = ao_can_async_send_store_3 +  7 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  8

{
        .store                  = ao_can_async_send_store_3 +  8 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 >  9

{
        .store                  = ao_can_async_send_store_3 +  9 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 10

{
        .store                  = ao_can_async_send_store_3 + 10 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 11

{
        .store                  = ao_can_async_send_store_3 + 11 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 12

{
        .store                  = ao_can_async_send_store_3 + 12 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 13

{
        .store                  = ao_can_async_send_store_3 + 13 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 14

{
        .store                  = ao_can_async_send_store_3 + 14 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 15

{
        .store                  = ao_can_async_send_store_3 + 15 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 16

{
        .store                  = ao_can_async_send_store_3 + 16 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 17

{
        .store                  = ao_can_async_send_store_3 + 17 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 18

{
        .store                  = ao_can_async_send_store_3 + 18 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 19

{
        .store                  = ao_can_async_send_store_3 + 19 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 20

{
        .store                  = ao_can_async_send_store_3 + 20 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 21

{
        .store                  = ao_can_async_send_store_3 + 21 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 22

{
        .store                  = ao_can_async_send_store_3 + 22 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 23

{
        .store                  = ao_can_async_send_store_3 + 23 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 24

{
        .store                  = ao_can_async_send_store_3 + 24 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 25

{
        .store                  = ao_can_async_send_store_3 + 25 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 26

{
        .store                  = ao_can_async_send_store_3 + 26 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 27

{
        .store                  = ao_can_async_send_store_3 + 27 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 28

{
        .store                  = ao_can_async_send_store_3 + 28 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 29

{
        .store                  = ao_can_async_send_store_3 + 29 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 30

{
        .store                  = ao_can_async_send_store_3 + 30 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_3 > 31

{
        .store                  = ao_can_async_send_store_3 + 31 * 2,

        .count                  = 2
},

#endif

#endif

};

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_started_store_3[AO_CAN_FIFOS_TX_3 + 2] =
{
        &ao_can_cond_change_wait_3.async,

        &ao_can_sem_take_3.async,

#if AO_CAN_FIFOS_TX_3 >  0

#if AO_CAN_FIFOS_TX_3 >  0

        &ao_can_async_send_3[ 0].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  1

        &ao_can_async_send_3[ 1].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  2

        &ao_can_async_send_3[ 2].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  3

        &ao_can_async_send_3[ 3].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  4

        &ao_can_async_send_3[ 4].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  5

        &ao_can_async_send_3[ 5].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  6

        &ao_can_async_send_3[ 6].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  7

        &ao_can_async_send_3[ 7].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  8

        &ao_can_async_send_3[ 8].async,

#endif

#if AO_CAN_FIFOS_TX_3 >  9

        &ao_can_async_send_3[ 9].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 10

        &ao_can_async_send_3[10].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 11

        &ao_can_async_send_3[11].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 12

        &ao_can_async_send_3[12].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 13

        &ao_can_async_send_3[13].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 14

        &ao_can_async_send_3[14].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 15

        &ao_can_async_send_3[15].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 16

        &ao_can_async_send_3[16].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 17

        &ao_can_async_send_3[17].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 18

        &ao_can_async_send_3[18].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 19

        &ao_can_async_send_3[19].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 20

        &ao_can_async_send_3[20].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 21

        &ao_can_async_send_3[21].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 22

        &ao_can_async_send_3[22].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 23

        &ao_can_async_send_3[23].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 24

        &ao_can_async_send_3[24].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 25

        &ao_can_async_send_3[25].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 26

        &ao_can_async_send_3[26].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 27

        &ao_can_async_send_3[27].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 28

        &ao_can_async_send_3[28].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 29

        &ao_can_async_send_3[29].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 30

        &ao_can_async_send_3[30].async,

#endif

#if AO_CAN_FIFOS_TX_3 > 31

        &ao_can_async_send_3[31].async,

#endif

#endif

};

static  ao_async_any_t          ao_can_async_started_3 =
{
        .store                  = ao_can_async_started_store_3,

        .count                  = 2 + AO_CAN_FIFOS_TX_3
};

// ----------------------------------------------------------------------------

void ao_can_change_3(uint32_t mode)
{
    // Assert.

    ao_assert
    (
        mode == 0 ||
        mode == 2 ||
        mode == 3 ||
        mode == 4 ||
        mode == 7
    );


    // Variables.

    ao_can_reg_t * const reg = ao_can_reg_3();


    // Ready.

    while (reg->con.bits.opmod != mode)
    {
        // Request.

        ao_cond_clear(&ao_can_cond_changed_3);

        reg->con.bits.reqop = mode;


        // Await.

        ao_cond_wait_begin( &ao_can_cond_changed_wait_3);

        ao_sem_take_begin(  &ao_can_sem_take_3);

        ao_await_any_forever
        (
            &ao_can_async_change_3
        );

        ao_sem_take_end(    &ao_can_sem_take_3);

        ao_cond_wait_end(   &ao_can_cond_changed_wait_3);


        // Stop.

        if (ao_can_sem_take_3.result)
        {
            ao_can_var_started_3 = false;
        }
    }
}

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_can_config_3()
{
    ao_can_config_baud_3();

    ao_can_config_fifos_3();

    ao_can_config_filter_masks_3();

    ao_can_config_filters_3();
}

__attribute__ ((weak))
void ao_can_config_baud_3()
{
    // Variables.

    ao_can_baud_t x;


    // Ready.

    x.f                 = AO_CAN_BAUD_3;

    x.f_pbclk           = AO_SYS_CLOCK_CAN3;

    x.sample            = AO_CAN_BAUD_SAMPLE_3;

    x.sample_thrice     = AO_CAN_BAUD_SAMPLE_THRICE_3;

    x.sjw               = AO_CAN_BAUD_SJW_3;

    x.wake_up_filter    = AO_CAN_BAUD_WAKE_UP_FILTER_3;

    ao_can_baud(&x);

    ao_assert(x.result);

    C3CFG = x.cfg;
}

__attribute__ ((weak))
void ao_can_config_fifos_3()
{
    // Fifo base address.

    C3FIFOBA = KVA_TO_PA(ao_can_buffers_3);


    // Fifos.

#if AO_CAN_FIFOS_3 > 0

#if AO_CAN_FIFOS_3 > 0

    C3FIFOCON0bits.FSIZE = AO_CAN_BUFFERS_3_0 - 1;

#endif

#if AO_CAN_FIFOS_3 > 1

    C3FIFOCON1bits.FSIZE = AO_CAN_BUFFERS_3_1 - 1;

#endif

#if AO_CAN_FIFOS_3 > 2

    C3FIFOCON2bits.FSIZE = AO_CAN_BUFFERS_3_2 - 1;

#endif

#if AO_CAN_FIFOS_3 > 3

    C3FIFOCON3bits.FSIZE = AO_CAN_BUFFERS_3_3 - 1;

#endif

#if AO_CAN_FIFOS_3 > 4

    C3FIFOCON4bits.FSIZE = AO_CAN_BUFFERS_3_4 - 1;

#endif

#if AO_CAN_FIFOS_3 > 5

    C3FIFOCON5bits.FSIZE = AO_CAN_BUFFERS_3_5 - 1;

#endif

#if AO_CAN_FIFOS_3 > 6

    C3FIFOCON6bits.FSIZE = AO_CAN_BUFFERS_3_6 - 1;

#endif

#if AO_CAN_FIFOS_3 > 7

    C3FIFOCON7bits.FSIZE = AO_CAN_BUFFERS_3_7 - 1;

#endif

#if AO_CAN_FIFOS_3 > 8

    C3FIFOCON8bits.FSIZE = AO_CAN_BUFFERS_3_8 - 1;

#endif

#if AO_CAN_FIFOS_3 > 9

    C3FIFOCON9bits.FSIZE = AO_CAN_BUFFERS_3_9 - 1;

#endif

#if AO_CAN_FIFOS_3 > 10

    C3FIFOCON10bits.FSIZE = AO_CAN_BUFFERS_3_10 - 1;

#endif

#if AO_CAN_FIFOS_3 > 11

    C3FIFOCON11bits.FSIZE = AO_CAN_BUFFERS_3_11 - 1;

#endif

#if AO_CAN_FIFOS_3 > 12

    C3FIFOCON12bits.FSIZE = AO_CAN_BUFFERS_3_12 - 1;

#endif

#if AO_CAN_FIFOS_3 > 13

    C3FIFOCON13bits.FSIZE = AO_CAN_BUFFERS_3_13 - 1;

#endif

#if AO_CAN_FIFOS_3 > 14

    C3FIFOCON14bits.FSIZE = AO_CAN_BUFFERS_3_14 - 1;

#endif

#if AO_CAN_FIFOS_3 > 15

    C3FIFOCON15bits.FSIZE = AO_CAN_BUFFERS_3_15 - 1;

#endif

#if AO_CAN_FIFOS_3 > 16

    C3FIFOCON16bits.FSIZE = AO_CAN_BUFFERS_3_16 - 1;

#endif

#if AO_CAN_FIFOS_3 > 17

    C3FIFOCON17bits.FSIZE = AO_CAN_BUFFERS_3_17 - 1;

#endif

#if AO_CAN_FIFOS_3 > 18

    C3FIFOCON18bits.FSIZE = AO_CAN_BUFFERS_3_18 - 1;

#endif

#if AO_CAN_FIFOS_3 > 19

    C3FIFOCON19bits.FSIZE = AO_CAN_BUFFERS_3_19 - 1;

#endif

#if AO_CAN_FIFOS_3 > 20

    C3FIFOCON20bits.FSIZE = AO_CAN_BUFFERS_3_20 - 1;

#endif

#if AO_CAN_FIFOS_3 > 21

    C3FIFOCON21bits.FSIZE = AO_CAN_BUFFERS_3_21 - 1;

#endif

#if AO_CAN_FIFOS_3 > 22

    C3FIFOCON22bits.FSIZE = AO_CAN_BUFFERS_3_22 - 1;

#endif

#if AO_CAN_FIFOS_3 > 23

    C3FIFOCON23bits.FSIZE = AO_CAN_BUFFERS_3_23 - 1;

#endif

#if AO_CAN_FIFOS_3 > 24

    C3FIFOCON24bits.FSIZE = AO_CAN_BUFFERS_3_24 - 1;

#endif

#if AO_CAN_FIFOS_3 > 25

    C3FIFOCON25bits.FSIZE = AO_CAN_BUFFERS_3_25 - 1;

#endif

#if AO_CAN_FIFOS_3 > 26

    C3FIFOCON26bits.FSIZE = AO_CAN_BUFFERS_3_26 - 1;

#endif

#if AO_CAN_FIFOS_3 > 27

    C3FIFOCON27bits.FSIZE = AO_CAN_BUFFERS_3_27 - 1;

#endif

#if AO_CAN_FIFOS_3 > 28

    C3FIFOCON28bits.FSIZE = AO_CAN_BUFFERS_3_28 - 1;

#endif

#if AO_CAN_FIFOS_3 > 29

    C3FIFOCON29bits.FSIZE = AO_CAN_BUFFERS_3_29 - 1;

#endif

#if AO_CAN_FIFOS_3 > 30

    C3FIFOCON30bits.FSIZE = AO_CAN_BUFFERS_3_30 - 1;

#endif

#if AO_CAN_FIFOS_3 > 31

    C3FIFOCON31bits.FSIZE = AO_CAN_BUFFERS_3_31 - 1;

#endif

#endif

}

__attribute__ ((weak))
void ao_can_config_filter_masks_3()
{
    C3RXM0bits.EID  = AO_CAN_FILTER_MASK_EID_3_0;
    C3RXM0bits.MIDE = AO_CAN_FILTER_MASK_IDE_3_0;
    C3RXM0bits.SID  = AO_CAN_FILTER_MASK_SID_3_0;

    C3RXM1bits.EID  = AO_CAN_FILTER_MASK_EID_3_1;
    C3RXM1bits.MIDE = AO_CAN_FILTER_MASK_IDE_3_1;
    C3RXM1bits.SID  = AO_CAN_FILTER_MASK_SID_3_1;

    C3RXM2bits.EID  = AO_CAN_FILTER_MASK_EID_3_2;
    C3RXM2bits.MIDE = AO_CAN_FILTER_MASK_IDE_3_2;
    C3RXM2bits.SID  = AO_CAN_FILTER_MASK_SID_3_2;

    C3RXM3bits.EID  = AO_CAN_FILTER_MASK_EID_3_3;
    C3RXM3bits.MIDE = AO_CAN_FILTER_MASK_IDE_3_3;
    C3RXM3bits.SID  = AO_CAN_FILTER_MASK_SID_3_3;
}

__attribute__ ((weak))
void ao_can_config_filters_3()
{

#if AO_CAN_FILTER_ENABLE_3_0

    C3RXF0bits.EID          = AO_CAN_FILTER_EID_3_0;
    C3RXF0bits.EXID         = AO_CAN_FILTER_IDE_3_0;
    C3RXF0bits.SID          = AO_CAN_FILTER_SID_3_0;
    C3FLTCON0bits.FSEL0     = AO_CAN_FILTER_FIFO_3_0;
    C3FLTCON0bits.MSEL0     = AO_CAN_FILTER_MASK_3_0;
    C3FLTCON0bits.FLTEN0    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_1

    C3RXF1bits.EID          = AO_CAN_FILTER_EID_3_1;
    C3RXF1bits.EXID         = AO_CAN_FILTER_IDE_3_1;
    C3RXF1bits.SID          = AO_CAN_FILTER_SID_3_1;
    C3FLTCON0bits.FSEL1     = AO_CAN_FILTER_FIFO_3_1;
    C3FLTCON0bits.MSEL1     = AO_CAN_FILTER_MASK_3_1;
    C3FLTCON0bits.FLTEN1    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_2

    C3RXF2bits.EID          = AO_CAN_FILTER_EID_3_2;
    C3RXF2bits.EXID         = AO_CAN_FILTER_IDE_3_2;
    C3RXF2bits.SID          = AO_CAN_FILTER_SID_3_2;
    C3FLTCON0bits.FSEL2     = AO_CAN_FILTER_FIFO_3_2;
    C3FLTCON0bits.MSEL2     = AO_CAN_FILTER_MASK_3_2;
    C3FLTCON0bits.FLTEN2    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_3

    C3RXF3bits.EID          = AO_CAN_FILTER_EID_3_3;
    C3RXF3bits.EXID         = AO_CAN_FILTER_IDE_3_3;
    C3RXF3bits.SID          = AO_CAN_FILTER_SID_3_3;
    C3FLTCON0bits.FSEL3     = AO_CAN_FILTER_FIFO_3_3;
    C3FLTCON0bits.MSEL3     = AO_CAN_FILTER_MASK_3_3;
    C3FLTCON0bits.FLTEN3    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_4

    C3RXF4bits.EID          = AO_CAN_FILTER_EID_3_4;
    C3RXF4bits.EXID         = AO_CAN_FILTER_IDE_3_4;
    C3RXF4bits.SID          = AO_CAN_FILTER_SID_3_4;
    C3FLTCON1bits.FSEL4     = AO_CAN_FILTER_FIFO_3_4;
    C3FLTCON1bits.MSEL4     = AO_CAN_FILTER_MASK_3_4;
    C3FLTCON1bits.FLTEN4    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_5

    C3RXF5bits.EID          = AO_CAN_FILTER_EID_3_5;
    C3RXF5bits.EXID         = AO_CAN_FILTER_IDE_3_5;
    C3RXF5bits.SID          = AO_CAN_FILTER_SID_3_5;
    C3FLTCON1bits.FSEL5     = AO_CAN_FILTER_FIFO_3_5;
    C3FLTCON1bits.MSEL5     = AO_CAN_FILTER_MASK_3_5;
    C3FLTCON1bits.FLTEN5    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_6

    C3RXF6bits.EID          = AO_CAN_FILTER_EID_3_6;
    C3RXF6bits.EXID         = AO_CAN_FILTER_IDE_3_6;
    C3RXF6bits.SID          = AO_CAN_FILTER_SID_3_6;
    C3FLTCON1bits.FSEL6     = AO_CAN_FILTER_FIFO_3_6;
    C3FLTCON1bits.MSEL6     = AO_CAN_FILTER_MASK_3_6;
    C3FLTCON1bits.FLTEN6    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_7

    C3RXF7bits.EID          = AO_CAN_FILTER_EID_3_7;
    C3RXF7bits.EXID         = AO_CAN_FILTER_IDE_3_7;
    C3RXF7bits.SID          = AO_CAN_FILTER_SID_3_7;
    C3FLTCON1bits.FSEL7     = AO_CAN_FILTER_FIFO_3_7;
    C3FLTCON1bits.MSEL7     = AO_CAN_FILTER_MASK_3_7;
    C3FLTCON1bits.FLTEN7    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_8

    C3RXF8bits.EID          = AO_CAN_FILTER_EID_3_8;
    C3RXF8bits.EXID         = AO_CAN_FILTER_IDE_3_8;
    C3RXF8bits.SID          = AO_CAN_FILTER_SID_3_8;
    C3FLTCON2bits.FSEL8     = AO_CAN_FILTER_FIFO_3_8;
    C3FLTCON2bits.MSEL8     = AO_CAN_FILTER_MASK_3_8;
    C3FLTCON2bits.FLTEN8    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_9

    C3RXF9bits.EID          = AO_CAN_FILTER_EID_3_9;
    C3RXF9bits.EXID         = AO_CAN_FILTER_IDE_3_9;
    C3RXF9bits.SID          = AO_CAN_FILTER_SID_3_9;
    C3FLTCON2bits.FSEL9     = AO_CAN_FILTER_FIFO_3_9;
    C3FLTCON2bits.MSEL9     = AO_CAN_FILTER_MASK_3_9;
    C3FLTCON2bits.FLTEN9    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_10

    C3RXF10bits.EID         = AO_CAN_FILTER_EID_3_10;
    C3RXF10bits.EXID        = AO_CAN_FILTER_IDE_3_10;
    C3RXF10bits.SID         = AO_CAN_FILTER_SID_3_10;
    C3FLTCON2bits.FSEL10    = AO_CAN_FILTER_FIFO_3_10;
    C3FLTCON2bits.MSEL10    = AO_CAN_FILTER_MASK_3_10;
    C3FLTCON2bits.FLTEN10   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_11

    C3RXF11bits.EID         = AO_CAN_FILTER_EID_3_11;
    C3RXF11bits.EXID        = AO_CAN_FILTER_IDE_3_11;
    C3RXF11bits.SID         = AO_CAN_FILTER_SID_3_11;
    C3FLTCON2bits.FSEL11    = AO_CAN_FILTER_FIFO_3_11;
    C3FLTCON2bits.MSEL11    = AO_CAN_FILTER_MASK_3_11;
    C3FLTCON2bits.FLTEN11   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_12

    C3RXF12bits.EID         = AO_CAN_FILTER_EID_3_12;
    C3RXF12bits.EXID        = AO_CAN_FILTER_IDE_3_12;
    C3RXF12bits.SID         = AO_CAN_FILTER_SID_3_12;
    C3FLTCON3bits.FSEL12    = AO_CAN_FILTER_FIFO_3_12;
    C3FLTCON3bits.MSEL12    = AO_CAN_FILTER_MASK_3_12;
    C3FLTCON3bits.FLTEN12   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_13

    C3RXF13bits.EID         = AO_CAN_FILTER_EID_3_13;
    C3RXF13bits.EXID        = AO_CAN_FILTER_IDE_3_13;
    C3RXF13bits.SID         = AO_CAN_FILTER_SID_3_13;
    C3FLTCON3bits.FSEL13    = AO_CAN_FILTER_FIFO_3_13;
    C3FLTCON3bits.MSEL13    = AO_CAN_FILTER_MASK_3_13;
    C3FLTCON3bits.FLTEN13   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_14

    C3RXF14bits.EID         = AO_CAN_FILTER_EID_3_14;
    C3RXF14bits.EXID        = AO_CAN_FILTER_IDE_3_14;
    C3RXF14bits.SID         = AO_CAN_FILTER_SID_3_14;
    C3FLTCON3bits.FSEL14    = AO_CAN_FILTER_FIFO_3_14;
    C3FLTCON3bits.MSEL14    = AO_CAN_FILTER_MASK_3_14;
    C3FLTCON3bits.FLTEN14   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_15

    C3RXF15bits.EID         = AO_CAN_FILTER_EID_3_15;
    C3RXF15bits.EXID        = AO_CAN_FILTER_IDE_3_15;
    C3RXF15bits.SID         = AO_CAN_FILTER_SID_3_15;
    C3FLTCON3bits.FSEL15    = AO_CAN_FILTER_FIFO_3_15;
    C3FLTCON3bits.MSEL15    = AO_CAN_FILTER_MASK_3_15;
    C3FLTCON3bits.FLTEN15   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_16

    C3RXF16bits.EID         = AO_CAN_FILTER_EID_3_16;
    C3RXF16bits.EXID        = AO_CAN_FILTER_IDE_3_16;
    C3RXF16bits.SID         = AO_CAN_FILTER_SID_3_16;
    C3FLTCON4bits.FSEL16    = AO_CAN_FILTER_FIFO_3_16;
    C3FLTCON4bits.MSEL16    = AO_CAN_FILTER_MASK_3_16;
    C3FLTCON4bits.FLTEN16   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_17

    C3RXF17bits.EID         = AO_CAN_FILTER_EID_3_17;
    C3RXF17bits.EXID        = AO_CAN_FILTER_IDE_3_17;
    C3RXF17bits.SID         = AO_CAN_FILTER_SID_3_17;
    C3FLTCON4bits.FSEL17    = AO_CAN_FILTER_FIFO_3_17;
    C3FLTCON4bits.MSEL17    = AO_CAN_FILTER_MASK_3_17;
    C3FLTCON4bits.FLTEN17   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_18

    C3RXF18bits.EID         = AO_CAN_FILTER_EID_3_18;
    C3RXF18bits.EXID        = AO_CAN_FILTER_IDE_3_18;
    C3RXF18bits.SID         = AO_CAN_FILTER_SID_3_18;
    C3FLTCON4bits.FSEL18    = AO_CAN_FILTER_FIFO_3_18;
    C3FLTCON4bits.MSEL18    = AO_CAN_FILTER_MASK_3_18;
    C3FLTCON4bits.FLTEN18   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_19

    C3RXF19bits.EID         = AO_CAN_FILTER_EID_3_19;
    C3RXF19bits.EXID        = AO_CAN_FILTER_IDE_3_19;
    C3RXF19bits.SID         = AO_CAN_FILTER_SID_3_19;
    C3FLTCON4bits.FSEL19    = AO_CAN_FILTER_FIFO_3_19;
    C3FLTCON4bits.MSEL19    = AO_CAN_FILTER_MASK_3_19;
    C3FLTCON4bits.FLTEN19   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_20

    C3RXF20bits.EID         = AO_CAN_FILTER_EID_3_20;
    C3RXF20bits.EXID        = AO_CAN_FILTER_IDE_3_20;
    C3RXF20bits.SID         = AO_CAN_FILTER_SID_3_20;
    C3FLTCON5bits.FSEL20    = AO_CAN_FILTER_FIFO_3_20;
    C3FLTCON5bits.MSEL20    = AO_CAN_FILTER_MASK_3_20;
    C3FLTCON5bits.FLTEN20   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_21

    C3RXF21bits.EID         = AO_CAN_FILTER_EID_3_21;
    C3RXF21bits.EXID        = AO_CAN_FILTER_IDE_3_21;
    C3RXF21bits.SID         = AO_CAN_FILTER_SID_3_21;
    C3FLTCON5bits.FSEL21    = AO_CAN_FILTER_FIFO_3_21;
    C3FLTCON5bits.MSEL21    = AO_CAN_FILTER_MASK_3_21;
    C3FLTCON5bits.FLTEN21   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_22

    C3RXF22bits.EID         = AO_CAN_FILTER_EID_3_22;
    C3RXF22bits.EXID        = AO_CAN_FILTER_IDE_3_22;
    C3RXF22bits.SID         = AO_CAN_FILTER_SID_3_22;
    C3FLTCON5bits.FSEL22    = AO_CAN_FILTER_FIFO_3_22;
    C3FLTCON5bits.MSEL22    = AO_CAN_FILTER_MASK_3_22;
    C3FLTCON5bits.FLTEN22   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_23

    C3RXF23bits.EID         = AO_CAN_FILTER_EID_3_23;
    C3RXF23bits.EXID        = AO_CAN_FILTER_IDE_3_23;
    C3RXF23bits.SID         = AO_CAN_FILTER_SID_3_23;
    C3FLTCON5bits.FSEL23    = AO_CAN_FILTER_FIFO_3_23;
    C3FLTCON5bits.MSEL23    = AO_CAN_FILTER_MASK_3_23;
    C3FLTCON5bits.FLTEN23   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_24

    C3RXF24bits.EID         = AO_CAN_FILTER_EID_3_24;
    C3RXF24bits.EXID        = AO_CAN_FILTER_IDE_3_24;
    C3RXF24bits.SID         = AO_CAN_FILTER_SID_3_24;
    C3FLTCON6bits.FSEL24    = AO_CAN_FILTER_FIFO_3_24;
    C3FLTCON6bits.MSEL24    = AO_CAN_FILTER_MASK_3_24;
    C3FLTCON6bits.FLTEN24   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_25

    C3RXF25bits.EID         = AO_CAN_FILTER_EID_3_25;
    C3RXF25bits.EXID        = AO_CAN_FILTER_IDE_3_25;
    C3RXF25bits.SID         = AO_CAN_FILTER_SID_3_25;
    C3FLTCON6bits.FSEL25    = AO_CAN_FILTER_FIFO_3_25;
    C3FLTCON6bits.MSEL25    = AO_CAN_FILTER_MASK_3_25;
    C3FLTCON6bits.FLTEN25   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_26

    C3RXF26bits.EID         = AO_CAN_FILTER_EID_3_26;
    C3RXF26bits.EXID        = AO_CAN_FILTER_IDE_3_26;
    C3RXF26bits.SID         = AO_CAN_FILTER_SID_3_26;
    C3FLTCON6bits.FSEL26    = AO_CAN_FILTER_FIFO_3_26;
    C3FLTCON6bits.MSEL26    = AO_CAN_FILTER_MASK_3_26;
    C3FLTCON6bits.FLTEN26   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_27

    C3RXF27bits.EID         = AO_CAN_FILTER_EID_3_27;
    C3RXF27bits.EXID        = AO_CAN_FILTER_IDE_3_27;
    C3RXF27bits.SID         = AO_CAN_FILTER_SID_3_27;
    C3FLTCON6bits.FSEL27    = AO_CAN_FILTER_FIFO_3_27;
    C3FLTCON6bits.MSEL27    = AO_CAN_FILTER_MASK_3_27;
    C3FLTCON6bits.FLTEN27   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_28

    C3RXF28bits.EID         = AO_CAN_FILTER_EID_3_28;
    C3RXF28bits.EXID        = AO_CAN_FILTER_IDE_3_28;
    C3RXF28bits.SID         = AO_CAN_FILTER_SID_3_28;
    C3FLTCON7bits.FSEL28    = AO_CAN_FILTER_FIFO_3_28;
    C3FLTCON7bits.MSEL28    = AO_CAN_FILTER_MASK_3_28;
    C3FLTCON7bits.FLTEN28   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_29

    C3RXF29bits.EID         = AO_CAN_FILTER_EID_3_29;
    C3RXF29bits.EXID        = AO_CAN_FILTER_IDE_3_29;
    C3RXF29bits.SID         = AO_CAN_FILTER_SID_3_29;
    C3FLTCON7bits.FSEL29    = AO_CAN_FILTER_FIFO_3_29;
    C3FLTCON7bits.MSEL29    = AO_CAN_FILTER_MASK_3_29;
    C3FLTCON7bits.FLTEN29   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_30

    C3RXF30bits.EID         = AO_CAN_FILTER_EID_3_30;
    C3RXF30bits.EXID        = AO_CAN_FILTER_IDE_3_30;
    C3RXF30bits.SID         = AO_CAN_FILTER_SID_3_30;
    C3FLTCON7bits.FSEL30    = AO_CAN_FILTER_FIFO_3_30;
    C3FLTCON7bits.MSEL30    = AO_CAN_FILTER_MASK_3_30;
    C3FLTCON7bits.FLTEN30   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_3_31

    C3RXF31bits.EID         = AO_CAN_FILTER_EID_3_31;
    C3RXF31bits.EXID        = AO_CAN_FILTER_IDE_3_31;
    C3RXF31bits.SID         = AO_CAN_FILTER_SID_3_31;
    C3FLTCON7bits.FSEL31    = AO_CAN_FILTER_FIFO_3_31;
    C3FLTCON7bits.MSEL31    = AO_CAN_FILTER_MASK_3_31;
    C3FLTCON7bits.FLTEN31   = 1;

#endif

}

// ----------------------------------------------------------------------------

void ao_can_ir_3()
{
    // Variables.

    ao_can_t *          c1;
    ao_can_t *          c2;

    ao_can_fifo_flags_t f;

    uint32_t            i1;
    uint32_t            i2;

    uint32_t            m;

    uint32_t            r;

    ao_can_reg_t *      reg = ao_can_reg_3();

    ao_time_t           t;


    // Ready.

    do
    {
        t = ao_now();

        i1 = reg->vec.bits.icode;

        ao_ir_can3_reply();

        switch (i1)
        {

#if AO_CAN_INVALID_3

            case 0b1001000:

                // Invalid message received.

                ao_can_invalid_3(&ao_can_invalid_info_3);

                reg->intx.bits.ivrif = 0;

                break;

#endif

                // Mode changed.

            case 0b1000111:

#if AO_CAN_MODE_3

                ao_can_mode_3(&ao_can_mode_info_3);

#endif

                ao_cond_set(&ao_can_cond_changed_3);

                reg->intx.bits.modif = 0;

                break;

#if AO_CAN_TIMER_3

            case 0b1000110:

                // Timer.

                ao_can_timer_3(&ao_can_timer_info_3);

                reg->intx.bits.ctmrif = 0;

                break;

#endif

            case 0b1000101:
            case 0b1000100:

                // System error.

#if AO_CAN_SYSTEM_3

                ao_can_system_info_3.flags = (ao_can_system_flags_t) i1;

                ao_can_system_3(&ao_can_system_info_3);

#endif

                reg->con.bits.on = 0;

                while (reg->con.bits.canbusy) { }

                reg->con.bits.on = 1;

                break;

#if AO_CAN_RBOV_3

            case 0b1000011:

                // Receive buffer overrun.

                r = reg->rxovf.reg;

                m = (AO_CAN_FIFOS_TX_3 == 32) ? UINT32_MAX : (1 << AO_CAN_FIFOS_TX_3) - 1;

#if AO_CAN_RXOF_3

                f = (ao_can_fifo_flags_t) (r & ~m);

                if (f != AO_CAN_FIFO_FLAGS_NONE)
                {
                    ao_can_overflow_info_3.fifos = f;

                    ao_can_overflow_info_3.fifos_rx = (ao_can_fifo_flags_t) ((uint32_t) f >> AO_CAN_FIFOS_TX_3);

                    ao_can_overflow_3(&ao_can_overflow_info_3);
                }

#endif

#if AO_CAN_TXUF_3

                f = (ao_can_fifo_flags_t) (r & m);

                if (f != AO_CAN_FIFO_FLAGS_NONE)
                {
                    ao_can_underflow_info_3.fifos = f;

                    ao_can_underflow_info_3.fifos_tx = f;

                    ao_can_underflow_3(&ao_can_underflow_info_3);
                }

#endif

                // DS61154.

                // Section 34.12.1.17.

                // Clearing all the CxFIFOINTn.RXOVFLIF bits will automatically
                // clear the CxINT.RBOVIF bit.

                while (r)
                {
                    i2 = ao_ffsu(r);

                    m = 1 << i2;

                    r = r & ~m;

                    reg->fifo[i2].intx.bits.rxovflif = 0;
                }

                // DS61154.

                // Section 34.12.1.17: The CxINT.RBOVIF bit is not directly clearable.

                // Section 34.3.4    : The CxINT.RBOVIF bit is writable.

                reg->intx.bits.rbovif = 0;

                break;

#endif

#if AO_CAN_WAKE_UP_3

            case 0b1000010:

                // Wake up.

                ao_can_wake_up_3(&ao_can_wake_up_info_3);

                reg->intx.bits.wakif = 0;

                break;

#endif

#if AO_CAN_BUS_3

            case 0b1000001:

                // CAN bus error.

                ao_can_bus_info_3.receive_error_counter = reg->trec.bits.rerrcnt;

                if (reg->trec.bits.rxbp)
                {
                    ao_can_bus_info_3.receive_error_state = AO_CAN_BUS_PASSIVE;
                }

                else if (reg->trec.bits.rxwarn)
                {
                    ao_can_bus_info_3.receive_error_state = AO_CAN_BUS_ACTIVE_WARNING;
                }

                else
                {
                    ao_can_bus_info_3.receive_error_state = AO_CAN_BUS_ACTIVE;
                }

                ao_can_bus_info_3.transmit_error_counter = reg->trec.bits.terrcnt;

                if (reg->trec.bits.txbo)
                {
                    ao_can_bus_info_3.transmit_error_state = AO_CAN_BUS_OFF;
                }

                else if (reg->trec.bits.txbp)
                {
                    ao_can_bus_info_3.transmit_error_state = AO_CAN_BUS_PASSIVE;
                }

                else if (reg->trec.bits.txwarn)
                {
                    ao_can_bus_info_3.transmit_error_state = AO_CAN_BUS_ACTIVE_WARNING;
                }

                else
                {
                    ao_can_bus_info_3.transmit_error_state = AO_CAN_BUS_ACTIVE;
                }

                ao_can_bus_3(&ao_can_bus_info_3);

                reg->intx.bits.cerrif = 0;

                break;

#endif

            case 0b1000000:

                // No interrupt.

                break;

#if AO_CAN_RX_3

#if AO_CAN_FIFOS_3 > 31  &&  AO_CAN_FIFOS_TX_3 <= 31

            case 31:

#endif

#if AO_CAN_FIFOS_3 > 30  &&  AO_CAN_FIFOS_TX_3 <= 30

            case 30:

#endif

#if AO_CAN_FIFOS_3 > 29  &&  AO_CAN_FIFOS_TX_3 <= 29

            case 29:

#endif

#if AO_CAN_FIFOS_3 > 28  &&  AO_CAN_FIFOS_TX_3 <= 28

            case 28:

#endif

#if AO_CAN_FIFOS_3 > 27  &&  AO_CAN_FIFOS_TX_3 <= 27

            case 27:

#endif

#if AO_CAN_FIFOS_3 > 26  &&  AO_CAN_FIFOS_TX_3 <= 26

            case 26:

#endif

#if AO_CAN_FIFOS_3 > 25  &&  AO_CAN_FIFOS_TX_3 <= 25

            case 25:

#endif

#if AO_CAN_FIFOS_3 > 24  &&  AO_CAN_FIFOS_TX_3 <= 24

            case 24:

#endif

#if AO_CAN_FIFOS_3 > 23  &&  AO_CAN_FIFOS_TX_3 <= 23

            case 23:

#endif

#if AO_CAN_FIFOS_3 > 22  &&  AO_CAN_FIFOS_TX_3 <= 22

            case 22:

#endif

#if AO_CAN_FIFOS_3 > 21  &&  AO_CAN_FIFOS_TX_3 <= 21

            case 21:

#endif

#if AO_CAN_FIFOS_3 > 20  &&  AO_CAN_FIFOS_TX_3 <= 20

            case 20:

#endif

#if AO_CAN_FIFOS_3 > 19  &&  AO_CAN_FIFOS_TX_3 <= 19

            case 19:

#endif

#if AO_CAN_FIFOS_3 > 18  &&  AO_CAN_FIFOS_TX_3 <= 18

            case 18:

#endif

#if AO_CAN_FIFOS_3 > 17  &&  AO_CAN_FIFOS_TX_3 <= 17

            case 17:

#endif

#if AO_CAN_FIFOS_3 > 16  &&  AO_CAN_FIFOS_TX_3 <= 16

            case 16:

#endif

#if AO_CAN_FIFOS_3 > 15  &&  AO_CAN_FIFOS_TX_3 <= 15

            case 15:

#endif

#if AO_CAN_FIFOS_3 > 14  &&  AO_CAN_FIFOS_TX_3 <= 14

            case 14:

#endif

#if AO_CAN_FIFOS_3 > 13  &&  AO_CAN_FIFOS_TX_3 <= 13

            case 13:

#endif

#if AO_CAN_FIFOS_3 > 12  &&  AO_CAN_FIFOS_TX_3 <= 12

            case 12:

#endif

#if AO_CAN_FIFOS_3 > 11  &&  AO_CAN_FIFOS_TX_3 <= 11

            case 11:

#endif

#if AO_CAN_FIFOS_3 > 10  &&  AO_CAN_FIFOS_TX_3 <= 10

            case 10:

#endif

#if AO_CAN_FIFOS_3 >  9  &&  AO_CAN_FIFOS_TX_3 <=  9

            case  9:

#endif

#if AO_CAN_FIFOS_3 >  8  &&  AO_CAN_FIFOS_TX_3 <=  8

            case  8:

#endif

#if AO_CAN_FIFOS_3 >  7  &&  AO_CAN_FIFOS_TX_3 <=  7

            case  7:

#endif

#if AO_CAN_FIFOS_3 >  6  &&  AO_CAN_FIFOS_TX_3 <=  6

            case  6:

#endif

#if AO_CAN_FIFOS_3 >  5  &&  AO_CAN_FIFOS_TX_3 <=  5

            case  5:

#endif

#if AO_CAN_FIFOS_3 >  4  &&  AO_CAN_FIFOS_TX_3 <=  4

            case  4:

#endif

#if AO_CAN_FIFOS_3 >  3  &&  AO_CAN_FIFOS_TX_3 <=  3

            case  3:

#endif

#if AO_CAN_FIFOS_3 >  2  &&  AO_CAN_FIFOS_TX_3 <=  2

            case  2:

#endif

#if AO_CAN_FIFOS_3 >  1  &&  AO_CAN_FIFOS_TX_3 <=  1

            case  1:

#endif

#if AO_CAN_FIFOS_3 >  0  &&  AO_CAN_FIFOS_TX_3 <=  0

            case  0:

#endif

                c1 = PA_TO_KVA1(reg->fifo[i1].ua.reg);

                c2 = ao_can_in_can_3 + i1 - AO_CAN_FIFOS_TX_3;

                if (reg->fifo[i1].con.bits.donly)
                {
                    c2->cmsgsid = 0;

                    c2->cmsgeid = 0;

                    c2->data = *((uint64_t *) c1);
                }

                else
                {
                    *c2 = *c1;
                }

                if (!c2->ide && c2->srr)
                {
                    c2->rtr = 1;
                }

                ao_send_obj_try(ao_can_in_3 + i1 - AO_CAN_FIFOS_TX_3);

                // DS80000480.

                // The CxFIFOCONn.FRESET bit and the CxFIFOCONn.UINC
                // bit are not settable through a normal Special
                // Function Register (SFR) write.

                // Use the SET register operations to change the state
                // of these bits.

                reg->fifo[i1].con.set = _C3FIFOCON0_UINC_MASK;

                break;

#endif

#if AO_CAN_TX_3

#if AO_CAN_FIFOS_3 > 31  &&  AO_CAN_FIFOS_TX_3 > 31

            case 31:

#endif

#if AO_CAN_FIFOS_3 > 30  &&  AO_CAN_FIFOS_TX_3 > 30

            case 30:

#endif

#if AO_CAN_FIFOS_3 > 29  &&  AO_CAN_FIFOS_TX_3 > 29

            case 29:

#endif

#if AO_CAN_FIFOS_3 > 28  &&  AO_CAN_FIFOS_TX_3 > 28

            case 28:

#endif

#if AO_CAN_FIFOS_3 > 27  &&  AO_CAN_FIFOS_TX_3 > 27

            case 27:

#endif

#if AO_CAN_FIFOS_3 > 26  &&  AO_CAN_FIFOS_TX_3 > 26

            case 26:

#endif

#if AO_CAN_FIFOS_3 > 25  &&  AO_CAN_FIFOS_TX_3 > 25

            case 25:

#endif

#if AO_CAN_FIFOS_3 > 24  &&  AO_CAN_FIFOS_TX_3 > 24

            case 24:

#endif

#if AO_CAN_FIFOS_3 > 23  &&  AO_CAN_FIFOS_TX_3 > 23

            case 23:

#endif

#if AO_CAN_FIFOS_3 > 22  &&  AO_CAN_FIFOS_TX_3 > 22

            case 22:

#endif

#if AO_CAN_FIFOS_3 > 21  &&  AO_CAN_FIFOS_TX_3 > 21

            case 21:

#endif

#if AO_CAN_FIFOS_3 > 20  &&  AO_CAN_FIFOS_TX_3 > 20

            case 20:

#endif

#if AO_CAN_FIFOS_3 > 19  &&  AO_CAN_FIFOS_TX_3 > 19

            case 19:

#endif

#if AO_CAN_FIFOS_3 > 18  &&  AO_CAN_FIFOS_TX_3 > 18

            case 18:

#endif

#if AO_CAN_FIFOS_3 > 17  &&  AO_CAN_FIFOS_TX_3 > 17

            case 17:

#endif

#if AO_CAN_FIFOS_3 > 16  &&  AO_CAN_FIFOS_TX_3 > 16

            case 16:

#endif

#if AO_CAN_FIFOS_3 > 15  &&  AO_CAN_FIFOS_TX_3 > 15

            case 15:

#endif

#if AO_CAN_FIFOS_3 > 14  &&  AO_CAN_FIFOS_TX_3 > 14

            case 14:

#endif

#if AO_CAN_FIFOS_3 > 13  &&  AO_CAN_FIFOS_TX_3 > 13

            case 13:

#endif

#if AO_CAN_FIFOS_3 > 12  &&  AO_CAN_FIFOS_TX_3 > 12

            case 12:

#endif

#if AO_CAN_FIFOS_3 > 11  &&  AO_CAN_FIFOS_TX_3 > 11

            case 11:

#endif

#if AO_CAN_FIFOS_3 > 10  &&  AO_CAN_FIFOS_TX_3 > 10

            case 10:

#endif

#if AO_CAN_FIFOS_3 >  9  &&  AO_CAN_FIFOS_TX_3 >  9

            case  9:

#endif

#if AO_CAN_FIFOS_3 >  8  &&  AO_CAN_FIFOS_TX_3 >  8

            case  8:

#endif

#if AO_CAN_FIFOS_3 >  7  &&  AO_CAN_FIFOS_TX_3 >  7

            case  7:

#endif

#if AO_CAN_FIFOS_3 >  6  &&  AO_CAN_FIFOS_TX_3 >  6

            case  6:

#endif

#if AO_CAN_FIFOS_3 >  5  &&  AO_CAN_FIFOS_TX_3 >  5

            case  5:

#endif

#if AO_CAN_FIFOS_3 >  4  &&  AO_CAN_FIFOS_TX_3 >  4

            case  4:

#endif

#if AO_CAN_FIFOS_3 >  3  &&  AO_CAN_FIFOS_TX_3 >  3

            case  3:

#endif

#if AO_CAN_FIFOS_3 >  2  &&  AO_CAN_FIFOS_TX_3 >  2

            case  2:

#endif

#if AO_CAN_FIFOS_3 >  1  &&  AO_CAN_FIFOS_TX_3 >  1

            case  1:

#endif

#if AO_CAN_FIFOS_3 >  0  &&  AO_CAN_FIFOS_TX_3 >  0

            case  0:

#endif

                // Fifo.

#if AO_CAN_TXST_3

                if
                (
                    reg->fifo[i1].intx.bits.txemptyie &&
                    reg->fifo[i1].intx.bits.txemptyif
                )
                {
                    ao_can_sent_info_3.fifo = i1;

                    ao_can_sent_info_3.fifo_tx = i1;

                    ao_can_sent_3(&ao_can_sent_info_3);

                    reg->fifo[i1].intx.bits.txemptyie = 0;
                }

                if
                (
                    reg->fifo[i1].intx.bits.txnfullie &&
                    reg->fifo[i1].intx.bits.txnfullif
                )
                {

#endif

                    ao_cond_set(ao_can_cond_not_full_3 + i1);

                    reg->fifo[i1].intx.bits.txnfullie = 0;

#if AO_CAN_TXST_3

                }

#endif

                break;

#endif

            default:

                // This really should not have happend.

                ao_assert(false);

                break;
        }
    }
    while (i1 != 0b1000000);
}

// ----------------------------------------------------------------------------

void ao_can_listen_all_3()
{
    ao_can_var_mode_3 = 7;

    ao_cond_set(&ao_can_cond_change_3);
}

void ao_can_listen_only_3()
{
    ao_can_var_mode_3 = 3;

    ao_cond_set(&ao_can_cond_change_3);
}

void ao_can_loopback_3()
{
    ao_can_var_mode_3 = 2;

    ao_cond_set(&ao_can_cond_change_3);
}

void ao_can_normal_3()
{
    ao_can_var_mode_3 = 0;

    ao_cond_set(&ao_can_cond_change_3);
}

// ----------------------------------------------------------------------------

void ao_can_start_3()
{
    ao_task_start(&ao_can_task_3);
}

void ao_can_started_3()
{
    // Variables.

#if AO_CAN_TX_3

    ao_can_t *      c1;
    ao_can_t *      c2;

    size_t          i;

    ao_can_reg_t *  reg = ao_can_reg_3();

#endif


    // Ready.

    while (ao_can_var_started_3)
    {
        // Await begin.

        ao_cond_wait_begin(     &ao_can_cond_change_wait_3);

        ao_sem_take_begin(      &ao_can_sem_take_3);

#if AO_CAN_TX_3

        for (i = 0; i < AO_CAN_FIFOS_TX_3; i++)
        {
            ao_cond_wait_begin( &ao_can_cond_not_full_wait_3[i]);

            ao_recv_obj_begin(  &ao_can_out_3               [i]);

            ao_async_all_begin( &ao_can_async_send_3        [i]);
        }

#endif


        // Await.

        ao_await_any_forever(   &ao_can_async_started_3);


        // Await end.

#if AO_CAN_TX_3

        for (i = 0; i < AO_CAN_FIFOS_TX_3; i++)
        {
            ao_async_all_end(   &ao_can_async_send_3        [i]);

            ao_recv_obj_end(    &ao_can_out_3               [i]);

            ao_cond_wait_end(   &ao_can_cond_not_full_wait_3[i]);
        }

#endif

        ao_sem_take_end(        &ao_can_sem_take_3);

        ao_cond_wait_end(       &ao_can_cond_change_wait_3);


        // Stop.

        if (ao_can_sem_take_3.result)
        {
            ao_can_var_started_3 = false;
        }


        // Change.

        else if (ao_can_cond_change_wait_3.result)
        {
            ao_cond_clear(&ao_can_cond_change_3);

            ao_can_change_3(ao_can_var_mode_3);
        }


        // Out.

#if AO_CAN_TX_3

        else
        {
            for (i = 0; i < AO_CAN_FIFOS_TX_3; i++)
            {
                if
                (
                    ao_can_cond_not_full_wait_3 [i].result &&
                    ao_can_out_3                [i].result
                )
                {
                    c2 = ao_can_out_can_3 + i;

                    c1 = (ao_can_t *) PA_TO_KVA1(reg->fifo[i].ua.reg);

                    *c1 = *c2;


                    // DS61154.

                    // Section 34.7.1.

                    // Format of Transmit Message Buffer.

                    // Unused bits should be clear.

                    // RB0 and RB1 bits must be clear.

                    c1->cmsgeid &= 0x3FFFFE0F;
                    c1->cmsgsid &= 0x000007FF;


                    // In case of an extended message format,
                    // the SRR bit should be set.

                    if (c1->ide)
                    {
                        c1->srr = 1;
                    }


                    // DS80000480.

                    // The CxFIFOCONn.FRESET bit and the CxFIFOCONn.UINC bit
                    // are not settable through a normal Special Function
                    // Register (SFR) write.

                    // Use the SET register operations to change the state of
                    // these bits.

                    reg->fifo[i].con.set = _C3FIFOCON0_UINC_MASK;


#if AO_CAN_TXST_3

                    reg->fifo[i].intx.bits.txemptyie = 1;

#endif

                    if (reg->fifo[i].con.bits.rtren == 0)
                    {
                        if (reg->fifo[i].intx.bits.txnfullif == 0)
                        {
                            ao_cond_clear(ao_can_cond_not_full_3 + i);

                            reg->fifo[i].intx.bits.txnfullie = 1;
                        }

                        reg->fifo[i].con.set = _C3FIFOCON0_TXREQ_MASK;
                    }
                }
            }
        }

#endif

    }
}

void ao_can_starting_3()
{
    // Variables.

    uint32_t mode;


    // Ready.

    ao_can_var_started_3 = true;

    ao_cond_clear(&ao_can_cond_change_3);

    mode = ao_can_var_mode_3;

    ao_assert
    (
        mode == 0 ||
        mode == 2 ||
        mode == 3 ||
        mode == 7
    );

    ao_can_change_3(mode);
}

void ao_can_stop_3()
{
    ao_sem_give(&ao_can_sem_3, 1);
}

void ao_can_stopping_3()
{
    ao_can_change_3(4);
}

// ----------------------------------------------------------------------------

void ao_can_task_proc_3(void * x)
{
    // Variables.

    size_t          i;

    ao_can_reg_t *  reg = ao_can_reg_3();

    (void)          x;


    // Ready.

    while (1)
    {
        // On.

        reg->con.bits.on = 1;

        ao_assert(reg->con.bits.opmod == 4);


        // Configuration.

        ao_can_config_3();


        // Interrupts layer 3.

#if AO_CAN_RX_3

        for (i = AO_CAN_FIFOS_TX_3; i < AO_CAN_FIFOS_TX_3 + AO_CAN_FIFOS_RX_3; i++)
        {
            reg->fifo[i].con.bits.txen = 0;

            reg->fifo[i].intx.bits.rxnemptyie = 1;

#if AO_CAN_RXOF_3

            reg->fifo[i].intx.bits.rxovflie = 1;

#endif

        }

#endif

#if AO_CAN_TX_3

        for (i = 0; i < AO_CAN_FIFOS_TX_3; i++)
        {
            reg->fifo[i].con.bits.txen = 1;

            if (reg->fifo[i].con.bits.rtren)
            {

#if AO_CAN_TXUF_3

                reg->fifo[i].intx.bits.rxovflie = 1;

#endif

                ao_cond_set(&ao_can_cond_not_full_3[i]);
            }

            else
            {
                if (reg->fifo[i].intx.bits.txnfullif == 0)
                {
                    reg->fifo[i].intx.bits.txnfullie = 1;
                }

                else
                {
                    ao_cond_set(&ao_can_cond_not_full_3[i]);
                }
            }

#if AO_CAN_TXST_3

            if (reg->fifo[i].intx.bits.txemptyif) { }

            else
            {
                reg->fifo[i].intx.bits.txemptyie = 1;
            }

#endif

        }

#endif


        // Interrupts layer 2.

        reg->intx.bits.modie = 1;
        reg->intx.bits.serrie = 1;

#if AO_CAN_BUS_3

        reg->intx.bits.cerrie = 1;

#endif

#if AO_CAN_INVALID_3

        reg->intx.bits.ivrie = 1;

#endif

#if AO_CAN_RBOV_3

        reg->intx.bits.rbovie = 1;

#endif

#if AO_CAN_RX_3

        reg->intx.bits.rbie = 1;

#endif

#if AO_CAN_TIMER_3

        reg->intx.bits.ctmrie = 1;

#endif

#if AO_CAN_TX_3

        reg->intx.bits.tbie = 1;

#endif

#if AO_CAN_WAKE_UP_3

        reg->intx.bits.wakie = 1;

#endif


        // Interrupts layer 1.

        ao_ir_can3_enable();


        // Start.

        ao_can_starting_3();

        ao_can_started_3();


        // Stop.

        ao_can_stopping_3();


        // Interrupts layer 1.

        ao_ir_can3_disable();


        // Interrupts layer 2.

        reg->intx.bits.modie = 0;
        reg->intx.bits.serrie = 0;

#if AO_CAN_BUS_3

        reg->intx.bits.cerrie = 0;

#endif

#if AO_CAN_INVALID_3

        reg->intx.bits.ivrie = 0;

#endif

#if AO_CAN_RBOV_3

        reg->intx.bits.rbovie = 0;

#endif

#if AO_CAN_RX_3

        reg->intx.bits.rbie = 0;

#endif

#if AO_CAN_TIMER_3

        reg->intx.bits.ctmrie = 0;

#endif

#if AO_CAN_TX_3

        reg->intx.bits.tbie = 0;

#endif

#if AO_CAN_WAKE_UP_3

        reg->intx.bits.wakie = 0;

#endif


        // Interrupts layer 3.

#if AO_CAN_TX_3

        for (i = 0; i < AO_CAN_FIFOS_TX_3; i++)
        {

            reg->fifo[i].intx.bits.txnfullie = 0;

#if AO_CAN_TXUF_3

            reg->fifo[i].intx.bits.rxovflie = 0;

#endif

#if AO_CAN_TXST_3

            reg->fifo[i].intx.bits.txemptyie = 0;

#endif

        }

#endif

#if AO_CAN_RX_3

        for (i = AO_CAN_FIFOS_TX_3; i < AO_CAN_FIFOS_TX_3 + AO_CAN_FIFOS_RX_3; i++)
        {
            reg->fifo[i].intx.bits.rxnemptyie = 0;

#if AO_CAN_RXOF_3

            reg->fifo[i].intx.bits.rxovflie = 0;

#endif

        }

#endif


        // Off.

        reg->con.bits.on = 0;

        while (reg->con.bits.canbusy) { }


        // Task.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_CAN_4 && AO_CAN_4

// ----------------------------------------------------------------------------

#if AO_CAN_BAUD_4 < AO_CAN_BAUD_MIN_4

#error Invalid configuration.

#endif

#if AO_CAN_BAUD_4 > AO_CAN_BAUD_MAX_4

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_4 > 0  && AO_CAN_BUFFERS_4_0  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 1  && AO_CAN_BUFFERS_4_1  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 2  && AO_CAN_BUFFERS_4_2  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 3  && AO_CAN_BUFFERS_4_3  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 4  && AO_CAN_BUFFERS_4_4  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 5  && AO_CAN_BUFFERS_4_5  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 6  && AO_CAN_BUFFERS_4_6  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 7  && AO_CAN_BUFFERS_4_7  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 8  && AO_CAN_BUFFERS_4_8  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 9  && AO_CAN_BUFFERS_4_9  < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 10 && AO_CAN_BUFFERS_4_10 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 11 && AO_CAN_BUFFERS_4_11 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 12 && AO_CAN_BUFFERS_4_12 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 13 && AO_CAN_BUFFERS_4_13 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 14 && AO_CAN_BUFFERS_4_14 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 15 && AO_CAN_BUFFERS_4_15 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 16 && AO_CAN_BUFFERS_4_16 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 17 && AO_CAN_BUFFERS_4_17 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 18 && AO_CAN_BUFFERS_4_18 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 19 && AO_CAN_BUFFERS_4_19 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 20 && AO_CAN_BUFFERS_4_20 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 21 && AO_CAN_BUFFERS_4_21 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 22 && AO_CAN_BUFFERS_4_22 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 23 && AO_CAN_BUFFERS_4_23 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 24 && AO_CAN_BUFFERS_4_24 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 25 && AO_CAN_BUFFERS_4_25 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 26 && AO_CAN_BUFFERS_4_26 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 27 && AO_CAN_BUFFERS_4_27 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 28 && AO_CAN_BUFFERS_4_28 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 29 && AO_CAN_BUFFERS_4_29 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 30 && AO_CAN_BUFFERS_4_30 < 1

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 31 && AO_CAN_BUFFERS_4_31 < 1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_4 > 0  && AO_CAN_BUFFERS_4_0  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 1  && AO_CAN_BUFFERS_4_1  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 2  && AO_CAN_BUFFERS_4_2  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 3  && AO_CAN_BUFFERS_4_3  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 4  && AO_CAN_BUFFERS_4_4  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 5  && AO_CAN_BUFFERS_4_5  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 6  && AO_CAN_BUFFERS_4_6  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 7  && AO_CAN_BUFFERS_4_7  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 8  && AO_CAN_BUFFERS_4_8  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 9  && AO_CAN_BUFFERS_4_9  > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 10 && AO_CAN_BUFFERS_4_10 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 11 && AO_CAN_BUFFERS_4_11 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 12 && AO_CAN_BUFFERS_4_12 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 13 && AO_CAN_BUFFERS_4_13 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 14 && AO_CAN_BUFFERS_4_14 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 15 && AO_CAN_BUFFERS_4_15 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 16 && AO_CAN_BUFFERS_4_16 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 17 && AO_CAN_BUFFERS_4_17 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 18 && AO_CAN_BUFFERS_4_18 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 19 && AO_CAN_BUFFERS_4_19 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 20 && AO_CAN_BUFFERS_4_20 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 21 && AO_CAN_BUFFERS_4_21 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 22 && AO_CAN_BUFFERS_4_22 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 23 && AO_CAN_BUFFERS_4_23 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 24 && AO_CAN_BUFFERS_4_24 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 25 && AO_CAN_BUFFERS_4_25 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 26 && AO_CAN_BUFFERS_4_26 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 27 && AO_CAN_BUFFERS_4_27 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 28 && AO_CAN_BUFFERS_4_28 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 29 && AO_CAN_BUFFERS_4_29 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 30 && AO_CAN_BUFFERS_4_30 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_4 > 31 && AO_CAN_BUFFERS_4_31 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_4 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FIFOS_RX_4 > 32

#error Invalid configuration.

#endif

#if AO_CAN_FIFOS_TX_4 > 32

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_EID_4_0  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_1  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_2  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_3  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_4  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_5  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_6  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_7  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_8  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_9  > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_10 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_11 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_12 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_13 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_14 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_15 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_16 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_17 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_18 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_19 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_20 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_21 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_22 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_23 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_24 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_25 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_26 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_27 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_28 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_29 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_30 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_EID_4_31 > 0x3FFFF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_FIFO_4_0  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_1  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_2  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_3  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_4  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_5  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_6  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_7  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_8  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_9  > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_10 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_11 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_12 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_13 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_14 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_15 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_16 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_17 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_18 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_19 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_20 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_21 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_22 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_23 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_24 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_25 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_26 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_27 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_28 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_29 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_30 > 31

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_FIFO_4_31 > 31

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_IDE_4_0  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_1  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_2  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_3  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_4  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_5  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_6  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_7  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_8  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_9  > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_10 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_11 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_12 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_13 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_14 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_15 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_16 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_17 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_18 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_19 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_20 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_21 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_22 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_23 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_24 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_25 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_26 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_27 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_28 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_29 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_30 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_IDE_4_31 > 0x1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_4_0  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_1  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_2  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_3  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_4  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_5  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_6  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_7  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_8  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_9  > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_10 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_11 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_12 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_13 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_14 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_15 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_16 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_17 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_18 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_19 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_20 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_21 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_22 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_23 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_24 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_25 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_26 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_27 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_28 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_29 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_30 > 3

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_4_31 > 3

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_EID_4_0 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_4_1 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_4_2 > 0x3FFFF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_EID_4_3 > 0x3FFFF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_IDE_4_0 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_4_1 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_4_2 > 0x1

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_IDE_4_3 > 0x1

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_MASK_SID_4_0 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_4_1 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_4_2 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_MASK_SID_4_3 > 0x7FF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_FILTER_SID_4_0  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_1  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_2  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_3  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_4  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_5  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_6  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_7  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_8  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_9  > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_10 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_11 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_12 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_13 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_14 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_15 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_16 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_17 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_18 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_19 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_20 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_21 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_22 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_23 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_24 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_25 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_26 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_27 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_28 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_29 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_30 > 0x7FF

#error Invalid configuration.

#endif

#if AO_CAN_FILTER_SID_4_31 > 0x7FF

#error Invalid configuration.

#endif

// ----------------------------------------------------------------------------

#define AO_CAN_RXOF_4           ((AO_CAN_RX_4)      && (AO_CAN_OVERFLOW_4))

#define AO_CAN_TXST_4           ((AO_CAN_TX_4)      && (AO_CAN_SENT_4))

#define AO_CAN_TXUF_4           ((AO_CAN_TX_4)      && (AO_CAN_UNDERFLOW_4))

// ----------------------------------------------------------------------------

#define AO_CAN_RBOV_4           ((AO_CAN_RXOF_4)    || (AO_CAN_TXUF_4))

// ----------------------------------------------------------------------------

static  void                    ao_can_change_4(    uint32_t mode);

static  void                    ao_can_started_4();

static  void                    ao_can_starting_4();

static  void                    ao_can_stopping_4();

static  void                    ao_can_task_proc_4( void * x);

// ----------------------------------------------------------------------------

        ao_can_t                ao_can_buffers_4    [AO_CAN_BUFFERS_4];

// ----------------------------------------------------------------------------

#if AO_CAN_BUS_4

static  ao_can_bus_info_t       ao_can_bus_info_4;

#endif

#if AO_CAN_INVALID_4

static  ao_can_invalid_info_t   ao_can_invalid_info_4;

#endif

#if AO_CAN_MODE_4

static  ao_can_mode_info_t      ao_can_mode_info_4;

#endif

#if AO_CAN_RXOF_4

static  ao_can_overflow_info_t  ao_can_overflow_info_4;

#endif

#if AO_CAN_SYSTEM_4

static  ao_can_system_info_t    ao_can_system_info_4;

#endif

#if AO_CAN_TIMER_4

static  ao_can_timer_info_t     ao_can_timer_info_4;

#endif

#if AO_CAN_TXST_4

static  ao_can_sent_info_t      ao_can_sent_info_4;

#endif

#if AO_CAN_TXUF_4

static  ao_can_underflow_info_t ao_can_underflow_info_4;

#endif

#if AO_CAN_WAKE_UP_4

static  ao_can_wake_up_info_t   ao_can_wake_up_info_4;

#endif

// ----------------------------------------------------------------------------

#if AO_CAN_RX_4

// ----------------------------------------------------------------------------

static  ao_can_t                ao_can_in_can_4     [AO_CAN_FIFOS_RX_4];

        ao_send_obj_t           ao_can_in_4         [AO_CAN_FIFOS_RX_4] =
{

#if AO_CAN_FIFOS_RX_4 >  0

#if AO_CAN_FIFOS_RX_4 >  0

{
        .ptr                    = ao_can_in_can_4 +  0
},

#endif

#if AO_CAN_FIFOS_RX_4 >  1

{
        .ptr                    = ao_can_in_can_4 +  1
},

#endif

#if AO_CAN_FIFOS_RX_4 >  2

{
        .ptr                    = ao_can_in_can_4 +  2
},

#endif

#if AO_CAN_FIFOS_RX_4 >  3

{
        .ptr                    = ao_can_in_can_4 +  3
},

#endif

#if AO_CAN_FIFOS_RX_4 >  4

{
        .ptr                    = ao_can_in_can_4 +  4
},

#endif

#if AO_CAN_FIFOS_RX_4 >  5

{
        .ptr                    = ao_can_in_can_4 +  5
},

#endif

#if AO_CAN_FIFOS_RX_4 >  6

{
        .ptr                    = ao_can_in_can_4 +  6
},

#endif

#if AO_CAN_FIFOS_RX_4 >  7

{
        .ptr                    = ao_can_in_can_4 +  7
},

#endif

#if AO_CAN_FIFOS_RX_4 >  8

{
        .ptr                    = ao_can_in_can_4 +  8
},

#endif

#if AO_CAN_FIFOS_RX_4 >  9

{
        .ptr                    = ao_can_in_can_4 +  9
},

#endif

#if AO_CAN_FIFOS_RX_4 > 10

{
        .ptr                    = ao_can_in_can_4 + 10
},

#endif

#if AO_CAN_FIFOS_RX_4 > 11

{
        .ptr                    = ao_can_in_can_4 + 11
},

#endif

#if AO_CAN_FIFOS_RX_4 > 12

{
        .ptr                    = ao_can_in_can_4 + 12
},

#endif

#if AO_CAN_FIFOS_RX_4 > 13

{
        .ptr                    = ao_can_in_can_4 + 13
},

#endif

#if AO_CAN_FIFOS_RX_4 > 14

{
        .ptr                    = ao_can_in_can_4 + 14
},

#endif

#if AO_CAN_FIFOS_RX_4 > 15

{
        .ptr                    = ao_can_in_can_4 + 15
},

#endif

#if AO_CAN_FIFOS_RX_4 > 16

{
        .ptr                    = ao_can_in_can_4 + 16
},

#endif

#if AO_CAN_FIFOS_RX_4 > 17

{
        .ptr                    = ao_can_in_can_4 + 17
},

#endif

#if AO_CAN_FIFOS_RX_4 > 18

{
        .ptr                    = ao_can_in_can_4 + 18
},

#endif

#if AO_CAN_FIFOS_RX_4 > 19

{
        .ptr                    = ao_can_in_can_4 + 19
},

#endif

#if AO_CAN_FIFOS_RX_4 > 20

{
        .ptr                    = ao_can_in_can_4 + 20
},

#endif

#if AO_CAN_FIFOS_RX_4 > 21

{
        .ptr                    = ao_can_in_can_4 + 21
},

#endif

#if AO_CAN_FIFOS_RX_4 > 22

{
        .ptr                    = ao_can_in_can_4 + 22
},

#endif

#if AO_CAN_FIFOS_RX_4 > 23

{
        .ptr                    = ao_can_in_can_4 + 23
},

#endif

#if AO_CAN_FIFOS_RX_4 > 24

{
        .ptr                    = ao_can_in_can_4 + 24
},

#endif

#if AO_CAN_FIFOS_RX_4 > 25

{
        .ptr                    = ao_can_in_can_4 + 25
},

#endif

#if AO_CAN_FIFOS_RX_4 > 26

{
        .ptr                    = ao_can_in_can_4 + 26
},

#endif

#if AO_CAN_FIFOS_RX_4 > 27

{
        .ptr                    = ao_can_in_can_4 + 27
},

#endif

#if AO_CAN_FIFOS_RX_4 > 28

{
        .ptr                    = ao_can_in_can_4 + 28
},

#endif

#if AO_CAN_FIFOS_RX_4 > 29

{
        .ptr                    = ao_can_in_can_4 + 29
},

#endif

#if AO_CAN_FIFOS_RX_4 > 30

{
        .ptr                    = ao_can_in_can_4 + 30
},

#endif

#if AO_CAN_FIFOS_RX_4 > 31

{
        .ptr                    = ao_can_in_can_4 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

#endif

#if AO_CAN_TX_4

// ----------------------------------------------------------------------------

static  ao_can_t                ao_can_out_can_4    [AO_CAN_FIFOS_TX_4];

        ao_recv_obj_t           ao_can_out_4        [AO_CAN_FIFOS_TX_4] =
{

#if AO_CAN_FIFOS_TX_4 >  0

#if AO_CAN_FIFOS_TX_4 >  0

{
        .ptr                    = ao_can_out_can_4 +  0
},

#endif

#if AO_CAN_FIFOS_TX_4 >  1

{
        .ptr                    = ao_can_out_can_4 +  1
},

#endif

#if AO_CAN_FIFOS_TX_4 >  2

{
        .ptr                    = ao_can_out_can_4 +  2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  3

{
        .ptr                    = ao_can_out_can_4 +  3
},

#endif

#if AO_CAN_FIFOS_TX_4 >  4

{
        .ptr                    = ao_can_out_can_4 +  4
},

#endif

#if AO_CAN_FIFOS_TX_4 >  5

{
        .ptr                    = ao_can_out_can_4 +  5
},

#endif

#if AO_CAN_FIFOS_TX_4 >  6

{
        .ptr                    = ao_can_out_can_4 +  6
},

#endif

#if AO_CAN_FIFOS_TX_4 >  7

{
        .ptr                    = ao_can_out_can_4 +  7
},

#endif

#if AO_CAN_FIFOS_TX_4 >  8

{
        .ptr                    = ao_can_out_can_4 +  8
},

#endif

#if AO_CAN_FIFOS_TX_4 >  9

{
        .ptr                    = ao_can_out_can_4 +  9
},

#endif

#if AO_CAN_FIFOS_TX_4 > 10

{
        .ptr                    = ao_can_out_can_4 + 10
},

#endif

#if AO_CAN_FIFOS_TX_4 > 11

{
        .ptr                    = ao_can_out_can_4 + 11
},

#endif

#if AO_CAN_FIFOS_TX_4 > 12

{
        .ptr                    = ao_can_out_can_4 + 12
},

#endif

#if AO_CAN_FIFOS_TX_4 > 13

{
        .ptr                    = ao_can_out_can_4 + 13
},

#endif

#if AO_CAN_FIFOS_TX_4 > 14

{
        .ptr                    = ao_can_out_can_4 + 14
},

#endif

#if AO_CAN_FIFOS_TX_4 > 15

{
        .ptr                    = ao_can_out_can_4 + 15
},

#endif

#if AO_CAN_FIFOS_TX_4 > 16

{
        .ptr                    = ao_can_out_can_4 + 16
},

#endif

#if AO_CAN_FIFOS_TX_4 > 17

{
        .ptr                    = ao_can_out_can_4 + 17
},

#endif

#if AO_CAN_FIFOS_TX_4 > 18

{
        .ptr                    = ao_can_out_can_4 + 18
},

#endif

#if AO_CAN_FIFOS_TX_4 > 19

{
        .ptr                    = ao_can_out_can_4 + 19
},

#endif

#if AO_CAN_FIFOS_TX_4 > 20

{
        .ptr                    = ao_can_out_can_4 + 20
},

#endif

#if AO_CAN_FIFOS_TX_4 > 21

{
        .ptr                    = ao_can_out_can_4 + 21
},

#endif

#if AO_CAN_FIFOS_TX_4 > 22

{
        .ptr                    = ao_can_out_can_4 + 22
},

#endif

#if AO_CAN_FIFOS_TX_4 > 23

{
        .ptr                    = ao_can_out_can_4 + 23
},

#endif

#if AO_CAN_FIFOS_TX_4 > 24

{
        .ptr                    = ao_can_out_can_4 + 24
},

#endif

#if AO_CAN_FIFOS_TX_4 > 25

{
        .ptr                    = ao_can_out_can_4 + 25
},

#endif

#if AO_CAN_FIFOS_TX_4 > 26

{
        .ptr                    = ao_can_out_can_4 + 26
},

#endif

#if AO_CAN_FIFOS_TX_4 > 27

{
        .ptr                    = ao_can_out_can_4 + 27
},

#endif

#if AO_CAN_FIFOS_TX_4 > 28

{
        .ptr                    = ao_can_out_can_4 + 28
},

#endif

#if AO_CAN_FIFOS_TX_4 > 29

{
        .ptr                    = ao_can_out_can_4 + 29
},

#endif

#if AO_CAN_FIFOS_TX_4 > 30

{
        .ptr                    = ao_can_out_can_4 + 30
},

#endif

#if AO_CAN_FIFOS_TX_4 > 31

{
        .ptr                    = ao_can_out_can_4 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_change_4;

static  ao_cond_wait_t          ao_can_cond_change_wait_4 =
{
        .cond                   = &ao_can_cond_change_4
};

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_changed_4;

static  ao_cond_wait_t          ao_can_cond_changed_wait_4 =
{
        .cond                   = &ao_can_cond_changed_4
};

// ----------------------------------------------------------------------------

static  ao_cond_t               ao_can_cond_not_full_4      [AO_CAN_FIFOS_TX_4];

static  ao_cond_wait_t          ao_can_cond_not_full_wait_4 [AO_CAN_FIFOS_TX_4] =
{

#if AO_CAN_FIFOS_TX_4 >  0

#if AO_CAN_FIFOS_TX_4 >  0

{
        .cond                   = ao_can_cond_not_full_4 +  0
},

#endif

#if AO_CAN_FIFOS_TX_4 >  1

{
        .cond                   = ao_can_cond_not_full_4 +  1
},

#endif

#if AO_CAN_FIFOS_TX_4 >  2

{
        .cond                   = ao_can_cond_not_full_4 +  2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  3

{
        .cond                   = ao_can_cond_not_full_4 +  3
},

#endif

#if AO_CAN_FIFOS_TX_4 >  4

{
        .cond                   = ao_can_cond_not_full_4 +  4
},

#endif

#if AO_CAN_FIFOS_TX_4 >  5

{
        .cond                   = ao_can_cond_not_full_4 +  5
},

#endif

#if AO_CAN_FIFOS_TX_4 >  6

{
        .cond                   = ao_can_cond_not_full_4 +  6
},

#endif

#if AO_CAN_FIFOS_TX_4 >  7

{
        .cond                   = ao_can_cond_not_full_4 +  7
},

#endif

#if AO_CAN_FIFOS_TX_4 >  8

{
        .cond                   = ao_can_cond_not_full_4 +  8
},

#endif

#if AO_CAN_FIFOS_TX_4 >  9

{
        .cond                   = ao_can_cond_not_full_4 +  9
},

#endif

#if AO_CAN_FIFOS_TX_4 > 10

{
        .cond                   = ao_can_cond_not_full_4 + 10
},

#endif

#if AO_CAN_FIFOS_TX_4 > 11

{
        .cond                   = ao_can_cond_not_full_4 + 11
},

#endif

#if AO_CAN_FIFOS_TX_4 > 12

{
        .cond                   = ao_can_cond_not_full_4 + 12
},

#endif

#if AO_CAN_FIFOS_TX_4 > 13

{
        .cond                   = ao_can_cond_not_full_4 + 13
},

#endif

#if AO_CAN_FIFOS_TX_4 > 14

{
        .cond                   = ao_can_cond_not_full_4 + 14
},

#endif

#if AO_CAN_FIFOS_TX_4 > 15

{
        .cond                   = ao_can_cond_not_full_4 + 15
},

#endif

#if AO_CAN_FIFOS_TX_4 > 16

{
        .cond                   = ao_can_cond_not_full_4 + 16
},

#endif

#if AO_CAN_FIFOS_TX_4 > 17

{
        .cond                   = ao_can_cond_not_full_4 + 17
},

#endif

#if AO_CAN_FIFOS_TX_4 > 18

{
        .cond                   = ao_can_cond_not_full_4 + 18
},

#endif

#if AO_CAN_FIFOS_TX_4 > 19

{
        .cond                   = ao_can_cond_not_full_4 + 19
},

#endif

#if AO_CAN_FIFOS_TX_4 > 20

{
        .cond                   = ao_can_cond_not_full_4 + 20
},

#endif

#if AO_CAN_FIFOS_TX_4 > 21

{
        .cond                   = ao_can_cond_not_full_4 + 21
},

#endif

#if AO_CAN_FIFOS_TX_4 > 22

{
        .cond                   = ao_can_cond_not_full_4 + 22
},

#endif

#if AO_CAN_FIFOS_TX_4 > 23

{
        .cond                   = ao_can_cond_not_full_4 + 23
},

#endif

#if AO_CAN_FIFOS_TX_4 > 24

{
        .cond                   = ao_can_cond_not_full_4 + 24
},

#endif

#if AO_CAN_FIFOS_TX_4 > 25

{
        .cond                   = ao_can_cond_not_full_4 + 25
},

#endif

#if AO_CAN_FIFOS_TX_4 > 26

{
        .cond                   = ao_can_cond_not_full_4 + 26
},

#endif

#if AO_CAN_FIFOS_TX_4 > 27

{
        .cond                   = ao_can_cond_not_full_4 + 27
},

#endif

#if AO_CAN_FIFOS_TX_4 > 28

{
        .cond                   = ao_can_cond_not_full_4 + 28
},

#endif

#if AO_CAN_FIFOS_TX_4 > 29

{
        .cond                   = ao_can_cond_not_full_4 + 29
},

#endif

#if AO_CAN_FIFOS_TX_4 > 30

{
        .cond                   = ao_can_cond_not_full_4 + 30
},

#endif

#if AO_CAN_FIFOS_TX_4 > 31

{
        .cond                   = ao_can_cond_not_full_4 + 31
},

#endif

#endif

};

// ----------------------------------------------------------------------------

static  ao_sem_t                ao_can_sem_4;

static  ao_sem_take_t           ao_can_sem_take_4 =
{
        .count                  = 1,

        .sem                    = &ao_can_sem_4
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_can_task_4 =
{
        .proc                   = ao_can_task_proc_4
};

// ----------------------------------------------------------------------------

static  uint32_t    volatile    ao_can_var_mode_4 = 0;

static  bool        volatile    ao_can_var_started_4 = false;

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_change_store_4 [2] =
{
        &ao_can_cond_changed_wait_4.async,

        &ao_can_sem_take_4.async
};

static  ao_async_any_t          ao_can_async_change_4 =
{
        .store                  = ao_can_async_change_store_4,

        .count                  = 2
};

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_send_store_4   [AO_CAN_FIFOS_TX_4 * 2] =
{

#if AO_CAN_FIFOS_TX_4 >  0

#if AO_CAN_FIFOS_TX_4 >  0

        &ao_can_cond_not_full_wait_4[ 0].async,

        &ao_can_out_4               [ 0].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  1

        &ao_can_cond_not_full_wait_4[ 1].async,

        &ao_can_out_4               [ 1].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  2

        &ao_can_cond_not_full_wait_4[ 2].async,

        &ao_can_out_4               [ 2].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  3

        &ao_can_cond_not_full_wait_4[ 3].async,

        &ao_can_out_4               [ 3].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  4

        &ao_can_cond_not_full_wait_4[ 4].async,

        &ao_can_out_4               [ 4].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  5

        &ao_can_cond_not_full_wait_4[ 5].async,

        &ao_can_out_4               [ 5].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  6

        &ao_can_cond_not_full_wait_4[ 6].async,

        &ao_can_out_4               [ 6].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  7

        &ao_can_cond_not_full_wait_4[ 7].async,

        &ao_can_out_4               [ 7].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  8

        &ao_can_cond_not_full_wait_4[ 8].async,

        &ao_can_out_4               [ 8].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  9

        &ao_can_cond_not_full_wait_4[ 9].async,

        &ao_can_out_4               [ 9].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 10

        &ao_can_cond_not_full_wait_4[10].async,

        &ao_can_out_4               [10].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 11

        &ao_can_cond_not_full_wait_4[11].async,

        &ao_can_out_4               [11].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 12

        &ao_can_cond_not_full_wait_4[12].async,

        &ao_can_out_4               [12].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 13

        &ao_can_cond_not_full_wait_4[13].async,

        &ao_can_out_4               [13].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 14

        &ao_can_cond_not_full_wait_4[14].async,

        &ao_can_out_4               [14].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 15

        &ao_can_cond_not_full_wait_4[15].async,

        &ao_can_out_4               [15].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 16

        &ao_can_cond_not_full_wait_4[16].async,

        &ao_can_out_4               [16].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 17

        &ao_can_cond_not_full_wait_4[17].async,

        &ao_can_out_4               [17].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 18

        &ao_can_cond_not_full_wait_4[18].async,

        &ao_can_out_4               [18].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 19

        &ao_can_cond_not_full_wait_4[19].async,

        &ao_can_out_4               [19].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 20

        &ao_can_cond_not_full_wait_4[20].async,

        &ao_can_out_4               [20].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 21

        &ao_can_cond_not_full_wait_4[21].async,

        &ao_can_out_4               [21].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 22

        &ao_can_cond_not_full_wait_4[22].async,

        &ao_can_out_4               [22].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 23

        &ao_can_cond_not_full_wait_4[23].async,

        &ao_can_out_4               [23].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 24

        &ao_can_cond_not_full_wait_4[24].async,

        &ao_can_out_4               [24].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 25

        &ao_can_cond_not_full_wait_4[25].async,

        &ao_can_out_4               [25].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 26

        &ao_can_cond_not_full_wait_4[26].async,

        &ao_can_out_4               [26].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 27

        &ao_can_cond_not_full_wait_4[27].async,

        &ao_can_out_4               [27].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 28

        &ao_can_cond_not_full_wait_4[28].async,

        &ao_can_out_4               [28].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 29

        &ao_can_cond_not_full_wait_4[29].async,

        &ao_can_out_4               [29].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 30

        &ao_can_cond_not_full_wait_4[30].async,

        &ao_can_out_4               [30].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 31

        &ao_can_cond_not_full_wait_4[31].async,

        &ao_can_out_4               [31].async,

#endif

#endif

};

static  ao_async_all_t          ao_can_async_send_4         [AO_CAN_FIFOS_TX_4] =
{

#if AO_CAN_FIFOS_TX_4 >  0

#if AO_CAN_FIFOS_TX_4 >  0

{
        .store                  = ao_can_async_send_store_4 +  0 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  1

{
        .store                  = ao_can_async_send_store_4 +  1 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  2

{
        .store                  = ao_can_async_send_store_4 +  2 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  3

{
        .store                  = ao_can_async_send_store_4 +  3 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  4

{
        .store                  = ao_can_async_send_store_4 +  4 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  5

{
        .store                  = ao_can_async_send_store_4 +  5 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  6

{
        .store                  = ao_can_async_send_store_4 +  6 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  7

{
        .store                  = ao_can_async_send_store_4 +  7 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  8

{
        .store                  = ao_can_async_send_store_4 +  8 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 >  9

{
        .store                  = ao_can_async_send_store_4 +  9 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 10

{
        .store                  = ao_can_async_send_store_4 + 10 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 11

{
        .store                  = ao_can_async_send_store_4 + 11 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 12

{
        .store                  = ao_can_async_send_store_4 + 12 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 13

{
        .store                  = ao_can_async_send_store_4 + 13 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 14

{
        .store                  = ao_can_async_send_store_4 + 14 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 15

{
        .store                  = ao_can_async_send_store_4 + 15 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 16

{
        .store                  = ao_can_async_send_store_4 + 16 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 17

{
        .store                  = ao_can_async_send_store_4 + 17 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 18

{
        .store                  = ao_can_async_send_store_4 + 18 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 19

{
        .store                  = ao_can_async_send_store_4 + 19 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 20

{
        .store                  = ao_can_async_send_store_4 + 20 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 21

{
        .store                  = ao_can_async_send_store_4 + 21 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 22

{
        .store                  = ao_can_async_send_store_4 + 22 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 23

{
        .store                  = ao_can_async_send_store_4 + 23 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 24

{
        .store                  = ao_can_async_send_store_4 + 24 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 25

{
        .store                  = ao_can_async_send_store_4 + 25 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 26

{
        .store                  = ao_can_async_send_store_4 + 26 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 27

{
        .store                  = ao_can_async_send_store_4 + 27 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 28

{
        .store                  = ao_can_async_send_store_4 + 28 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 29

{
        .store                  = ao_can_async_send_store_4 + 29 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 30

{
        .store                  = ao_can_async_send_store_4 + 30 * 2,

        .count                  = 2
},

#endif

#if AO_CAN_FIFOS_TX_4 > 31

{
        .store                  = ao_can_async_send_store_4 + 31 * 2,

        .count                  = 2
},

#endif

#endif

};

// ----------------------------------------------------------------------------

static  ao_async_t *            ao_can_async_started_store_4[AO_CAN_FIFOS_TX_4 + 2] =
{
        &ao_can_cond_change_wait_4.async,

        &ao_can_sem_take_4.async,

#if AO_CAN_FIFOS_TX_4 >  0

#if AO_CAN_FIFOS_TX_4 >  0

        &ao_can_async_send_4[ 0].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  1

        &ao_can_async_send_4[ 1].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  2

        &ao_can_async_send_4[ 2].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  3

        &ao_can_async_send_4[ 3].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  4

        &ao_can_async_send_4[ 4].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  5

        &ao_can_async_send_4[ 5].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  6

        &ao_can_async_send_4[ 6].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  7

        &ao_can_async_send_4[ 7].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  8

        &ao_can_async_send_4[ 8].async,

#endif

#if AO_CAN_FIFOS_TX_4 >  9

        &ao_can_async_send_4[ 9].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 10

        &ao_can_async_send_4[10].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 11

        &ao_can_async_send_4[11].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 12

        &ao_can_async_send_4[12].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 13

        &ao_can_async_send_4[13].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 14

        &ao_can_async_send_4[14].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 15

        &ao_can_async_send_4[15].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 16

        &ao_can_async_send_4[16].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 17

        &ao_can_async_send_4[17].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 18

        &ao_can_async_send_4[18].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 19

        &ao_can_async_send_4[19].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 20

        &ao_can_async_send_4[20].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 21

        &ao_can_async_send_4[21].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 22

        &ao_can_async_send_4[22].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 23

        &ao_can_async_send_4[23].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 24

        &ao_can_async_send_4[24].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 25

        &ao_can_async_send_4[25].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 26

        &ao_can_async_send_4[26].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 27

        &ao_can_async_send_4[27].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 28

        &ao_can_async_send_4[28].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 29

        &ao_can_async_send_4[29].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 30

        &ao_can_async_send_4[30].async,

#endif

#if AO_CAN_FIFOS_TX_4 > 31

        &ao_can_async_send_4[31].async,

#endif

#endif

};

static  ao_async_any_t          ao_can_async_started_4 =
{
        .store                  = ao_can_async_started_store_4,

        .count                  = 2 + AO_CAN_FIFOS_TX_4
};

// ----------------------------------------------------------------------------

void ao_can_change_4(uint32_t mode)
{
    // Assert.

    ao_assert
    (
        mode == 0 ||
        mode == 2 ||
        mode == 3 ||
        mode == 4 ||
        mode == 7
    );


    // Variables.

    ao_can_reg_t * const reg = ao_can_reg_4();


    // Ready.

    while (reg->con.bits.opmod != mode)
    {
        // Request.

        ao_cond_clear(&ao_can_cond_changed_4);

        reg->con.bits.reqop = mode;


        // Await.

        ao_cond_wait_begin( &ao_can_cond_changed_wait_4);

        ao_sem_take_begin(  &ao_can_sem_take_4);

        ao_await_any_forever
        (
            &ao_can_async_change_4
        );

        ao_sem_take_end(    &ao_can_sem_take_4);

        ao_cond_wait_end(   &ao_can_cond_changed_wait_4);


        // Stop.

        if (ao_can_sem_take_4.result)
        {
            ao_can_var_started_4 = false;
        }
    }
}

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_can_config_4()
{
    ao_can_config_baud_4();

    ao_can_config_fifos_4();

    ao_can_config_filter_masks_4();

    ao_can_config_filters_4();
}

__attribute__ ((weak))
void ao_can_config_baud_4()
{
    // Variables.

    ao_can_baud_t x;


    // Ready.

    x.f                 = AO_CAN_BAUD_4;

    x.f_pbclk           = AO_SYS_CLOCK_CAN4;

    x.sample            = AO_CAN_BAUD_SAMPLE_4;

    x.sample_thrice     = AO_CAN_BAUD_SAMPLE_THRICE_4;

    x.sjw               = AO_CAN_BAUD_SJW_4;

    x.wake_up_filter    = AO_CAN_BAUD_WAKE_UP_FILTER_4;

    ao_can_baud(&x);

    ao_assert(x.result);

    C4CFG = x.cfg;
}

__attribute__ ((weak))
void ao_can_config_fifos_4()
{
    // Fifo base address.

    C4FIFOBA = KVA_TO_PA(ao_can_buffers_4);


    // Fifos.

#if AO_CAN_FIFOS_4 > 0

#if AO_CAN_FIFOS_4 > 0

    C4FIFOCON0bits.FSIZE = AO_CAN_BUFFERS_4_0 - 1;

#endif

#if AO_CAN_FIFOS_4 > 1

    C4FIFOCON1bits.FSIZE = AO_CAN_BUFFERS_4_1 - 1;

#endif

#if AO_CAN_FIFOS_4 > 2

    C4FIFOCON2bits.FSIZE = AO_CAN_BUFFERS_4_2 - 1;

#endif

#if AO_CAN_FIFOS_4 > 3

    C4FIFOCON3bits.FSIZE = AO_CAN_BUFFERS_4_3 - 1;

#endif

#if AO_CAN_FIFOS_4 > 4

    C4FIFOCON4bits.FSIZE = AO_CAN_BUFFERS_4_4 - 1;

#endif

#if AO_CAN_FIFOS_4 > 5

    C4FIFOCON5bits.FSIZE = AO_CAN_BUFFERS_4_5 - 1;

#endif

#if AO_CAN_FIFOS_4 > 6

    C4FIFOCON6bits.FSIZE = AO_CAN_BUFFERS_4_6 - 1;

#endif

#if AO_CAN_FIFOS_4 > 7

    C4FIFOCON7bits.FSIZE = AO_CAN_BUFFERS_4_7 - 1;

#endif

#if AO_CAN_FIFOS_4 > 8

    C4FIFOCON8bits.FSIZE = AO_CAN_BUFFERS_4_8 - 1;

#endif

#if AO_CAN_FIFOS_4 > 9

    C4FIFOCON9bits.FSIZE = AO_CAN_BUFFERS_4_9 - 1;

#endif

#if AO_CAN_FIFOS_4 > 10

    C4FIFOCON10bits.FSIZE = AO_CAN_BUFFERS_4_10 - 1;

#endif

#if AO_CAN_FIFOS_4 > 11

    C4FIFOCON11bits.FSIZE = AO_CAN_BUFFERS_4_11 - 1;

#endif

#if AO_CAN_FIFOS_4 > 12

    C4FIFOCON12bits.FSIZE = AO_CAN_BUFFERS_4_12 - 1;

#endif

#if AO_CAN_FIFOS_4 > 13

    C4FIFOCON13bits.FSIZE = AO_CAN_BUFFERS_4_13 - 1;

#endif

#if AO_CAN_FIFOS_4 > 14

    C4FIFOCON14bits.FSIZE = AO_CAN_BUFFERS_4_14 - 1;

#endif

#if AO_CAN_FIFOS_4 > 15

    C4FIFOCON15bits.FSIZE = AO_CAN_BUFFERS_4_15 - 1;

#endif

#if AO_CAN_FIFOS_4 > 16

    C4FIFOCON16bits.FSIZE = AO_CAN_BUFFERS_4_16 - 1;

#endif

#if AO_CAN_FIFOS_4 > 17

    C4FIFOCON17bits.FSIZE = AO_CAN_BUFFERS_4_17 - 1;

#endif

#if AO_CAN_FIFOS_4 > 18

    C4FIFOCON18bits.FSIZE = AO_CAN_BUFFERS_4_18 - 1;

#endif

#if AO_CAN_FIFOS_4 > 19

    C4FIFOCON19bits.FSIZE = AO_CAN_BUFFERS_4_19 - 1;

#endif

#if AO_CAN_FIFOS_4 > 20

    C4FIFOCON20bits.FSIZE = AO_CAN_BUFFERS_4_20 - 1;

#endif

#if AO_CAN_FIFOS_4 > 21

    C4FIFOCON21bits.FSIZE = AO_CAN_BUFFERS_4_21 - 1;

#endif

#if AO_CAN_FIFOS_4 > 22

    C4FIFOCON22bits.FSIZE = AO_CAN_BUFFERS_4_22 - 1;

#endif

#if AO_CAN_FIFOS_4 > 23

    C4FIFOCON23bits.FSIZE = AO_CAN_BUFFERS_4_23 - 1;

#endif

#if AO_CAN_FIFOS_4 > 24

    C4FIFOCON24bits.FSIZE = AO_CAN_BUFFERS_4_24 - 1;

#endif

#if AO_CAN_FIFOS_4 > 25

    C4FIFOCON25bits.FSIZE = AO_CAN_BUFFERS_4_25 - 1;

#endif

#if AO_CAN_FIFOS_4 > 26

    C4FIFOCON26bits.FSIZE = AO_CAN_BUFFERS_4_26 - 1;

#endif

#if AO_CAN_FIFOS_4 > 27

    C4FIFOCON27bits.FSIZE = AO_CAN_BUFFERS_4_27 - 1;

#endif

#if AO_CAN_FIFOS_4 > 28

    C4FIFOCON28bits.FSIZE = AO_CAN_BUFFERS_4_28 - 1;

#endif

#if AO_CAN_FIFOS_4 > 29

    C4FIFOCON29bits.FSIZE = AO_CAN_BUFFERS_4_29 - 1;

#endif

#if AO_CAN_FIFOS_4 > 30

    C4FIFOCON30bits.FSIZE = AO_CAN_BUFFERS_4_30 - 1;

#endif

#if AO_CAN_FIFOS_4 > 31

    C4FIFOCON31bits.FSIZE = AO_CAN_BUFFERS_4_31 - 1;

#endif

#endif

}

__attribute__ ((weak))
void ao_can_config_filter_masks_4()
{
    C4RXM0bits.EID  = AO_CAN_FILTER_MASK_EID_4_0;
    C4RXM0bits.MIDE = AO_CAN_FILTER_MASK_IDE_4_0;
    C4RXM0bits.SID  = AO_CAN_FILTER_MASK_SID_4_0;

    C4RXM1bits.EID  = AO_CAN_FILTER_MASK_EID_4_1;
    C4RXM1bits.MIDE = AO_CAN_FILTER_MASK_IDE_4_1;
    C4RXM1bits.SID  = AO_CAN_FILTER_MASK_SID_4_1;

    C4RXM2bits.EID  = AO_CAN_FILTER_MASK_EID_4_2;
    C4RXM2bits.MIDE = AO_CAN_FILTER_MASK_IDE_4_2;
    C4RXM2bits.SID  = AO_CAN_FILTER_MASK_SID_4_2;

    C4RXM3bits.EID  = AO_CAN_FILTER_MASK_EID_4_3;
    C4RXM3bits.MIDE = AO_CAN_FILTER_MASK_IDE_4_3;
    C4RXM3bits.SID  = AO_CAN_FILTER_MASK_SID_4_3;
}

__attribute__ ((weak))
void ao_can_config_filters_4()
{

#if AO_CAN_FILTER_ENABLE_4_0

    C4RXF0bits.EID          = AO_CAN_FILTER_EID_4_0;
    C4RXF0bits.EXID         = AO_CAN_FILTER_IDE_4_0;
    C4RXF0bits.SID          = AO_CAN_FILTER_SID_4_0;
    C4FLTCON0bits.FSEL0     = AO_CAN_FILTER_FIFO_4_0;
    C4FLTCON0bits.MSEL0     = AO_CAN_FILTER_MASK_4_0;
    C4FLTCON0bits.FLTEN0    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_1

    C4RXF1bits.EID          = AO_CAN_FILTER_EID_4_1;
    C4RXF1bits.EXID         = AO_CAN_FILTER_IDE_4_1;
    C4RXF1bits.SID          = AO_CAN_FILTER_SID_4_1;
    C4FLTCON0bits.FSEL1     = AO_CAN_FILTER_FIFO_4_1;
    C4FLTCON0bits.MSEL1     = AO_CAN_FILTER_MASK_4_1;
    C4FLTCON0bits.FLTEN1    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_2

    C4RXF2bits.EID          = AO_CAN_FILTER_EID_4_2;
    C4RXF2bits.EXID         = AO_CAN_FILTER_IDE_4_2;
    C4RXF2bits.SID          = AO_CAN_FILTER_SID_4_2;
    C4FLTCON0bits.FSEL2     = AO_CAN_FILTER_FIFO_4_2;
    C4FLTCON0bits.MSEL2     = AO_CAN_FILTER_MASK_4_2;
    C4FLTCON0bits.FLTEN2    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_3

    C4RXF3bits.EID          = AO_CAN_FILTER_EID_4_3;
    C4RXF3bits.EXID         = AO_CAN_FILTER_IDE_4_3;
    C4RXF3bits.SID          = AO_CAN_FILTER_SID_4_3;
    C4FLTCON0bits.FSEL3     = AO_CAN_FILTER_FIFO_4_3;
    C4FLTCON0bits.MSEL3     = AO_CAN_FILTER_MASK_4_3;
    C4FLTCON0bits.FLTEN3    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_4

    C4RXF4bits.EID          = AO_CAN_FILTER_EID_4_4;
    C4RXF4bits.EXID         = AO_CAN_FILTER_IDE_4_4;
    C4RXF4bits.SID          = AO_CAN_FILTER_SID_4_4;
    C4FLTCON1bits.FSEL4     = AO_CAN_FILTER_FIFO_4_4;
    C4FLTCON1bits.MSEL4     = AO_CAN_FILTER_MASK_4_4;
    C4FLTCON1bits.FLTEN4    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_5

    C4RXF5bits.EID          = AO_CAN_FILTER_EID_4_5;
    C4RXF5bits.EXID         = AO_CAN_FILTER_IDE_4_5;
    C4RXF5bits.SID          = AO_CAN_FILTER_SID_4_5;
    C4FLTCON1bits.FSEL5     = AO_CAN_FILTER_FIFO_4_5;
    C4FLTCON1bits.MSEL5     = AO_CAN_FILTER_MASK_4_5;
    C4FLTCON1bits.FLTEN5    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_6

    C4RXF6bits.EID          = AO_CAN_FILTER_EID_4_6;
    C4RXF6bits.EXID         = AO_CAN_FILTER_IDE_4_6;
    C4RXF6bits.SID          = AO_CAN_FILTER_SID_4_6;
    C4FLTCON1bits.FSEL6     = AO_CAN_FILTER_FIFO_4_6;
    C4FLTCON1bits.MSEL6     = AO_CAN_FILTER_MASK_4_6;
    C4FLTCON1bits.FLTEN6    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_7

    C4RXF7bits.EID          = AO_CAN_FILTER_EID_4_7;
    C4RXF7bits.EXID         = AO_CAN_FILTER_IDE_4_7;
    C4RXF7bits.SID          = AO_CAN_FILTER_SID_4_7;
    C4FLTCON1bits.FSEL7     = AO_CAN_FILTER_FIFO_4_7;
    C4FLTCON1bits.MSEL7     = AO_CAN_FILTER_MASK_4_7;
    C4FLTCON1bits.FLTEN7    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_8

    C4RXF8bits.EID          = AO_CAN_FILTER_EID_4_8;
    C4RXF8bits.EXID         = AO_CAN_FILTER_IDE_4_8;
    C4RXF8bits.SID          = AO_CAN_FILTER_SID_4_8;
    C4FLTCON2bits.FSEL8     = AO_CAN_FILTER_FIFO_4_8;
    C4FLTCON2bits.MSEL8     = AO_CAN_FILTER_MASK_4_8;
    C4FLTCON2bits.FLTEN8    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_9

    C4RXF9bits.EID          = AO_CAN_FILTER_EID_4_9;
    C4RXF9bits.EXID         = AO_CAN_FILTER_IDE_4_9;
    C4RXF9bits.SID          = AO_CAN_FILTER_SID_4_9;
    C4FLTCON2bits.FSEL9     = AO_CAN_FILTER_FIFO_4_9;
    C4FLTCON2bits.MSEL9     = AO_CAN_FILTER_MASK_4_9;
    C4FLTCON2bits.FLTEN9    = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_10

    C4RXF10bits.EID         = AO_CAN_FILTER_EID_4_10;
    C4RXF10bits.EXID        = AO_CAN_FILTER_IDE_4_10;
    C4RXF10bits.SID         = AO_CAN_FILTER_SID_4_10;
    C4FLTCON2bits.FSEL10    = AO_CAN_FILTER_FIFO_4_10;
    C4FLTCON2bits.MSEL10    = AO_CAN_FILTER_MASK_4_10;
    C4FLTCON2bits.FLTEN10   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_11

    C4RXF11bits.EID         = AO_CAN_FILTER_EID_4_11;
    C4RXF11bits.EXID        = AO_CAN_FILTER_IDE_4_11;
    C4RXF11bits.SID         = AO_CAN_FILTER_SID_4_11;
    C4FLTCON2bits.FSEL11    = AO_CAN_FILTER_FIFO_4_11;
    C4FLTCON2bits.MSEL11    = AO_CAN_FILTER_MASK_4_11;
    C4FLTCON2bits.FLTEN11   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_12

    C4RXF12bits.EID         = AO_CAN_FILTER_EID_4_12;
    C4RXF12bits.EXID        = AO_CAN_FILTER_IDE_4_12;
    C4RXF12bits.SID         = AO_CAN_FILTER_SID_4_12;
    C4FLTCON3bits.FSEL12    = AO_CAN_FILTER_FIFO_4_12;
    C4FLTCON3bits.MSEL12    = AO_CAN_FILTER_MASK_4_12;
    C4FLTCON3bits.FLTEN12   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_13

    C4RXF13bits.EID         = AO_CAN_FILTER_EID_4_13;
    C4RXF13bits.EXID        = AO_CAN_FILTER_IDE_4_13;
    C4RXF13bits.SID         = AO_CAN_FILTER_SID_4_13;
    C4FLTCON3bits.FSEL13    = AO_CAN_FILTER_FIFO_4_13;
    C4FLTCON3bits.MSEL13    = AO_CAN_FILTER_MASK_4_13;
    C4FLTCON3bits.FLTEN13   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_14

    C4RXF14bits.EID         = AO_CAN_FILTER_EID_4_14;
    C4RXF14bits.EXID        = AO_CAN_FILTER_IDE_4_14;
    C4RXF14bits.SID         = AO_CAN_FILTER_SID_4_14;
    C4FLTCON3bits.FSEL14    = AO_CAN_FILTER_FIFO_4_14;
    C4FLTCON3bits.MSEL14    = AO_CAN_FILTER_MASK_4_14;
    C4FLTCON3bits.FLTEN14   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_15

    C4RXF15bits.EID         = AO_CAN_FILTER_EID_4_15;
    C4RXF15bits.EXID        = AO_CAN_FILTER_IDE_4_15;
    C4RXF15bits.SID         = AO_CAN_FILTER_SID_4_15;
    C4FLTCON3bits.FSEL15    = AO_CAN_FILTER_FIFO_4_15;
    C4FLTCON3bits.MSEL15    = AO_CAN_FILTER_MASK_4_15;
    C4FLTCON3bits.FLTEN15   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_16

    C4RXF16bits.EID         = AO_CAN_FILTER_EID_4_16;
    C4RXF16bits.EXID        = AO_CAN_FILTER_IDE_4_16;
    C4RXF16bits.SID         = AO_CAN_FILTER_SID_4_16;
    C4FLTCON4bits.FSEL16    = AO_CAN_FILTER_FIFO_4_16;
    C4FLTCON4bits.MSEL16    = AO_CAN_FILTER_MASK_4_16;
    C4FLTCON4bits.FLTEN16   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_17

    C4RXF17bits.EID         = AO_CAN_FILTER_EID_4_17;
    C4RXF17bits.EXID        = AO_CAN_FILTER_IDE_4_17;
    C4RXF17bits.SID         = AO_CAN_FILTER_SID_4_17;
    C4FLTCON4bits.FSEL17    = AO_CAN_FILTER_FIFO_4_17;
    C4FLTCON4bits.MSEL17    = AO_CAN_FILTER_MASK_4_17;
    C4FLTCON4bits.FLTEN17   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_18

    C4RXF18bits.EID         = AO_CAN_FILTER_EID_4_18;
    C4RXF18bits.EXID        = AO_CAN_FILTER_IDE_4_18;
    C4RXF18bits.SID         = AO_CAN_FILTER_SID_4_18;
    C4FLTCON4bits.FSEL18    = AO_CAN_FILTER_FIFO_4_18;
    C4FLTCON4bits.MSEL18    = AO_CAN_FILTER_MASK_4_18;
    C4FLTCON4bits.FLTEN18   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_19

    C4RXF19bits.EID         = AO_CAN_FILTER_EID_4_19;
    C4RXF19bits.EXID        = AO_CAN_FILTER_IDE_4_19;
    C4RXF19bits.SID         = AO_CAN_FILTER_SID_4_19;
    C4FLTCON4bits.FSEL19    = AO_CAN_FILTER_FIFO_4_19;
    C4FLTCON4bits.MSEL19    = AO_CAN_FILTER_MASK_4_19;
    C4FLTCON4bits.FLTEN19   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_20

    C4RXF20bits.EID         = AO_CAN_FILTER_EID_4_20;
    C4RXF20bits.EXID        = AO_CAN_FILTER_IDE_4_20;
    C4RXF20bits.SID         = AO_CAN_FILTER_SID_4_20;
    C4FLTCON5bits.FSEL20    = AO_CAN_FILTER_FIFO_4_20;
    C4FLTCON5bits.MSEL20    = AO_CAN_FILTER_MASK_4_20;
    C4FLTCON5bits.FLTEN20   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_21

    C4RXF21bits.EID         = AO_CAN_FILTER_EID_4_21;
    C4RXF21bits.EXID        = AO_CAN_FILTER_IDE_4_21;
    C4RXF21bits.SID         = AO_CAN_FILTER_SID_4_21;
    C4FLTCON5bits.FSEL21    = AO_CAN_FILTER_FIFO_4_21;
    C4FLTCON5bits.MSEL21    = AO_CAN_FILTER_MASK_4_21;
    C4FLTCON5bits.FLTEN21   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_22

    C4RXF22bits.EID         = AO_CAN_FILTER_EID_4_22;
    C4RXF22bits.EXID        = AO_CAN_FILTER_IDE_4_22;
    C4RXF22bits.SID         = AO_CAN_FILTER_SID_4_22;
    C4FLTCON5bits.FSEL22    = AO_CAN_FILTER_FIFO_4_22;
    C4FLTCON5bits.MSEL22    = AO_CAN_FILTER_MASK_4_22;
    C4FLTCON5bits.FLTEN22   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_23

    C4RXF23bits.EID         = AO_CAN_FILTER_EID_4_23;
    C4RXF23bits.EXID        = AO_CAN_FILTER_IDE_4_23;
    C4RXF23bits.SID         = AO_CAN_FILTER_SID_4_23;
    C4FLTCON5bits.FSEL23    = AO_CAN_FILTER_FIFO_4_23;
    C4FLTCON5bits.MSEL23    = AO_CAN_FILTER_MASK_4_23;
    C4FLTCON5bits.FLTEN23   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_24

    C4RXF24bits.EID         = AO_CAN_FILTER_EID_4_24;
    C4RXF24bits.EXID        = AO_CAN_FILTER_IDE_4_24;
    C4RXF24bits.SID         = AO_CAN_FILTER_SID_4_24;
    C4FLTCON6bits.FSEL24    = AO_CAN_FILTER_FIFO_4_24;
    C4FLTCON6bits.MSEL24    = AO_CAN_FILTER_MASK_4_24;
    C4FLTCON6bits.FLTEN24   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_25

    C4RXF25bits.EID         = AO_CAN_FILTER_EID_4_25;
    C4RXF25bits.EXID        = AO_CAN_FILTER_IDE_4_25;
    C4RXF25bits.SID         = AO_CAN_FILTER_SID_4_25;
    C4FLTCON6bits.FSEL25    = AO_CAN_FILTER_FIFO_4_25;
    C4FLTCON6bits.MSEL25    = AO_CAN_FILTER_MASK_4_25;
    C4FLTCON6bits.FLTEN25   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_26

    C4RXF26bits.EID         = AO_CAN_FILTER_EID_4_26;
    C4RXF26bits.EXID        = AO_CAN_FILTER_IDE_4_26;
    C4RXF26bits.SID         = AO_CAN_FILTER_SID_4_26;
    C4FLTCON6bits.FSEL26    = AO_CAN_FILTER_FIFO_4_26;
    C4FLTCON6bits.MSEL26    = AO_CAN_FILTER_MASK_4_26;
    C4FLTCON6bits.FLTEN26   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_27

    C4RXF27bits.EID         = AO_CAN_FILTER_EID_4_27;
    C4RXF27bits.EXID        = AO_CAN_FILTER_IDE_4_27;
    C4RXF27bits.SID         = AO_CAN_FILTER_SID_4_27;
    C4FLTCON6bits.FSEL27    = AO_CAN_FILTER_FIFO_4_27;
    C4FLTCON6bits.MSEL27    = AO_CAN_FILTER_MASK_4_27;
    C4FLTCON6bits.FLTEN27   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_28

    C4RXF28bits.EID         = AO_CAN_FILTER_EID_4_28;
    C4RXF28bits.EXID        = AO_CAN_FILTER_IDE_4_28;
    C4RXF28bits.SID         = AO_CAN_FILTER_SID_4_28;
    C4FLTCON7bits.FSEL28    = AO_CAN_FILTER_FIFO_4_28;
    C4FLTCON7bits.MSEL28    = AO_CAN_FILTER_MASK_4_28;
    C4FLTCON7bits.FLTEN28   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_29

    C4RXF29bits.EID         = AO_CAN_FILTER_EID_4_29;
    C4RXF29bits.EXID        = AO_CAN_FILTER_IDE_4_29;
    C4RXF29bits.SID         = AO_CAN_FILTER_SID_4_29;
    C4FLTCON7bits.FSEL29    = AO_CAN_FILTER_FIFO_4_29;
    C4FLTCON7bits.MSEL29    = AO_CAN_FILTER_MASK_4_29;
    C4FLTCON7bits.FLTEN29   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_30

    C4RXF30bits.EID         = AO_CAN_FILTER_EID_4_30;
    C4RXF30bits.EXID        = AO_CAN_FILTER_IDE_4_30;
    C4RXF30bits.SID         = AO_CAN_FILTER_SID_4_30;
    C4FLTCON7bits.FSEL30    = AO_CAN_FILTER_FIFO_4_30;
    C4FLTCON7bits.MSEL30    = AO_CAN_FILTER_MASK_4_30;
    C4FLTCON7bits.FLTEN30   = 1;

#endif

#if AO_CAN_FILTER_ENABLE_4_31

    C4RXF31bits.EID         = AO_CAN_FILTER_EID_4_31;
    C4RXF31bits.EXID        = AO_CAN_FILTER_IDE_4_31;
    C4RXF31bits.SID         = AO_CAN_FILTER_SID_4_31;
    C4FLTCON7bits.FSEL31    = AO_CAN_FILTER_FIFO_4_31;
    C4FLTCON7bits.MSEL31    = AO_CAN_FILTER_MASK_4_31;
    C4FLTCON7bits.FLTEN31   = 1;

#endif

}

// ----------------------------------------------------------------------------

void ao_can_ir_4()
{
    // Variables.

    ao_can_t *          c1;
    ao_can_t *          c2;

    ao_can_fifo_flags_t f;

    uint32_t            i1;
    uint32_t            i2;

    uint32_t            m;

    uint32_t            r;

    ao_can_reg_t *      reg = ao_can_reg_4();

    ao_time_t           t;


    // Ready.

    do
    {
        t = ao_now();

        i1 = reg->vec.bits.icode;

        ao_ir_can4_reply();

        switch (i1)
        {

#if AO_CAN_INVALID_4

            case 0b1001000:

                // Invalid message received.

                ao_can_invalid_4(&ao_can_invalid_info_4);

                reg->intx.bits.ivrif = 0;

                break;

#endif

                // Mode changed.

            case 0b1000111:

#if AO_CAN_MODE_4

                ao_can_mode_4(&ao_can_mode_info_4);

#endif

                ao_cond_set(&ao_can_cond_changed_4);

                reg->intx.bits.modif = 0;

                break;

#if AO_CAN_TIMER_4

            case 0b1000110:

                // Timer.

                ao_can_timer_4(&ao_can_timer_info_4);

                reg->intx.bits.ctmrif = 0;

                break;

#endif

            case 0b1000101:
            case 0b1000100:

                // System error.

#if AO_CAN_SYSTEM_4

                ao_can_system_info_4.flags = (ao_can_system_flags_t) i1;

                ao_can_system_4(&ao_can_system_info_4);

#endif

                reg->con.bits.on = 0;

                while (reg->con.bits.canbusy) { }

                reg->con.bits.on = 1;

                break;

#if AO_CAN_RBOV_4

            case 0b1000011:

                // Receive buffer overrun.

                r = reg->rxovf.reg;

                m = (AO_CAN_FIFOS_TX_4 == 32) ? UINT32_MAX : (1 << AO_CAN_FIFOS_TX_4) - 1;

#if AO_CAN_RXOF_4

                f = (ao_can_fifo_flags_t) (r & ~m);

                if (f != AO_CAN_FIFO_FLAGS_NONE)
                {
                    ao_can_overflow_info_4.fifos = f;

                    ao_can_overflow_info_4.fifos_rx = (ao_can_fifo_flags_t) ((uint32_t) f >> AO_CAN_FIFOS_TX_4);

                    ao_can_overflow_4(&ao_can_overflow_info_4);
                }

#endif

#if AO_CAN_TXUF_4

                f = (ao_can_fifo_flags_t) (r & m);

                if (f != AO_CAN_FIFO_FLAGS_NONE)
                {
                    ao_can_underflow_info_4.fifos = f;

                    ao_can_underflow_info_4.fifos_tx = f;

                    ao_can_underflow_4(&ao_can_underflow_info_4);
                }

#endif

                // DS61154.

                // Section 34.12.1.17.

                // Clearing all the CxFIFOINTn.RXOVFLIF bits will automatically
                // clear the CxINT.RBOVIF bit.

                while (r)
                {
                    i2 = ao_ffsu(r);

                    m = 1 << i2;

                    r = r & ~m;

                    reg->fifo[i2].intx.bits.rxovflif = 0;
                }

                // DS61154.

                // Section 34.12.1.17: The CxINT.RBOVIF bit is not directly clearable.

                // Section 34.3.4    : The CxINT.RBOVIF bit is writable.

                reg->intx.bits.rbovif = 0;

                break;

#endif

#if AO_CAN_WAKE_UP_4

            case 0b1000010:

                // Wake up.

                ao_can_wake_up_4(&ao_can_wake_up_info_4);

                reg->intx.bits.wakif = 0;

                break;

#endif

#if AO_CAN_BUS_4

            case 0b1000001:

                // CAN bus error.

                ao_can_bus_info_4.receive_error_counter = reg->trec.bits.rerrcnt;

                if (reg->trec.bits.rxbp)
                {
                    ao_can_bus_info_4.receive_error_state = AO_CAN_BUS_PASSIVE;
                }

                else if (reg->trec.bits.rxwarn)
                {
                    ao_can_bus_info_4.receive_error_state = AO_CAN_BUS_ACTIVE_WARNING;
                }

                else
                {
                    ao_can_bus_info_4.receive_error_state = AO_CAN_BUS_ACTIVE;
                }

                ao_can_bus_info_4.transmit_error_counter = reg->trec.bits.terrcnt;

                if (reg->trec.bits.txbo)
                {
                    ao_can_bus_info_4.transmit_error_state = AO_CAN_BUS_OFF;
                }

                else if (reg->trec.bits.txbp)
                {
                    ao_can_bus_info_4.transmit_error_state = AO_CAN_BUS_PASSIVE;
                }

                else if (reg->trec.bits.txwarn)
                {
                    ao_can_bus_info_4.transmit_error_state = AO_CAN_BUS_ACTIVE_WARNING;
                }

                else
                {
                    ao_can_bus_info_4.transmit_error_state = AO_CAN_BUS_ACTIVE;
                }

                ao_can_bus_4(&ao_can_bus_info_4);

                reg->intx.bits.cerrif = 0;

                break;

#endif

            case 0b1000000:

                // No interrupt.

                break;

#if AO_CAN_RX_4

#if AO_CAN_FIFOS_4 > 31  &&  AO_CAN_FIFOS_TX_4 <= 31

            case 31:

#endif

#if AO_CAN_FIFOS_4 > 30  &&  AO_CAN_FIFOS_TX_4 <= 30

            case 30:

#endif

#if AO_CAN_FIFOS_4 > 29  &&  AO_CAN_FIFOS_TX_4 <= 29

            case 29:

#endif

#if AO_CAN_FIFOS_4 > 28  &&  AO_CAN_FIFOS_TX_4 <= 28

            case 28:

#endif

#if AO_CAN_FIFOS_4 > 27  &&  AO_CAN_FIFOS_TX_4 <= 27

            case 27:

#endif

#if AO_CAN_FIFOS_4 > 26  &&  AO_CAN_FIFOS_TX_4 <= 26

            case 26:

#endif

#if AO_CAN_FIFOS_4 > 25  &&  AO_CAN_FIFOS_TX_4 <= 25

            case 25:

#endif

#if AO_CAN_FIFOS_4 > 24  &&  AO_CAN_FIFOS_TX_4 <= 24

            case 24:

#endif

#if AO_CAN_FIFOS_4 > 23  &&  AO_CAN_FIFOS_TX_4 <= 23

            case 23:

#endif

#if AO_CAN_FIFOS_4 > 22  &&  AO_CAN_FIFOS_TX_4 <= 22

            case 22:

#endif

#if AO_CAN_FIFOS_4 > 21  &&  AO_CAN_FIFOS_TX_4 <= 21

            case 21:

#endif

#if AO_CAN_FIFOS_4 > 20  &&  AO_CAN_FIFOS_TX_4 <= 20

            case 20:

#endif

#if AO_CAN_FIFOS_4 > 19  &&  AO_CAN_FIFOS_TX_4 <= 19

            case 19:

#endif

#if AO_CAN_FIFOS_4 > 18  &&  AO_CAN_FIFOS_TX_4 <= 18

            case 18:

#endif

#if AO_CAN_FIFOS_4 > 17  &&  AO_CAN_FIFOS_TX_4 <= 17

            case 17:

#endif

#if AO_CAN_FIFOS_4 > 16  &&  AO_CAN_FIFOS_TX_4 <= 16

            case 16:

#endif

#if AO_CAN_FIFOS_4 > 15  &&  AO_CAN_FIFOS_TX_4 <= 15

            case 15:

#endif

#if AO_CAN_FIFOS_4 > 14  &&  AO_CAN_FIFOS_TX_4 <= 14

            case 14:

#endif

#if AO_CAN_FIFOS_4 > 13  &&  AO_CAN_FIFOS_TX_4 <= 13

            case 13:

#endif

#if AO_CAN_FIFOS_4 > 12  &&  AO_CAN_FIFOS_TX_4 <= 12

            case 12:

#endif

#if AO_CAN_FIFOS_4 > 11  &&  AO_CAN_FIFOS_TX_4 <= 11

            case 11:

#endif

#if AO_CAN_FIFOS_4 > 10  &&  AO_CAN_FIFOS_TX_4 <= 10

            case 10:

#endif

#if AO_CAN_FIFOS_4 >  9  &&  AO_CAN_FIFOS_TX_4 <=  9

            case  9:

#endif

#if AO_CAN_FIFOS_4 >  8  &&  AO_CAN_FIFOS_TX_4 <=  8

            case  8:

#endif

#if AO_CAN_FIFOS_4 >  7  &&  AO_CAN_FIFOS_TX_4 <=  7

            case  7:

#endif

#if AO_CAN_FIFOS_4 >  6  &&  AO_CAN_FIFOS_TX_4 <=  6

            case  6:

#endif

#if AO_CAN_FIFOS_4 >  5  &&  AO_CAN_FIFOS_TX_4 <=  5

            case  5:

#endif

#if AO_CAN_FIFOS_4 >  4  &&  AO_CAN_FIFOS_TX_4 <=  4

            case  4:

#endif

#if AO_CAN_FIFOS_4 >  3  &&  AO_CAN_FIFOS_TX_4 <=  3

            case  3:

#endif

#if AO_CAN_FIFOS_4 >  2  &&  AO_CAN_FIFOS_TX_4 <=  2

            case  2:

#endif

#if AO_CAN_FIFOS_4 >  1  &&  AO_CAN_FIFOS_TX_4 <=  1

            case  1:

#endif

#if AO_CAN_FIFOS_4 >  0  &&  AO_CAN_FIFOS_TX_4 <=  0

            case  0:

#endif

                c1 = PA_TO_KVA1(reg->fifo[i1].ua.reg);

                c2 = ao_can_in_can_4 + i1 - AO_CAN_FIFOS_TX_4;

                if (reg->fifo[i1].con.bits.donly)
                {
                    c2->cmsgsid = 0;

                    c2->cmsgeid = 0;

                    c2->data = *((uint64_t *) c1);
                }

                else
                {
                    *c2 = *c1;
                }

                if (!c2->ide && c2->srr)
                {
                    c2->rtr = 1;
                }

                ao_send_obj_try(ao_can_in_4 + i1 - AO_CAN_FIFOS_TX_4);

                // DS80000480.

                // The CxFIFOCONn.FRESET bit and the CxFIFOCONn.UINC
                // bit are not settable through a normal Special
                // Function Register (SFR) write.

                // Use the SET register operations to change the state
                // of these bits.

                reg->fifo[i1].con.set = _C4FIFOCON0_UINC_MASK;

                break;

#endif

#if AO_CAN_TX_4

#if AO_CAN_FIFOS_4 > 31  &&  AO_CAN_FIFOS_TX_4 > 31

            case 31:

#endif

#if AO_CAN_FIFOS_4 > 30  &&  AO_CAN_FIFOS_TX_4 > 30

            case 30:

#endif

#if AO_CAN_FIFOS_4 > 29  &&  AO_CAN_FIFOS_TX_4 > 29

            case 29:

#endif

#if AO_CAN_FIFOS_4 > 28  &&  AO_CAN_FIFOS_TX_4 > 28

            case 28:

#endif

#if AO_CAN_FIFOS_4 > 27  &&  AO_CAN_FIFOS_TX_4 > 27

            case 27:

#endif

#if AO_CAN_FIFOS_4 > 26  &&  AO_CAN_FIFOS_TX_4 > 26

            case 26:

#endif

#if AO_CAN_FIFOS_4 > 25  &&  AO_CAN_FIFOS_TX_4 > 25

            case 25:

#endif

#if AO_CAN_FIFOS_4 > 24  &&  AO_CAN_FIFOS_TX_4 > 24

            case 24:

#endif

#if AO_CAN_FIFOS_4 > 23  &&  AO_CAN_FIFOS_TX_4 > 23

            case 23:

#endif

#if AO_CAN_FIFOS_4 > 22  &&  AO_CAN_FIFOS_TX_4 > 22

            case 22:

#endif

#if AO_CAN_FIFOS_4 > 21  &&  AO_CAN_FIFOS_TX_4 > 21

            case 21:

#endif

#if AO_CAN_FIFOS_4 > 20  &&  AO_CAN_FIFOS_TX_4 > 20

            case 20:

#endif

#if AO_CAN_FIFOS_4 > 19  &&  AO_CAN_FIFOS_TX_4 > 19

            case 19:

#endif

#if AO_CAN_FIFOS_4 > 18  &&  AO_CAN_FIFOS_TX_4 > 18

            case 18:

#endif

#if AO_CAN_FIFOS_4 > 17  &&  AO_CAN_FIFOS_TX_4 > 17

            case 17:

#endif

#if AO_CAN_FIFOS_4 > 16  &&  AO_CAN_FIFOS_TX_4 > 16

            case 16:

#endif

#if AO_CAN_FIFOS_4 > 15  &&  AO_CAN_FIFOS_TX_4 > 15

            case 15:

#endif

#if AO_CAN_FIFOS_4 > 14  &&  AO_CAN_FIFOS_TX_4 > 14

            case 14:

#endif

#if AO_CAN_FIFOS_4 > 13  &&  AO_CAN_FIFOS_TX_4 > 13

            case 13:

#endif

#if AO_CAN_FIFOS_4 > 12  &&  AO_CAN_FIFOS_TX_4 > 12

            case 12:

#endif

#if AO_CAN_FIFOS_4 > 11  &&  AO_CAN_FIFOS_TX_4 > 11

            case 11:

#endif

#if AO_CAN_FIFOS_4 > 10  &&  AO_CAN_FIFOS_TX_4 > 10

            case 10:

#endif

#if AO_CAN_FIFOS_4 >  9  &&  AO_CAN_FIFOS_TX_4 >  9

            case  9:

#endif

#if AO_CAN_FIFOS_4 >  8  &&  AO_CAN_FIFOS_TX_4 >  8

            case  8:

#endif

#if AO_CAN_FIFOS_4 >  7  &&  AO_CAN_FIFOS_TX_4 >  7

            case  7:

#endif

#if AO_CAN_FIFOS_4 >  6  &&  AO_CAN_FIFOS_TX_4 >  6

            case  6:

#endif

#if AO_CAN_FIFOS_4 >  5  &&  AO_CAN_FIFOS_TX_4 >  5

            case  5:

#endif

#if AO_CAN_FIFOS_4 >  4  &&  AO_CAN_FIFOS_TX_4 >  4

            case  4:

#endif

#if AO_CAN_FIFOS_4 >  3  &&  AO_CAN_FIFOS_TX_4 >  3

            case  3:

#endif

#if AO_CAN_FIFOS_4 >  2  &&  AO_CAN_FIFOS_TX_4 >  2

            case  2:

#endif

#if AO_CAN_FIFOS_4 >  1  &&  AO_CAN_FIFOS_TX_4 >  1

            case  1:

#endif

#if AO_CAN_FIFOS_4 >  0  &&  AO_CAN_FIFOS_TX_4 >  0

            case  0:

#endif

                // Fifo.

#if AO_CAN_TXST_4

                if
                (
                    reg->fifo[i1].intx.bits.txemptyie &&
                    reg->fifo[i1].intx.bits.txemptyif
                )
                {
                    ao_can_sent_info_4.fifo = i1;

                    ao_can_sent_info_4.fifo_tx = i1;

                    ao_can_sent_4(&ao_can_sent_info_4);

                    reg->fifo[i1].intx.bits.txemptyie = 0;
                }

                if
                (
                    reg->fifo[i1].intx.bits.txnfullie &&
                    reg->fifo[i1].intx.bits.txnfullif
                )
                {

#endif

                    ao_cond_set(ao_can_cond_not_full_4 + i1);

                    reg->fifo[i1].intx.bits.txnfullie = 0;

#if AO_CAN_TXST_4

                }

#endif

                break;

#endif

            default:

                // This really should not have happend.

                ao_assert(false);

                break;
        }
    }
    while (i1 != 0b1000000);
}

// ----------------------------------------------------------------------------

void ao_can_listen_all_4()
{
    ao_can_var_mode_4 = 7;

    ao_cond_set(&ao_can_cond_change_4);
}

void ao_can_listen_only_4()
{
    ao_can_var_mode_4 = 3;

    ao_cond_set(&ao_can_cond_change_4);
}

void ao_can_loopback_4()
{
    ao_can_var_mode_4 = 2;

    ao_cond_set(&ao_can_cond_change_4);
}

void ao_can_normal_4()
{
    ao_can_var_mode_4 = 0;

    ao_cond_set(&ao_can_cond_change_4);
}

// ----------------------------------------------------------------------------

void ao_can_start_4()
{
    ao_task_start(&ao_can_task_4);
}

void ao_can_started_4()
{
    // Variables.

#if AO_CAN_TX_4

    ao_can_t *      c1;
    ao_can_t *      c2;

    size_t          i;

    ao_can_reg_t *  reg = ao_can_reg_4();

#endif


    // Ready.

    while (ao_can_var_started_4)
    {
        // Await begin.

        ao_cond_wait_begin(     &ao_can_cond_change_wait_4);

        ao_sem_take_begin(      &ao_can_sem_take_4);

#if AO_CAN_TX_4

        for (i = 0; i < AO_CAN_FIFOS_TX_4; i++)
        {
            ao_cond_wait_begin( &ao_can_cond_not_full_wait_4[i]);

            ao_recv_obj_begin(  &ao_can_out_4               [i]);

            ao_async_all_begin( &ao_can_async_send_4        [i]);
        }

#endif


        // Await.

        ao_await_any_forever(   &ao_can_async_started_4);


        // Await end.

#if AO_CAN_TX_4

        for (i = 0; i < AO_CAN_FIFOS_TX_4; i++)
        {
            ao_async_all_end(   &ao_can_async_send_4        [i]);

            ao_recv_obj_end(    &ao_can_out_4               [i]);

            ao_cond_wait_end(   &ao_can_cond_not_full_wait_4[i]);
        }

#endif

        ao_sem_take_end(        &ao_can_sem_take_4);

        ao_cond_wait_end(       &ao_can_cond_change_wait_4);


        // Stop.

        if (ao_can_sem_take_4.result)
        {
            ao_can_var_started_4 = false;
        }


        // Change.

        else if (ao_can_cond_change_wait_4.result)
        {
            ao_cond_clear(&ao_can_cond_change_4);

            ao_can_change_4(ao_can_var_mode_4);
        }


        // Out.

#if AO_CAN_TX_4

        else
        {
            for (i = 0; i < AO_CAN_FIFOS_TX_4; i++)
            {
                if
                (
                    ao_can_cond_not_full_wait_4 [i].result &&
                    ao_can_out_4                [i].result
                )
                {
                    c2 = ao_can_out_can_4 + i;

                    c1 = (ao_can_t *) PA_TO_KVA1(reg->fifo[i].ua.reg);

                    *c1 = *c2;


                    // DS61154.

                    // Section 34.7.1.

                    // Format of Transmit Message Buffer.

                    // Unused bits should be clear.

                    // RB0 and RB1 bits must be clear.

                    c1->cmsgeid &= 0x3FFFFE0F;
                    c1->cmsgsid &= 0x000007FF;


                    // In case of an extended message format,
                    // the SRR bit should be set.

                    if (c1->ide)
                    {
                        c1->srr = 1;
                    }


                    // DS80000480.

                    // The CxFIFOCONn.FRESET bit and the CxFIFOCONn.UINC bit
                    // are not settable through a normal Special Function
                    // Register (SFR) write.

                    // Use the SET register operations to change the state of
                    // these bits.

                    reg->fifo[i].con.set = _C4FIFOCON0_UINC_MASK;


#if AO_CAN_TXST_4

                    reg->fifo[i].intx.bits.txemptyie = 1;

#endif

                    if (reg->fifo[i].con.bits.rtren == 0)
                    {
                        if (reg->fifo[i].intx.bits.txnfullif == 0)
                        {
                            ao_cond_clear(ao_can_cond_not_full_4 + i);

                            reg->fifo[i].intx.bits.txnfullie = 1;
                        }

                        reg->fifo[i].con.set = _C4FIFOCON0_TXREQ_MASK;
                    }
                }
            }
        }

#endif

    }
}

void ao_can_starting_4()
{
    // Variables.

    uint32_t mode;


    // Ready.

    ao_can_var_started_4 = true;

    ao_cond_clear(&ao_can_cond_change_4);

    mode = ao_can_var_mode_4;

    ao_assert
    (
        mode == 0 ||
        mode == 2 ||
        mode == 3 ||
        mode == 7
    );

    ao_can_change_4(mode);
}

void ao_can_stop_4()
{
    ao_sem_give(&ao_can_sem_4, 1);
}

void ao_can_stopping_4()
{
    ao_can_change_4(4);
}

// ----------------------------------------------------------------------------

void ao_can_task_proc_4(void * x)
{
    // Variables.

    size_t          i;

    ao_can_reg_t *  reg = ao_can_reg_4();

    (void)          x;


    // Ready.

    while (1)
    {
        // On.

        reg->con.bits.on = 1;

        ao_assert(reg->con.bits.opmod == 4);


        // Configuration.

        ao_can_config_4();


        // Interrupts layer 3.

#if AO_CAN_RX_4

        for (i = AO_CAN_FIFOS_TX_4; i < AO_CAN_FIFOS_TX_4 + AO_CAN_FIFOS_RX_4; i++)
        {
            reg->fifo[i].con.bits.txen = 0;

            reg->fifo[i].intx.bits.rxnemptyie = 1;

#if AO_CAN_RXOF_4

            reg->fifo[i].intx.bits.rxovflie = 1;

#endif

        }

#endif

#if AO_CAN_TX_4

        for (i = 0; i < AO_CAN_FIFOS_TX_4; i++)
        {
            reg->fifo[i].con.bits.txen = 1;

            if (reg->fifo[i].con.bits.rtren)
            {

#if AO_CAN_TXUF_4

                reg->fifo[i].intx.bits.rxovflie = 1;

#endif

                ao_cond_set(&ao_can_cond_not_full_4[i]);
            }

            else
            {
                if (reg->fifo[i].intx.bits.txnfullif == 0)
                {
                    reg->fifo[i].intx.bits.txnfullie = 1;
                }

                else
                {
                    ao_cond_set(&ao_can_cond_not_full_4[i]);
                }
            }

#if AO_CAN_TXST_4

            if (reg->fifo[i].intx.bits.txemptyif) { }

            else
            {
                reg->fifo[i].intx.bits.txemptyie = 1;
            }

#endif

        }

#endif


        // Interrupts layer 2.

        reg->intx.bits.modie = 1;
        reg->intx.bits.serrie = 1;

#if AO_CAN_BUS_4

        reg->intx.bits.cerrie = 1;

#endif

#if AO_CAN_INVALID_4

        reg->intx.bits.ivrie = 1;

#endif

#if AO_CAN_RBOV_4

        reg->intx.bits.rbovie = 1;

#endif

#if AO_CAN_RX_4

        reg->intx.bits.rbie = 1;

#endif

#if AO_CAN_TIMER_4

        reg->intx.bits.ctmrie = 1;

#endif

#if AO_CAN_TX_4

        reg->intx.bits.tbie = 1;

#endif

#if AO_CAN_WAKE_UP_4

        reg->intx.bits.wakie = 1;

#endif


        // Interrupts layer 1.

        ao_ir_can4_enable();


        // Start.

        ao_can_starting_4();

        ao_can_started_4();


        // Stop.

        ao_can_stopping_4();


        // Interrupts layer 1.

        ao_ir_can4_disable();


        // Interrupts layer 2.

        reg->intx.bits.modie = 0;
        reg->intx.bits.serrie = 0;

#if AO_CAN_BUS_4

        reg->intx.bits.cerrie = 0;

#endif

#if AO_CAN_INVALID_4

        reg->intx.bits.ivrie = 0;

#endif

#if AO_CAN_RBOV_4

        reg->intx.bits.rbovie = 0;

#endif

#if AO_CAN_RX_4

        reg->intx.bits.rbie = 0;

#endif

#if AO_CAN_TIMER_4

        reg->intx.bits.ctmrie = 0;

#endif

#if AO_CAN_TX_4

        reg->intx.bits.tbie = 0;

#endif

#if AO_CAN_WAKE_UP_4

        reg->intx.bits.wakie = 0;

#endif


        // Interrupts layer 3.

#if AO_CAN_TX_4

        for (i = 0; i < AO_CAN_FIFOS_TX_4; i++)
        {

            reg->fifo[i].intx.bits.txnfullie = 0;

#if AO_CAN_TXUF_4

            reg->fifo[i].intx.bits.rxovflie = 0;

#endif

#if AO_CAN_TXST_4

            reg->fifo[i].intx.bits.txemptyie = 0;

#endif

        }

#endif

#if AO_CAN_RX_4

        for (i = AO_CAN_FIFOS_TX_4; i < AO_CAN_FIFOS_TX_4 + AO_CAN_FIFOS_RX_4; i++)
        {
            reg->fifo[i].intx.bits.rxnemptyie = 0;

#if AO_CAN_RXOF_4

            reg->fifo[i].intx.bits.rxovflie = 0;

#endif

        }

#endif


        // Off.

        reg->con.bits.on = 0;

        while (reg->con.bits.canbusy) { }


        // Task.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32MK

#if defined AO_CAN_1 && AO_CAN_1

// ----------------------------------------------------------------------------

AO_IR_CAN1_ATTRIBUTE
void ao_ir_can1()
{
    ao_ir_stack_func0((ao_func0_t) ao_can_ir_1);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_CAN_2 && AO_CAN_2

// ----------------------------------------------------------------------------

AO_IR_CAN2_ATTRIBUTE
void ao_ir_can2()
{
    ao_ir_stack_func0((ao_func0_t) ao_can_ir_2);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_CAN_3 && AO_CAN_3

// ----------------------------------------------------------------------------

AO_IR_CAN3_ATTRIBUTE
void ao_ir_can3()
{
    ao_ir_stack_func0((ao_func0_t) ao_can_ir_3);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_CAN_4 && AO_CAN_4

// ----------------------------------------------------------------------------

AO_IR_CAN4_ATTRIBUTE
void ao_ir_can4()
{
    ao_ir_stack_func0((ao_func0_t) ao_can_ir_4);
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MX

#if defined AO_CAN_1 && AO_CAN_1

// ----------------------------------------------------------------------------

AO_IR_CAN1_ATTRIBUTE
void ao_ir_can1()
{
    ao_ir_stack_func0((ao_func0_t) ao_can_ir_1);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_CAN_2 && AO_CAN_2

// ----------------------------------------------------------------------------

AO_IR_CAN2_ATTRIBUTE
void ao_ir_can2()
{
    ao_ir_stack_func0((ao_func0_t) ao_can_ir_2);
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MZ

#if defined AO_CAN_1 && AO_CAN_1

// ----------------------------------------------------------------------------

AO_IR_CAN1_ATTRIBUTE
void ao_ir_can1()
{
    ao_ir_stack_func0((ao_func0_t) ao_can_ir_1);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_CAN_2 && AO_CAN_2

// ----------------------------------------------------------------------------

AO_IR_CAN2_ATTRIBUTE
void ao_ir_can2()
{
    ao_ir_stack_func0((ao_func0_t) ao_can_ir_2);
}

// ----------------------------------------------------------------------------

#endif

#endif

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32_I2C

#if defined AO_I2C

// ----------------------------------------------------------------------------

static  bool    ao_i2c_recving( ao_i2c_reg_t * r);

// ----------------------------------------------------------------------------

static  bool    ao_i2c_sending( ao_i2c_reg_t * r);

// ----------------------------------------------------------------------------

bool ao_i2c_ack(ao_i2c_reg_t * r, ao_time_t t)
{
    return ao_i2c_ack_from(r, t, ao_now());
}

bool ao_i2c_ack_from(ao_i2c_reg_t * r, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(r);


    // Variables.

    ao_time_t   e;

    ao_time_t   x;

    bool        R1;
    bool        R2;
    bool        R3;


    // Ready.

    if (t == AO_INFINITY)
    {
        R3 = ao_i2c_ack_forever(r);
    }

    else
    {
        do
        {
            e = ao_now();

            x = e - b;

            t = t > x ? t - x : 0;

            b = e;

            R1 = (r->con.reg & 0x1F) ? true : false;
        }
        while (R1 && t > 0);

        if (R1) { }

        else
        {
            r->stat.bits.bcl = 0;

            r->con.bits.ackdt = 0;

            r->con.bits.acken = 1;

            do
            {
                e = ao_now();

                x = e - b;

                t = t > x ? t - x : 0;

                b = e;

                R1 = r->con.bits.acken ? true : false;

                R2 = r->stat.bits.bcl ? false : true;
            }
            while (R1 && R2 && t > 0);

            if (R2) { }

            else
            {
                R1 = true;
            }
        }

        R3 = !R1;
    }

    return R3;
}

bool ao_i2c_ack_forever(ao_i2c_reg_t * r)
{
    // Assert.

    ao_assert(r);


    // Variables.

    bool R1;
    bool R2;


    // Ready.

    while (r->con.reg & 0x1F) { }

    r->stat.bits.bcl = 0;

    r->con.bits.ackdt = 0;

    r->con.bits.acken = 1;

    do
    {
        R1 = r->con.bits.acken ? true : false;

        R2 = r->stat.bits.bcl ? false : true;
    }
    while (R1 && R2);

    return R2;
}

// ----------------------------------------------------------------------------

bool ao_i2c_acked(ao_i2c_reg_t const * r)
{
    ao_assert(r);

    return (r->stat.bits.ackstat == 0) ? true : false;
}

// ----------------------------------------------------------------------------

void ao_i2c_baud(ao_i2c_reg_t * r, uint32_t f_pbclk, uint32_t f)
{
    // Assert.

    ao_assert(r);

    ao_assert(f_pbclk);

    ao_assert(f);


    // Variables.

    uint64_t b;

    uint64_t t1;
    uint64_t t2;


    // Ready.

    // DS60001116.

    // TPGOB is nominally 130 ns.

    t1 = (uint64_t) f_pbclk;

    t2 = (uint64_t) f;

    b = t1;

    b = b * (1000000000ULL / f - 130ULL);

    b = b / 2000000000ULL;

    b = b - 1ULL;

    // DS60001116.

    // BRG values of 0 through 3 are expressly prohibited.

    // Do not program the register to any of these values, as indeterminate
    // results may occur.

    ao_assert(b >= 4);

    ao_assert(b <= AO_I2C_BRG_MAX);

    r->brg.reg = (uint32_t) b;
}

// ----------------------------------------------------------------------------

bool ao_i2c_nack(ao_i2c_reg_t * r, ao_time_t t)
{
    return ao_i2c_nack_from(r, t, ao_now());
}

bool ao_i2c_nack_from(ao_i2c_reg_t * r, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(r);


    // Variables.

    ao_time_t   e;

    ao_time_t   x;

    bool        R1;
    bool        R2;
    bool        R3;


    // Ready.

    if (t == AO_INFINITY)
    {
        R3 = ao_i2c_nack_forever(r);
    }

    else
    {
        do
        {
            e = ao_now();

            x = e - b;

            t = t > x ? t - x : 0;

            b = e;

            R1 = (r->con.reg & 0x1F) ? true : false;
        }
        while (R1 && t > 0);

        if (R1) { }

        else
        {
            r->stat.bits.bcl = 0;

            r->con.bits.ackdt = 1;

            r->con.bits.acken = 1;

            do
            {
                e = ao_now();

                x = e - b;

                t = t > x ? t - x : 0;

                b = e;

                R1 = r->con.bits.acken ? true : false;

                R2 = r->stat.bits.bcl ? false : true;
            }
            while (R1 && R2 && t > 0);

            if (R2) { }

            else
            {
                R1 = true;
            }
        }

        R3 = !R1;
    }

    return R3;
}

bool ao_i2c_nack_forever(ao_i2c_reg_t * r)
{
    // Assert.

    ao_assert(r);


    // Variables.

    bool R1;
    bool R2;


    // Ready.

    while (r->con.reg & 0x1F) { }

    r->stat.bits.bcl = 0;

    r->con.bits.ackdt = 1;

    r->con.bits.acken = 1;

    do
    {
        R1 = r->con.bits.acken ? true : false;

        R2 = r->stat.bits.bcl ? false : true;
    }
    while (R1 && R2);

    return R2;
}

// ----------------------------------------------------------------------------

bool ao_i2c_nacked(ao_i2c_reg_t const * r)
{
    ao_assert(r);

    return (r->stat.bits.ackstat == 1) ? true : false;
}

// ----------------------------------------------------------------------------

bool ao_i2c_recv(ao_i2c_reg_t * r, uint8_t * v, ao_time_t t)
{
    return ao_i2c_recv_from(r, v, t, ao_now());
}

bool ao_i2c_recv_from(ao_i2c_reg_t * r, uint8_t * v, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(r);

    ao_assert(v);


    // Variables.

    ao_time_t   e;

    ao_time_t   x;

    bool        R1;
    bool        R2;
    bool        R3;


    // Ready.

    if (t == AO_INFINITY)
    {
        R3 = ao_i2c_recv_forever(r, v);
    }

    else
    {
        R1 = r->stat.bits.rbf ? true : false;

        if (R1)
        {
            do
            {
                e = ao_now();

                x = e - b;

                t = t > x ? t - x : 0;

                b = e;

                *v = r->rcv.reg;

                R1 = r->stat.bits.rbf;
            }
            while (R1 && t > 0);
        }

        if (R1) { }

        else
        {
            r->stat.bits.i2cov = 0;

            do
            {
                e = ao_now();

                x = e - b;

                t = t > x ? t - x : 0;

                b = e;

                R1 = (r->con.reg & 0x1F) ? true : false;
            }
            while (R1 && t > 0);

            if (R1) { }

            else
            {
                r->stat.bits.bcl = 0;

                r->con.bits.rcen = 1;

                do
                {
                    e = ao_now();

                    x = e - b;

                    t = t > x ? t - x : 0;

                    b = e;

                    R1 = ao_i2c_recving(r);

                    R2 = r->stat.bits.bcl ? false : true;
                }
                while (R1 && R2 && t > 0);

                if (R1) { }

                else
                {
                    if (R2)
                    {
                        *v = r->rcv.reg;
                    }

                    else
                    {
                        R1 = true;
                    }
                }
            }
        }

        R3 = !R1;
    }

    return R3;
}

bool ao_i2c_recv_forever(ao_i2c_reg_t * r, uint8_t * v)
{
    // Assert.

    ao_assert(r);

    ao_assert(v);


    // Variables.

    bool R1;
    bool R2;


    // Ready.

    while (r->stat.bits.rbf)
    {
        *v = r->rcv.reg;
    }

    while (r->con.reg & 0x1F) { }

    r->stat.bits.bcl = 0;

    r->stat.bits.i2cov = 0;

    r->con.bits.rcen = 1;

    do
    {
        R1 = ao_i2c_recving(r);

        R2 = r->stat.bits.bcl ? false : true;
    }
    while (R1 && R2);

    if (R2)
    {
        *v = r->rcv.reg;
    }

    return R2;
}

// ----------------------------------------------------------------------------

bool ao_i2c_recving(ao_i2c_reg_t * r)
{
    if
    (
        r->con.bits.rcen    ||  // Reception in progress.

        !r->stat.bits.rbf       // Receive buffer not full.
    )
    {
        return true;
    }

    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------------

bool ao_i2c_restart(ao_i2c_reg_t * r, ao_time_t t)
{
    return ao_i2c_restart_from(r, t, ao_now());
}

bool ao_i2c_restart_from(ao_i2c_reg_t * r, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(r);


    // Variables.

    ao_time_t   e;

    ao_time_t   x;

    bool        R1;
    bool        R2;
    bool        R3;


    // Ready.

    if (t == AO_INFINITY)
    {
        R3 = ao_i2c_restart_forever(r);
    }

    else
    {
        do
        {
            e = ao_now();

            x = e - b;

            t = t > x ? t - x : 0;

            b = e;

            R1 = (r->con.reg & 0x1F) ? true : false;
        }
        while (R1 && t > 0);

        if (R1) { }

        else
        {
            r->stat.bits.bcl = 0;

            r->con.bits.rsen = 1;

            do
            {
                e = ao_now();

                x = e - b;

                t = t > x ? t - x : 0;

                b = e;

                R1 = r->con.bits.rsen ? true : false;

                R2 = r->stat.bits.bcl ? false : true;
            }
            while (R1 && R2 && t > 0);

            if (R2) { }

            else
            {
                R1 = true;
            }
        }

        R3 = !R1;
    }

    return R3;
}

bool ao_i2c_restart_forever(ao_i2c_reg_t * r)
{
    // Assert.

    ao_assert(r);


    // Variables.

    bool R1;
    bool R2;


    // Ready.

    while (r->con.reg & 0x1F) { }

    r->stat.bits.bcl = 0;

    r->con.bits.rsen = 1;

    do
    {
        R1 = r->con.bits.rsen ? true : false;

        R2 = r->stat.bits.bcl ? false : true;
    }
    while (R1 && R2);

    return R2;
}

// ----------------------------------------------------------------------------

bool ao_i2c_send(ao_i2c_reg_t * r, uint8_t v, ao_time_t t)
{
    return ao_i2c_send_from(r, v, t, ao_now());
}

bool ao_i2c_send_from(ao_i2c_reg_t * r, uint8_t v, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(r);


    // Variables.

    ao_time_t   e;

    ao_time_t   x;

    bool        R1;
    bool        R2;
    bool        R3;
    bool        R4;


    // Ready.

    if (t == AO_INFINITY)
    {
        R4 = ao_i2c_send_forever(r, v);
    }

    else
    {
        do
        {
            e = ao_now();

            x = e - b;

            t = t > x ? t - x : 0;

            b = e;

            R1 = (r->con.reg & 0x1F) ? true : false;
        }
        while (R1 && t > 0);

        if (R1) { }

        else
        {
            r->stat.bits.bcl = 0;

            r->stat.bits.iwcol = 0;

            r->trn.reg = v;

            do
            {
                e = ao_now();

                x = e - b;

                t = t > x ? t - x : 0;

                b = e;

                R1 = ao_i2c_sending(r);

                R2 = r->stat.bits.iwcol ? false : true;

                R3 = r->stat.bits.bcl ? false : true;
            }
            while (R1 && R2 && R3 && t > 0);

            if (R2 && R3) { }

            else
            {
                R1 = true;
            }
        }

        R4 = !R1;
    }

    return R4;
}

bool ao_i2c_send_forever(ao_i2c_reg_t * r, uint8_t v)
{
    // Assert.

    ao_assert(r);


    // Variables.

    bool R1;
    bool R2;
    bool R3;


    // Ready.

    while (r->con.reg & 0x1F) { }

    r->stat.bits.bcl = 0;

    r->stat.bits.iwcol = 0;

    r->trn.reg = v;

    do
    {
        R1 = ao_i2c_sending(r);

        R2 = r->stat.bits.iwcol ? false : true;

        R3 = r->stat.bits.bcl ? false : true;
    }
    while (R1 && R2 && R3);

    return R2 && R3;
}

// ----------------------------------------------------------------------------

bool ao_i2c_sending(ao_i2c_reg_t * r)
{
    if
    (
        r->stat.bits.tbf    ||  // Transmit buffer full.

        r->stat.bits.trstat     // Transmission in progress.
    )
    {
        return true;
    }

    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------------

bool ao_i2c_start(ao_i2c_reg_t * r, ao_time_t t)
{
    return ao_i2c_start_from(r, t, ao_now());
}

bool ao_i2c_start_from(ao_i2c_reg_t * r, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(r);


    // Variables.

    ao_time_t   e;

    ao_time_t   x;

    bool        R1;
    bool        R2;
    bool        R3;


    // Ready.

    if (t == AO_INFINITY)
    {
        R3 = ao_i2c_start_forever(r);
    }

    else
    {
        do
        {
            e = ao_now();

            x = e - b;

            t = t > x ? t - x : 0;

            b = e;

            R1 = (r->con.reg & 0x1F) ? true : false;
        }
        while (R1 && t > 0);

        if (R1) { }

        else
        {
            r->stat.bits.bcl = 0;

            r->con.bits.sen = 1;

            do
            {
                e = ao_now();

                x = e - b;

                t = t > x ? t - x : 0;

                b = e;

                R1 = r->con.bits.sen ? true : false;

                R2 = r->stat.bits.bcl ? false : true;
            }
            while (R1 && R2 && t > 0);

            if (R2) { }

            else
            {
                R1 = true;
            }
        }

        R3 = !R1;
    }

    return R3;
}

bool ao_i2c_start_forever(ao_i2c_reg_t * r)
{
    // Assert.

    ao_assert(r);


    // Variables.

    bool R1;
    bool R2;


    // Ready.

    while (r->con.reg & 0x1F) { }

    r->stat.bits.bcl = 0;

    r->con.bits.sen = 1;

    do
    {
        R1 = r->con.bits.sen ? true : false;

        R2 = r->stat.bits.bcl ? false : true;
    }
    while (R1 && R2);

    return R2;
}

// ----------------------------------------------------------------------------

bool ao_i2c_stop(ao_i2c_reg_t * r, ao_time_t t)
{
    return ao_i2c_stop_from(r, t, ao_now());
}

bool ao_i2c_stop_from(ao_i2c_reg_t * r, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(r);


    // Variables.

    ao_time_t   e;

    ao_time_t   x;

    bool        R1;
    bool        R2;
    bool        R3;


    // Ready.

    if (t == AO_INFINITY)
    {
        R3 = ao_i2c_stop_forever(r);
    }

    else
    {
        do
        {
            e = ao_now();

            x = e - b;

            t = t > x ? t - x : 0;

            b = e;

            R1 = (r->con.reg & 0x1F) ? true : false;
        }
        while (R1 && t > 0);

        if (R1) { }

        else
        {
            r->stat.bits.bcl = 0;

            r->con.bits.pen = 1;

            do
            {
                e = ao_now();

                x = e - b;

                t = t > x ? t - x : 0;

                b = e;

                R1 = r->con.bits.pen ? true : false;

                R2 = r->stat.bits.bcl ? false : true;
            }
            while (R1 && R2 && t > 0);

            if (R2) { }

            else
            {
                R1 = true;
            }
        }

        R3 = !R1;
    }

    return R3;
}

bool ao_i2c_stop_forever(ao_i2c_reg_t * r)
{
    // Assert.

    ao_assert(r);


    // Variables.

    bool R1;
    bool R2;


    // Ready.

    while (r->con.reg & 0x1F) { }

    r->stat.bits.bcl = 0;

    r->con.bits.pen = 1;

    do
    {
        R1 = r->con.bits.pen ? true : false;

        R2 = r->stat.bits.bcl ? false : true;
    }
    while (R1 && R2);

    return R2;
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32_SPI

#if defined AO_SPI

// ----------------------------------------------------------------------------

void ao_spi_baud(ao_spi_reg_t * r, uint32_t f_pbclk, uint32_t f)
{
    // Assert.

    ao_assert(r);

    ao_assert(f_pbclk > 0);

    ao_assert(f >= ao_spi_baud_min(f_pbclk));

    ao_assert(f <= ao_spi_baud_max(f_pbclk));


    // Ready.

    // If the peripheral bus clock is not an integer multiple of the desired baud rate, we cannot set up the latter exactly.

    // Then, we must ensure, that the actual baud rate does not exceed the desired baud rate.

    r->brg.reg = (f_pbclk - 1) / (2 * f);
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32_UART

#if defined AO_UART

// ----------------------------------------------------------------------------

static  void    ao_uart_ir_rx_1();

static  void    ao_uart_ir_rx_2();

static  void    ao_uart_ir_rx_3();

static  void    ao_uart_ir_rx_4();

static  void    ao_uart_ir_rx_5();

static  void    ao_uart_ir_rx_6();

// ----------------------------------------------------------------------------

static  void    ao_uart_ir_tx_1();

static  void    ao_uart_ir_tx_2();

static  void    ao_uart_ir_tx_3();

static  void    ao_uart_ir_tx_4();

static  void    ao_uart_ir_tx_5();

static  void    ao_uart_ir_tx_6();

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32

// ----------------------------------------------------------------------------

#if defined AO_UART

// ----------------------------------------------------------------------------

void ao_uart_baud(ao_uart_reg_t * r, uint32_t f_pbclk, uint32_t f)
{

#if defined AO_SYS_XC32_PIC32MK_GP                                      ||  \
    defined AO_SYS_XC32_PIC32MX_1XX_XLP                                 ||  \
    defined AO_SYS_XC32_PIC32MZ_DA                                      ||  \
    defined AO_SYS_XC32_PIC32MZ_DAK                                     ||  \
    defined AO_SYS_XC32_PIC32MZ_EF

    // DS80000663.

    // DS80000736.

    // DS80000737.

    // DS80000739.

    // DS80000823.

    // The UART TX Stop bit duration is shorter than expected in High-Speed
    // mode (UxMODE.BRGH = 1) for baud rates less than 7.5 Mbps.

    // Workaround.

    // For baud rates less than 7.5 Mbps, operate the UART in Standard-Speed
    // mode, that is, UxMODE.BRGH = 0.

    // For baud rates greater than 7.5 Mbps, operate the UART in High-Speed
    // mode, that is, UxMODE.BRGH = 1.

    if (f < 7500000UL)
    {
        ao_uart_baud_low(r, f_pbclk, f);
    }

    else

#endif

    if (f <= ao_uart_baud_low_max(f_pbclk))
    {
        ao_uart_baud_low(r, f_pbclk, f);
    }

    else
    {
        ao_uart_baud_high(r, f_pbclk, f);
    }
}

void ao_uart_baud_high(ao_uart_reg_t * r, uint32_t f_pbclk, uint32_t f)
{
    // Assert.

    ao_assert(r);

    ao_assert(f_pbclk > 0);

    ao_assert(f >= ao_uart_baud_high_min(f_pbclk));
    ao_assert(f <= ao_uart_baud_high_max(f_pbclk));


    // Assert.

#if defined AO_SYS_XC32_PIC32MK_GP                                      ||  \
    defined AO_SYS_XC32_PIC32MX_1XX_XLP                                 ||  \
    defined AO_SYS_XC32_PIC32MZ_DA                                      ||  \
    defined AO_SYS_XC32_PIC32MZ_DAK                                     ||  \
    defined AO_SYS_XC32_PIC32MZ_EF

    // DS80000737.

    // DS80000739.

    // DS80000736.

    // DS80000823.

    // DS80000663.

    // The UART TX Stop bit duration is shorter than expected in High-Speed
    // mode (UxMODE.BRGH = 1) for baud rates less than 7.5 Mbps.

    // Workaround.

    // For baud rates less than 7.5 Mbps, operate the UART in Standard-Speed
    // mode, that is, UxMODE.BRGH = 0.

    // For baud rates greater than 7.5 Mbps, operate the UART in High-Speed
    // mode, that is, UxMODE.BRGH = 1.

    ao_assert(f >= 7500000UL);

#endif

#if defined AO_SYS_XC32_PIC32MX_3XX

    // DS80000440.

    // In BRGH = 1 mode, the received data is not sampled in the middle of the
    // bit.

    // This reduces the UART's baud rate mismatch tolerance.

    // Workaround.

    // Use BRGH = 0 mode.

    ao_assert(false);

#endif


    // Variables.

    uint32_t b;


    // Ready.

    // If the peripheral bus clock is not an integer multiple of the desired
    // baud rate, we cannot set up the latter exactly.

    // Then, we must ensure, that the actual baud rate does not exceed the
    // desired baud rate.

    b = (f_pbclk - 1) / (4 * f);

#if defined AO_SYS_XC32_PIC32MX_3XX

    // DS80000440.

    // Using BRG values of 0, 1, or 2 causes the Start bit to be shortened.

    // This results in errors when receiving data.

    // This issue exists for BRGH values of 0 and 1.

    // Workaround.

    // Do not use BRG values of 0, 1, or 2.

    ao_assert(b > 2);

#endif

    r->mode.bits.brgh = 1;

    r->brg.reg = b;
}

void ao_uart_baud_low(ao_uart_reg_t * r, uint32_t f_pbclk, uint32_t f)
{
    // Assert.

    ao_assert(r);

    ao_assert(f_pbclk > 0);

    ao_assert(f >= ao_uart_baud_low_min(f_pbclk));
    ao_assert(f <= ao_uart_baud_low_max(f_pbclk));


    // Variables.

    uint32_t b;


    // Ready.

    // If the peripheral bus clock is not an integer multiple of the desired
    // baud rate, we cannot set up the latter exactly.

    // Then, we must ensure, that the actual baud rate does not exceed the
    // desired baud rate.

    b = (f_pbclk - 1) / (16 * f);

#if defined AO_SYS_XC32_PIC32MX_3XX

    // DS80000440.

    // Using BRG values of 0, 1, or 2 causes the Start bit to be shortened.

    // This results in errors when receiving data.

    // This issue exists for BRGH values of 0 and 1.

    // Workaround.

    // Do not use BRG values of 0, 1, or 2.

    ao_assert(b > 2);

#endif

    r->mode.bits.brgh = 0;

    r->brg.reg = b;
}

// ----------------------------------------------------------------------------

void ao_uart_loopback_disable(ao_uart_reg_t * r)
{
    ao_assert(r);

    r->mode.bits.lpback = 0;
}

void ao_uart_loopback_enable(ao_uart_reg_t * r)
{
    ao_assert(r);

    r->mode.bits.lpback = 1;
}

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#if defined AO_UART_1 && AO_UART_1

// ----------------------------------------------------------------------------

#if AO_UART_ERROR_1

static  ao_uart_error_info_t    ao_uart_error_info_1;

#endif

#if AO_UART_TX_1

static  ao_sem_t                ao_uart_sem_1;

#endif

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_uart_config_1()
{
    ao_uart_config_baud_1();

    ao_uart_config_frame_1();

    ao_uart_config_loopback_1();
}

__attribute__ ((weak))
void ao_uart_config_baud_1()
{
    ao_uart_baud_1(AO_UART_BAUD_1);
}

__attribute__ ((weak))
void ao_uart_config_frame_1()
{
    ao_uart_reg_t * r = ao_uart_reg_1();

    r->mode.bits.pdsel = AO_UART_DATA_BITS_PARITY_1;

    r->mode.bits.stsel = AO_UART_STOP_BITS_1;
}

__attribute__ ((weak))
void ao_uart_config_loopback_1()
{

#if AO_UART_LOOPBACK_1

    ao_uart_loopback_enable_1();

#else

    ao_uart_loopback_disable_1();

#endif

}

// ----------------------------------------------------------------------------

void ao_uart_start_1()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_1();


    // Ready.

    ao_uart_config_1();

#if AO_UART_RX_1

    // DS80000480.

    // The UxSTA.OERR bit does not get cleared on a module reset.

    // If the OERR bit is set and the module is disabled, the OERR bit retains
    // its status even after the UART module is reinitialized.

    // Workaround.

    // The user software must check this bit in the UART module initialization
    // routine and clear it if it is set.

    r->sta.bits.oerr    = 0;

    r->sta.bits.urxisel = 0;
    r->sta.bits.urxen   = 1;

    ao_ir_u1rx_enable();

#endif

#if AO_UART_TX_1

    ao_task_start(&ao_uart_task_1);

#endif

    r->mode.bits.on = 1;
}

void ao_uart_stop_1()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_1();


    // Ready.

    r->mode.bits.on = 0;

#if AO_UART_TX_1

    ao_sem_give(&ao_uart_sem_1, 1);

#endif

#if AO_UART_RX_1

    ao_ir_u1rx_disable();

    r->sta.bits.urxen = 0;

#endif

}

// ----------------------------------------------------------------------------

#if AO_UART_RX_1

// ----------------------------------------------------------------------------

static  uint8_t     ao_uart_in_store_1[AO_UART_FIFO_CAPACITY];

        ao_send_t   ao_uart_in_1 =
{
        .ptr        = ao_uart_in_store_1
};

// ----------------------------------------------------------------------------

void ao_uart_ir_rx_1()
{
    // Variables.

    uint8_t                 c;

    size_t                  n;

    ao_uart_reg_t * const   r = ao_uart_reg_1();

    ao_send_t *     const   s = &ao_uart_in_1;

    uint32_t                t;


    // Ready.

#if AO_UART_ERROR_1

    t = r->sta.reg & AO_UART_ERROR_OVERRUN;

    if (t)
    {
        ao_uart_error_info_1.flags = (ao_uart_error_flags_t) t;

        ao_uart_error_1(&ao_uart_error_info_1);
    }

#endif


    n = 0;

    while (n < AO_UART_FIFO_CAPACITY && r->sta.bits.urxda)
    {
        t = r->sta.reg & (AO_UART_ERROR_FRAMING | AO_UART_ERROR_PARITY);

        c = r->rx.reg;

        if (t)
        {

#if AO_UART_ERROR_1

            ao_uart_error_info_1.flags = (ao_uart_error_flags_t) t;

            ao_uart_error_1(&ao_uart_error_info_1);

#endif

        }

        else
        {
            ao_uart_in_store_1[n] = c;

            n++;
        }
    }

    r->sta.bits.oerr = 0;

    ao_ir_u1rx_reply();

    s->count_max = n;
    s->count_min = n;

    ao_send_try(s);
}

// ----------------------------------------------------------------------------

#endif

#if AO_UART_TX_1

// ----------------------------------------------------------------------------

static  void            ao_uart_task_proc_1(    void * x);

// ----------------------------------------------------------------------------

static  ao_cond_t       ao_uart_cond_1;

static  ao_cond_wait_t  ao_uart_cond_wait_1 =
{
        .cond           = &ao_uart_cond_1
};

// ----------------------------------------------------------------------------

static  uint8_t         ao_uart_out_store_1     [AO_UART_FIFO_CAPACITY];

        ao_recv_t       ao_uart_out_1 =
{
        .count_max      = AO_UART_FIFO_CAPACITY,

        .count_min      = 1,

        .ptr            = ao_uart_out_store_1
};

// ----------------------------------------------------------------------------

static  ao_sem_take_t   ao_uart_sem_take_1 =
{
        .count          = 1,

        .sem            = &ao_uart_sem_1
};

// ----------------------------------------------------------------------------

        ao_task_t       ao_uart_task_1 =
{
        .proc           = ao_uart_task_proc_1
};

// ----------------------------------------------------------------------------

static  ao_async_t *    ao_uart_async_b_store_1 [2] =
{
                        &ao_uart_cond_wait_1.async,

                        &ao_uart_out_1.async
};

static  ao_async_all_t  ao_uart_async_b_1 =
{
        .store          = ao_uart_async_b_store_1,

        .count          = 2
};

static  ao_async_t *    ao_uart_async_a_store_1 [2] =
{
                        &ao_uart_sem_take_1.async,

                        &ao_uart_async_b_1.async
};

static  ao_async_any_t  ao_uart_async_a_1 =
{
        .store          = ao_uart_async_a_store_1,

        .count          = 2
};

// ----------------------------------------------------------------------------

void ao_uart_ir_tx_1()
{
    ao_cond_set(&ao_uart_cond_1);

    ao_ir_u1tx_disable();
}

// ----------------------------------------------------------------------------

void ao_uart_task_proc_1(void * x)
{
    // Variables.

    (void) x;


    // Variables.

    ao_async_any_t *    const   async_a     = &ao_uart_async_a_1;

    ao_async_all_t *    const   async_b     = &ao_uart_async_b_1;

    uint8_t *           const   b           = &ao_uart_out_store_1[0];

    ao_cond_t *         const   cond        = &ao_uart_cond_1;

    ao_cond_wait_t *    const   cond_wait   = &ao_uart_cond_wait_1;

    size_t                      i;

    size_t                      n;

    ao_recv_t *         const   out         = &ao_uart_out_1;

    ao_uart_reg_t *     const   r           = ao_uart_reg_1();

    ao_sem_take_t *     const   sem_take    = &ao_uart_sem_take_1;

    bool                        started;


    // Ready.

    while (1)
    {
        // Start.

        r->sta.bits.utxisel = 1;
        r->sta.bits.utxen   = 1;

        ao_ir_u1tx_enable();


        // Start.

        started = true;

        do
        {
            // Await.

            ao_cond_wait_begin(     cond_wait);

            ao_recv_begin(          out);

            ao_async_all_begin(     async_b);

            ao_sem_take_begin(      sem_take);

            ao_await_any_forever(   async_a);

            ao_sem_take_end(        sem_take);

            ao_async_all_end(       async_b);

            ao_recv_end(            out);

            ao_cond_wait_end(       cond_wait);


            // Stop.

            if (sem_take->result)
            {
                started = false;
            }


            // Transmit.

            else if
            (
                cond_wait->result &&
                out      ->result
            )
            {
                // DS60001107.

                // Section 21.5.2.

                // While the UxTXIF flag bit indicates the status of the
                // UxTXREG register, the UxSTA.TRMT bit indicates the status of
                // the UxTSR register.

                // The UxSTA.TRMT bit is a read-only bit and it is set when the
                // UxTSR register is empty.

                // No interrupt logic is tied to this bit, so the user has to
                // poll this bit to determine if the UxTSR register is empty.

                while (!r->sta.bits.trmt) { }

#if defined AO_SYS_XC32_PIC32MX_3XX                                     ||  \
    defined AO_SYS_XC32_PIC32MX_5XX

                // DS80000440.

                // DS80000480.

                // The TRMT bits is asserted during the stop bit generation,
                // not after the stop bit has been sent.

                // Workaround.

                // Add a half bit time delay after the TRMT bit is asserted.

                ao_spin(ao_nanoseconds(1000000000ULL / (AO_UART_BAUD_1)));

#endif

                ao_cond_clear(cond);

                // DS80000737.

                // In order to avoid a race condition, the interrupt flag
                // should be cleared before writing new data to the transmit
                // register.

                ao_ir_u1tx_reply();

                n = out->count;

                for (i = 0; i < n; i++)
                {
                    r->tx.reg = b[i];
                }

                ao_ir_u1tx_enable();
            }
        }
        while (started);


        // Stop.

        ao_ir_u1tx_disable();

        r->sta.bits.utxen = 0;


        // Stop.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_UART_2 && AO_UART_2

// ----------------------------------------------------------------------------

#if AO_UART_ERROR_2

static  ao_uart_error_info_t    ao_uart_error_info_2;

#endif

#if AO_UART_TX_2

static  ao_sem_t                ao_uart_sem_2;

#endif

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_uart_config_2()
{
    ao_uart_config_baud_2();

    ao_uart_config_frame_2();

    ao_uart_config_loopback_2();
}

__attribute__ ((weak))
void ao_uart_config_baud_2()
{
    ao_uart_baud_2(AO_UART_BAUD_2);
}

__attribute__ ((weak))
void ao_uart_config_frame_2()
{
    ao_uart_reg_t * r = ao_uart_reg_2();

    r->mode.bits.pdsel = AO_UART_DATA_BITS_PARITY_2;

    r->mode.bits.stsel = AO_UART_STOP_BITS_2;
}

__attribute__ ((weak))
void ao_uart_config_loopback_2()
{

#if AO_UART_LOOPBACK_2

    ao_uart_loopback_enable_2();

#else

    ao_uart_loopback_disable_2();

#endif

}

// ----------------------------------------------------------------------------

void ao_uart_start_2()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_2();


    // Ready.

    ao_uart_config_2();

#if AO_UART_RX_2

    // DS80000480.

    // The UxSTA.OERR bit does not get cleared on a module reset.

    // If the OERR bit is set and the module is disabled, the OERR bit retains
    // its status even after the UART module is reinitialized.

    // Workaround.

    // The user software must check this bit in the UART module initialization
    // routine and clear it if it is set.

    r->sta.bits.oerr    = 0;

    r->sta.bits.urxisel = 0;
    r->sta.bits.urxen   = 1;

    ao_ir_u2rx_enable();

#endif

#if AO_UART_TX_2

    ao_task_start(&ao_uart_task_2);

#endif

    r->mode.bits.on = 1;
}

void ao_uart_stop_2()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_2();


    // Ready.

    r->mode.bits.on = 0;

#if AO_UART_TX_2

    ao_sem_give(&ao_uart_sem_2, 1);

#endif

#if AO_UART_RX_2

    ao_ir_u2rx_disable();

    r->sta.bits.urxen = 0;

#endif

}

// ----------------------------------------------------------------------------

#if AO_UART_RX_2

// ----------------------------------------------------------------------------

static  uint8_t     ao_uart_in_store_2[AO_UART_FIFO_CAPACITY];

        ao_send_t   ao_uart_in_2 =
{
        .ptr        = ao_uart_in_store_2
};

// ----------------------------------------------------------------------------

void ao_uart_ir_rx_2()
{
    // Variables.

    uint8_t                 c;

    size_t                  n;

    ao_uart_reg_t * const   r = ao_uart_reg_2();

    ao_send_t *     const   s = &ao_uart_in_2;

    uint32_t                t;


    // Ready.

#if AO_UART_ERROR_2

    t = r->sta.reg & AO_UART_ERROR_OVERRUN;

    if (t)
    {
        ao_uart_error_info_2.flags = (ao_uart_error_flags_t) t;

        ao_uart_error_2(&ao_uart_error_info_2);
    }

#endif


    n = 0;

    while (n < AO_UART_FIFO_CAPACITY && r->sta.bits.urxda)
    {
        t = r->sta.reg & (AO_UART_ERROR_FRAMING | AO_UART_ERROR_PARITY);

        c = r->rx.reg;

        if (t)
        {

#if AO_UART_ERROR_2

            ao_uart_error_info_2.flags = (ao_uart_error_flags_t) t;

            ao_uart_error_2(&ao_uart_error_info_2);

#endif

        }

        else
        {
            ao_uart_in_store_2[n] = c;

            n++;
        }
    }

    r->sta.bits.oerr = 0;

    ao_ir_u2rx_reply();

    s->count_max = n;
    s->count_min = n;

    ao_send_try(s);
}

// ----------------------------------------------------------------------------

#endif

#if AO_UART_TX_2

// ----------------------------------------------------------------------------

static  void            ao_uart_task_proc_2(    void * x);

// ----------------------------------------------------------------------------

static  ao_cond_t       ao_uart_cond_2;

static  ao_cond_wait_t  ao_uart_cond_wait_2 =
{
        .cond           = &ao_uart_cond_2
};

// ----------------------------------------------------------------------------

static  uint8_t         ao_uart_out_store_2     [AO_UART_FIFO_CAPACITY];

        ao_recv_t       ao_uart_out_2 =
{
        .count_max      = AO_UART_FIFO_CAPACITY,

        .count_min      = 1,

        .ptr            = ao_uart_out_store_2
};

// ----------------------------------------------------------------------------

static  ao_sem_take_t   ao_uart_sem_take_2 =
{
        .count          = 1,

        .sem            = &ao_uart_sem_2
};

// ----------------------------------------------------------------------------

        ao_task_t       ao_uart_task_2 =
{
        .proc           = ao_uart_task_proc_2
};

// ----------------------------------------------------------------------------

static  ao_async_t *    ao_uart_async_b_store_2 [2] =
{
                        &ao_uart_cond_wait_2.async,

                        &ao_uart_out_2.async
};

static  ao_async_all_t  ao_uart_async_b_2 =
{
        .store          = ao_uart_async_b_store_2,

        .count          = 2
};

static  ao_async_t *    ao_uart_async_a_store_2 [2] =
{
                        &ao_uart_sem_take_2.async,

                        &ao_uart_async_b_2.async
};

static  ao_async_any_t  ao_uart_async_a_2 =
{
        .store          = ao_uart_async_a_store_2,

        .count          = 2
};

// ----------------------------------------------------------------------------

void ao_uart_ir_tx_2()
{
    ao_cond_set(&ao_uart_cond_2);

    ao_ir_u2tx_disable();
}

// ----------------------------------------------------------------------------

void ao_uart_task_proc_2(void * x)
{
    // Variables.

    (void) x;


    // Variables.

    ao_async_any_t *    const   async_a     = &ao_uart_async_a_2;

    ao_async_all_t *    const   async_b     = &ao_uart_async_b_2;

    uint8_t *           const   b           = &ao_uart_out_store_2[0];

    ao_cond_t *         const   cond        = &ao_uart_cond_2;

    ao_cond_wait_t *    const   cond_wait   = &ao_uart_cond_wait_2;

    size_t                      i;

    size_t                      n;

    ao_recv_t *         const   out         = &ao_uart_out_2;

    ao_uart_reg_t *     const   r           = ao_uart_reg_2();

    ao_sem_take_t *     const   sem_take    = &ao_uart_sem_take_2;

    bool                        started;


    // Ready.

    while (1)
    {
        // Start.

        r->sta.bits.utxisel = 1;
        r->sta.bits.utxen   = 1;

        ao_ir_u2tx_enable();


        // Start.

        started = true;

        do
        {
            // Await.

            ao_cond_wait_begin(     cond_wait);

            ao_recv_begin(          out);

            ao_async_all_begin(     async_b);

            ao_sem_take_begin(      sem_take);

            ao_await_any_forever(   async_a);

            ao_sem_take_end(        sem_take);

            ao_async_all_end(       async_b);

            ao_recv_end(            out);

            ao_cond_wait_end(       cond_wait);


            // Stop.

            if (sem_take->result)
            {
                started = false;
            }


            // Transmit.

            else if
            (
                cond_wait->result &&
                out      ->result
            )
            {
                // DS60001107.

                // Section 21.5.2.

                // While the UxTXIF flag bit indicates the status of the
                // UxTXREG register, the UxSTA.TRMT bit indicates the status of
                // the UxTSR register.

                // The UxSTA.TRMT bit is a read-only bit and it is set when the
                // UxTSR register is empty.

                // No interrupt logic is tied to this bit, so the user has to
                // poll this bit to determine if the UxTSR register is empty.

                while (!r->sta.bits.trmt) { }

#if defined AO_SYS_XC32_PIC32MX_3XX                                     ||  \
    defined AO_SYS_XC32_PIC32MX_5XX

                // DS80000440.

                // DS80000480.

                // The TRMT bits is asserted during the stop bit generation,
                // not after the stop bit has been sent.

                // Workaround.

                // Add a half bit time delay after the TRMT bit is asserted.

                ao_spin(ao_nanoseconds(1000000000ULL / (AO_UART_BAUD_2)));

#endif

                ao_cond_clear(cond);

                // DS80000737.

				// In order to avoid a race condition, the interrupt flag
				// should be cleared before writing new data to the transmit
				// register.

                ao_ir_u2tx_reply();

                n = out->count;

                for (i = 0; i < n; i++)
                {
                    r->tx.reg = b[i];
                }

                ao_ir_u2tx_enable();
            }
        }
        while (started);


        // Stop.

        ao_ir_u2tx_disable();

        r->sta.bits.utxen = 0;


        // Stop.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_UART_3 && AO_UART_3

// ----------------------------------------------------------------------------

#if AO_UART_ERROR_3

static  ao_uart_error_info_t    ao_uart_error_info_3;

#endif

#if AO_UART_TX_3

static  ao_sem_t                ao_uart_sem_3;

#endif

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_uart_config_3()
{
    ao_uart_config_baud_3();

    ao_uart_config_frame_3();

    ao_uart_config_loopback_3();
}

__attribute__ ((weak))
void ao_uart_config_baud_3()
{
    ao_uart_baud_3(AO_UART_BAUD_3);
}

__attribute__ ((weak))
void ao_uart_config_frame_3()
{
    ao_uart_reg_t * r = ao_uart_reg_3();

    r->mode.bits.pdsel = AO_UART_DATA_BITS_PARITY_3;

    r->mode.bits.stsel = AO_UART_STOP_BITS_3;
}

__attribute__ ((weak))
void ao_uart_config_loopback_3()
{

#if AO_UART_LOOPBACK_3

    ao_uart_loopback_enable_3();

#else

    ao_uart_loopback_disable_3();

#endif

}

// ----------------------------------------------------------------------------

void ao_uart_start_3()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_3();


    // Ready.

    ao_uart_config_3();

#if AO_UART_RX_3

    // DS80000480.

    // The UxSTA.OERR bit does not get cleared on a module reset.

    // If the OERR bit is set and the module is disabled, the OERR bit retains
    // its status even after the UART module is reinitialized.

    // Workaround.

    // The user software must check this bit in the UART module initialization
    // routine and clear it if it is set.

    r->sta.bits.oerr    = 0;

    r->sta.bits.urxisel = 0;
    r->sta.bits.urxen   = 1;

    ao_ir_u3rx_enable();

#endif

#if AO_UART_TX_3

    ao_task_start(&ao_uart_task_3);

#endif

    r->mode.bits.on = 1;
}

void ao_uart_stop_3()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_3();


    // Ready.

    r->mode.bits.on = 0;

#if AO_UART_TX_3

    ao_sem_give(&ao_uart_sem_3, 1);

#endif

#if AO_UART_RX_3

    ao_ir_u3rx_disable();

    r->sta.bits.urxen = 0;

#endif

}

// ----------------------------------------------------------------------------

#if AO_UART_RX_3

// ----------------------------------------------------------------------------

static  uint8_t     ao_uart_in_store_3[AO_UART_FIFO_CAPACITY];

        ao_send_t   ao_uart_in_3 =
{
        .ptr        = ao_uart_in_store_3
};

// ----------------------------------------------------------------------------

void ao_uart_ir_rx_3()
{
    // Variables.

    uint8_t                 c;

    size_t                  n;

    ao_uart_reg_t * const   r = ao_uart_reg_3();

    ao_send_t *     const   s = &ao_uart_in_3;

    uint32_t                t;


    // Ready.

#if AO_UART_ERROR_3

    t = r->sta.reg & AO_UART_ERROR_OVERRUN;

    if (t)
    {
        ao_uart_error_info_3.flags = (ao_uart_error_flags_t) t;

        ao_uart_error_3(&ao_uart_error_info_3);
    }

#endif


    n = 0;

    while (n < AO_UART_FIFO_CAPACITY && r->sta.bits.urxda)
    {
        t = r->sta.reg & (AO_UART_ERROR_FRAMING | AO_UART_ERROR_PARITY);

        c = r->rx.reg;

        if (t)
        {

#if AO_UART_ERROR_3

            ao_uart_error_info_3.flags = (ao_uart_error_flags_t) t;

            ao_uart_error_3(&ao_uart_error_info_3);

#endif

        }

        else
        {
            ao_uart_in_store_3[n] = c;

            n++;
        }
    }

    r->sta.bits.oerr = 0;

    ao_ir_u3rx_reply();

    s->count_max = n;
    s->count_min = n;

    ao_send_try(s);
}

// ----------------------------------------------------------------------------

#endif

#if AO_UART_TX_3

// ----------------------------------------------------------------------------

static  void            ao_uart_task_proc_3(    void * x);

// ----------------------------------------------------------------------------

static  ao_cond_t       ao_uart_cond_3;

static  ao_cond_wait_t  ao_uart_cond_wait_3 =
{
        .cond           = &ao_uart_cond_3
};

// ----------------------------------------------------------------------------

static  uint8_t         ao_uart_out_store_3     [AO_UART_FIFO_CAPACITY];

        ao_recv_t       ao_uart_out_3 =
{
        .count_max      = AO_UART_FIFO_CAPACITY,

        .count_min      = 1,

        .ptr            = ao_uart_out_store_3
};

// ----------------------------------------------------------------------------

static  ao_sem_take_t   ao_uart_sem_take_3 =
{
        .count          = 1,

        .sem            = &ao_uart_sem_3
};

// ----------------------------------------------------------------------------

        ao_task_t       ao_uart_task_3 =
{
        .proc           = ao_uart_task_proc_3
};

// ----------------------------------------------------------------------------

static  ao_async_t *    ao_uart_async_b_store_3 [2] =
{
                        &ao_uart_cond_wait_3.async,

                        &ao_uart_out_3.async
};

static  ao_async_all_t  ao_uart_async_b_3 =
{
        .store          = ao_uart_async_b_store_3,

        .count          = 2
};

static  ao_async_t *    ao_uart_async_a_store_3 [2] =
{
                        &ao_uart_sem_take_3.async,

                        &ao_uart_async_b_3.async
};

static  ao_async_any_t  ao_uart_async_a_3 =
{
        .store          = ao_uart_async_a_store_3,

        .count          = 2
};

// ----------------------------------------------------------------------------

void ao_uart_ir_tx_3()
{
    ao_cond_set(&ao_uart_cond_3);

    ao_ir_u3tx_disable();
}

// ----------------------------------------------------------------------------

void ao_uart_task_proc_3(void * x)
{
    // Variables.

    (void) x;


    // Variables.

    ao_async_any_t *    const   async_a     = &ao_uart_async_a_3;

    ao_async_all_t *    const   async_b     = &ao_uart_async_b_3;

    uint8_t *           const   b           = &ao_uart_out_store_3[0];

    ao_cond_t *         const   cond        = &ao_uart_cond_3;

    ao_cond_wait_t *    const   cond_wait   = &ao_uart_cond_wait_3;

    size_t                      i;

    size_t                      n;

    ao_recv_t *         const   out         = &ao_uart_out_3;

    ao_uart_reg_t *     const   r           = ao_uart_reg_3();

    ao_sem_take_t *     const   sem_take    = &ao_uart_sem_take_3;

    bool                        started;


    // Ready.

    while (1)
    {
        // Start.

        r->sta.bits.utxisel = 1;
        r->sta.bits.utxen   = 1;

        ao_ir_u3tx_enable();


        // Start.

        started = true;

        do
        {
            // Await.

            ao_cond_wait_begin(     cond_wait);

            ao_recv_begin(          out);

            ao_async_all_begin(     async_b);

            ao_sem_take_begin(      sem_take);

            ao_await_any_forever(   async_a);

            ao_sem_take_end(        sem_take);

            ao_async_all_end(       async_b);

            ao_recv_end(            out);

            ao_cond_wait_end(       cond_wait);


            // Stop.

            if (sem_take->result)
            {
                started = false;
            }


            // Transmit.

            else if
            (
                cond_wait->result &&
                out      ->result
            )
            {
                // DS60001107.

                // Section 21.5.2.

                // While the UxTXIF flag bit indicates the status of the
                // UxTXREG register, the UxSTA.TRMT bit indicates the status of
                // the UxTSR register.

                // The UxSTA.TRMT bit is a read-only bit and it is set when the
                // UxTSR register is empty.

                // No interrupt logic is tied to this bit, so the user has to
                // poll this bit to determine if the UxTSR register is empty.

                while (!r->sta.bits.trmt) { }

#if defined AO_SYS_XC32_PIC32MX_3XX                                     ||  \
    defined AO_SYS_XC32_PIC32MX_5XX

                // DS80000440.

                // DS80000480.

                // The TRMT bits is asserted during the stop bit generation,
                // not after the stop bit has been sent.

                // Workaround.

                // Add a half bit time delay after the TRMT bit is asserted.

                ao_spin(ao_nanoseconds(1000000000ULL / (AO_UART_BAUD_3)));

#endif

                ao_cond_clear(cond);

                // DS80000737.

				// In order to avoid a race condition, the interrupt flag
				// should be cleared before writing new data to the transmit
				// register.

                ao_ir_u3tx_reply();

                n = out->count;

                for (i = 0; i < n; i++)
                {
                    r->tx.reg = b[i];
                }

                ao_ir_u3tx_enable();
            }
        }
        while (started);


        // Stop.

        ao_ir_u3tx_disable();

        r->sta.bits.utxen = 0;


        // Stop.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_UART_4 && AO_UART_4

// ----------------------------------------------------------------------------

#if AO_UART_ERROR_4

static  ao_uart_error_info_t    ao_uart_error_info_4;

#endif

#if AO_UART_TX_4

static  ao_sem_t                ao_uart_sem_4;

#endif

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_uart_config_4()
{
    ao_uart_config_baud_4();

    ao_uart_config_frame_4();

    ao_uart_config_loopback_4();
}

__attribute__ ((weak))
void ao_uart_config_baud_4()
{
    ao_uart_baud_4(AO_UART_BAUD_4);
}

__attribute__ ((weak))
void ao_uart_config_frame_4()
{
    ao_uart_reg_t * r = ao_uart_reg_4();

    r->mode.bits.pdsel = AO_UART_DATA_BITS_PARITY_4;

    r->mode.bits.stsel = AO_UART_STOP_BITS_4;
}

__attribute__ ((weak))
void ao_uart_config_loopback_4()
{

#if AO_UART_LOOPBACK_4

    ao_uart_loopback_enable_4();

#else

    ao_uart_loopback_disable_4();

#endif

}

// ----------------------------------------------------------------------------

void ao_uart_start_4()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_4();


    // Ready.

    ao_uart_config_4();

#if AO_UART_RX_4

    // DS80000480.

    // The UxSTA.OERR bit does not get cleared on a module reset.

    // If the OERR bit is set and the module is disabled, the OERR bit retains
    // its status even after the UART module is reinitialized.

    // Workaround.

    // The user software must check this bit in the UART module initialization
    // routine and clear it if it is set.

    r->sta.bits.oerr    = 0;

    r->sta.bits.urxisel = 0;
    r->sta.bits.urxen   = 1;

    ao_ir_u4rx_enable();

#endif

#if AO_UART_TX_4

    ao_task_start(&ao_uart_task_4);

#endif

    r->mode.bits.on = 1;
}

void ao_uart_stop_4()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_4();


    // Ready.

    r->mode.bits.on = 0;

#if AO_UART_TX_4

    ao_sem_give(&ao_uart_sem_4, 1);

#endif

#if AO_UART_RX_4

    ao_ir_u4rx_disable();

    r->sta.bits.urxen = 0;

#endif

}

// ----------------------------------------------------------------------------

#if AO_UART_RX_4

// ----------------------------------------------------------------------------

static  uint8_t     ao_uart_in_store_4[AO_UART_FIFO_CAPACITY];

        ao_send_t   ao_uart_in_4 =
{
        .ptr        = ao_uart_in_store_4
};

// ----------------------------------------------------------------------------

void ao_uart_ir_rx_4()
{
    // Variables.

    uint8_t                 c;

    size_t                  n;

    ao_uart_reg_t * const   r = ao_uart_reg_4();

    ao_send_t *     const   s = &ao_uart_in_4;

    uint32_t                t;


    // Ready.

#if AO_UART_ERROR_4

    t = r->sta.reg & AO_UART_ERROR_OVERRUN;

    if (t)
    {
        ao_uart_error_info_4.flags = (ao_uart_error_flags_t) t;

        ao_uart_error_4(&ao_uart_error_info_4);
    }

#endif


    n = 0;

    while (n < AO_UART_FIFO_CAPACITY && r->sta.bits.urxda)
    {
        t = r->sta.reg & (AO_UART_ERROR_FRAMING | AO_UART_ERROR_PARITY);

        c = r->rx.reg;

        if (t)
        {

#if AO_UART_ERROR_4

            ao_uart_error_info_4.flags = (ao_uart_error_flags_t) t;

            ao_uart_error_4(&ao_uart_error_info_4);

#endif

        }

        else
        {
            ao_uart_in_store_4[n] = c;

            n++;
        }
    }

    r->sta.bits.oerr = 0;

    ao_ir_u4rx_reply();

    s->count_max = n;
    s->count_min = n;

    ao_send_try(s);
}

// ----------------------------------------------------------------------------

#endif

#if AO_UART_TX_4

// ----------------------------------------------------------------------------

static  void            ao_uart_task_proc_4(    void * x);

// ----------------------------------------------------------------------------

static  ao_cond_t       ao_uart_cond_4;

static  ao_cond_wait_t  ao_uart_cond_wait_4 =
{
        .cond           = &ao_uart_cond_4
};

// ----------------------------------------------------------------------------

static  uint8_t         ao_uart_out_store_4     [AO_UART_FIFO_CAPACITY];

        ao_recv_t       ao_uart_out_4 =
{
        .count_max      = AO_UART_FIFO_CAPACITY,

        .count_min      = 1,

        .ptr            = ao_uart_out_store_4
};

// ----------------------------------------------------------------------------

static  ao_sem_take_t   ao_uart_sem_take_4 =
{
        .count          = 1,

        .sem            = &ao_uart_sem_4
};

// ----------------------------------------------------------------------------

        ao_task_t       ao_uart_task_4 =
{
        .proc           = ao_uart_task_proc_4
};

// ----------------------------------------------------------------------------

static  ao_async_t *    ao_uart_async_b_store_4 [2] =
{
                        &ao_uart_cond_wait_4.async,

                        &ao_uart_out_4.async
};

static  ao_async_all_t  ao_uart_async_b_4 =
{
        .store          = ao_uart_async_b_store_4,

        .count          = 2
};

static  ao_async_t *    ao_uart_async_a_store_4 [2] =
{
                        &ao_uart_sem_take_4.async,

                        &ao_uart_async_b_4.async
};

static  ao_async_any_t  ao_uart_async_a_4 =
{
        .store          = ao_uart_async_a_store_4,

        .count          = 2
};

// ----------------------------------------------------------------------------

void ao_uart_ir_tx_4()
{
    ao_cond_set(&ao_uart_cond_4);

    ao_ir_u4tx_disable();
}

// ----------------------------------------------------------------------------

void ao_uart_task_proc_4(void * x)
{
    // Variables.

    (void) x;


    // Variables.

    ao_async_any_t *    const   async_a     = &ao_uart_async_a_4;

    ao_async_all_t *    const   async_b     = &ao_uart_async_b_4;

    uint8_t *           const   b           = &ao_uart_out_store_4[0];

    ao_cond_t *         const   cond        = &ao_uart_cond_4;

    ao_cond_wait_t *    const   cond_wait   = &ao_uart_cond_wait_4;

    size_t                      i;

    size_t                      n;

    ao_recv_t *         const   out         = &ao_uart_out_4;

    ao_uart_reg_t *     const   r           = ao_uart_reg_4();

    ao_sem_take_t *     const   sem_take    = &ao_uart_sem_take_4;

    bool                        started;


    // Ready.

    while (1)
    {
        // Start.

        r->sta.bits.utxisel = 1;
        r->sta.bits.utxen   = 1;

        ao_ir_u4tx_enable();


        // Start.

        started = true;

        do
        {
            // Await.

            ao_cond_wait_begin(     cond_wait);

            ao_recv_begin(          out);

            ao_async_all_begin(     async_b);

            ao_sem_take_begin(      sem_take);

            ao_await_any_forever(   async_a);

            ao_sem_take_end(        sem_take);

            ao_async_all_end(       async_b);

            ao_recv_end(            out);

            ao_cond_wait_end(       cond_wait);


            // Stop.

            if (sem_take->result)
            {
                started = false;
            }


            // Transmit.

            else if
            (
                cond_wait->result &&
                out      ->result
            )
            {
                // DS60001107.

                // Section 21.5.2.

                // While the UxTXIF flag bit indicates the status of the
                // UxTXREG register, the UxSTA.TRMT bit indicates the status of
                // the UxTSR register.

                // The UxSTA.TRMT bit is a read-only bit and it is set when the
                // UxTSR register is empty.

                // No interrupt logic is tied to this bit, so the user has to
                // poll this bit to determine if the UxTSR register is empty.

                while (!r->sta.bits.trmt) { }

#if defined AO_SYS_XC32_PIC32MX_3XX                                     ||  \
    defined AO_SYS_XC32_PIC32MX_5XX

                // DS80000440.

                // DS80000480.

                // The TRMT bits is asserted during the stop bit generation,
                // not after the stop bit has been sent.

                // Workaround.

                // Add a half bit time delay after the TRMT bit is asserted.

                ao_spin(ao_nanoseconds(1000000000ULL / (AO_UART_BAUD_4)));

#endif

                ao_cond_clear(cond);

                // DS80000737.

				// In order to avoid a race condition, the interrupt flag
				// should be cleared before writing new data to the transmit
				// register.

                ao_ir_u4tx_reply();

                n = out->count;

                for (i = 0; i < n; i++)
                {
                    r->tx.reg = b[i];
                }

                ao_ir_u4tx_enable();
            }
        }
        while (started);


        // Stop.

        ao_ir_u4tx_disable();

        r->sta.bits.utxen = 0;


        // Stop.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_UART_5 && AO_UART_5

// ----------------------------------------------------------------------------

#if AO_UART_ERROR_5

static  ao_uart_error_info_t    ao_uart_error_info_5;

#endif

#if AO_UART_TX_5

static  ao_sem_t                ao_uart_sem_5;

#endif

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_uart_config_5()
{
    ao_uart_config_baud_5();

    ao_uart_config_frame_5();

    ao_uart_config_loopback_5();
}

__attribute__ ((weak))
void ao_uart_config_baud_5()
{
    ao_uart_baud_5(AO_UART_BAUD_5);
}

__attribute__ ((weak))
void ao_uart_config_frame_5()
{
    ao_uart_reg_t * r = ao_uart_reg_5();

    r->mode.bits.pdsel = AO_UART_DATA_BITS_PARITY_5;

    r->mode.bits.stsel = AO_UART_STOP_BITS_5;
}

__attribute__ ((weak))
void ao_uart_config_loopback_5()
{

#if AO_UART_LOOPBACK_5

    ao_uart_loopback_enable_5();

#else

    ao_uart_loopback_disable_5();

#endif

}

// ----------------------------------------------------------------------------

void ao_uart_start_5()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_5();


    // Ready.

    ao_uart_config_5();

#if AO_UART_RX_5

    // DS80000480.

    // The UxSTA.OERR bit does not get cleared on a module reset.

    // If the OERR bit is set and the module is disabled, the OERR bit retains
    // its status even after the UART module is reinitialized.

    // Workaround.

    // The user software must check this bit in the UART module initialization
    // routine and clear it if it is set.

    r->sta.bits.oerr    = 0;

    r->sta.bits.urxisel = 0;
    r->sta.bits.urxen   = 1;

    ao_ir_u5rx_enable();

#endif

#if AO_UART_TX_5

    ao_task_start(&ao_uart_task_5);

#endif

    r->mode.bits.on = 1;
}

void ao_uart_stop_5()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_5();


    // Ready.

    r->mode.bits.on = 0;

#if AO_UART_TX_5

    ao_sem_give(&ao_uart_sem_5, 1);

#endif

#if AO_UART_RX_5

    ao_ir_u5rx_disable();

    r->sta.bits.urxen = 0;

#endif

}

// ----------------------------------------------------------------------------

#if AO_UART_RX_5

// ----------------------------------------------------------------------------

static  uint8_t     ao_uart_in_store_5[AO_UART_FIFO_CAPACITY];

        ao_send_t   ao_uart_in_5 =
{
        .ptr        = ao_uart_in_store_5
};

// ----------------------------------------------------------------------------

void ao_uart_ir_rx_5()
{
    // Variables.

    uint8_t                 c;

    size_t                  n;

    ao_uart_reg_t * const   r = ao_uart_reg_5();

    ao_send_t *     const   s = &ao_uart_in_5;

    uint32_t                t;


    // Ready.

#if AO_UART_ERROR_5

    t = r->sta.reg & AO_UART_ERROR_OVERRUN;

    if (t)
    {
        ao_uart_error_info_5.flags = (ao_uart_error_flags_t) t;

        ao_uart_error_5(&ao_uart_error_info_5);
    }

#endif


    n = 0;

    while (n < AO_UART_FIFO_CAPACITY && r->sta.bits.urxda)
    {
        t = r->sta.reg & (AO_UART_ERROR_FRAMING | AO_UART_ERROR_PARITY);

        c = r->rx.reg;

        if (t)
        {

#if AO_UART_ERROR_5

            ao_uart_error_info_5.flags = (ao_uart_error_flags_t) t;

            ao_uart_error_5(&ao_uart_error_info_5);

#endif

        }

        else
        {
            ao_uart_in_store_5[n] = c;

            n++;
        }
    }

    r->sta.bits.oerr = 0;

    ao_ir_u5rx_reply();

    s->count_max = n;
    s->count_min = n;

    ao_send_try(s);
}

// ----------------------------------------------------------------------------

#endif

#if AO_UART_TX_5

// ----------------------------------------------------------------------------

static  void            ao_uart_task_proc_5(    void * x);

// ----------------------------------------------------------------------------

static  ao_cond_t       ao_uart_cond_5;

static  ao_cond_wait_t  ao_uart_cond_wait_5 =
{
        .cond           = &ao_uart_cond_5
};

// ----------------------------------------------------------------------------

static  uint8_t         ao_uart_out_store_5     [AO_UART_FIFO_CAPACITY];

        ao_recv_t       ao_uart_out_5 =
{
        .count_max      = AO_UART_FIFO_CAPACITY,

        .count_min      = 1,

        .ptr            = ao_uart_out_store_5
};

// ----------------------------------------------------------------------------

static  ao_sem_take_t   ao_uart_sem_take_5 =
{
        .count          = 1,

        .sem            = &ao_uart_sem_5
};

// ----------------------------------------------------------------------------

        ao_task_t       ao_uart_task_5 =
{
        .proc           = ao_uart_task_proc_5
};

// ----------------------------------------------------------------------------

static  ao_async_t *    ao_uart_async_b_store_5 [2] =
{
                        &ao_uart_cond_wait_5.async,

                        &ao_uart_out_5.async
};

static  ao_async_all_t  ao_uart_async_b_5 =
{
        .store          = ao_uart_async_b_store_5,

        .count          = 2
};

static  ao_async_t *    ao_uart_async_a_store_5 [2] =
{
                        &ao_uart_sem_take_5.async,

                        &ao_uart_async_b_5.async
};

static  ao_async_any_t  ao_uart_async_a_5 =
{
        .store          = ao_uart_async_a_store_5,

        .count          = 2
};

// ----------------------------------------------------------------------------

void ao_uart_ir_tx_5()
{
    ao_cond_set(&ao_uart_cond_5);

    ao_ir_u5tx_disable();
}

// ----------------------------------------------------------------------------

void ao_uart_task_proc_5(void * x)
{
    // Variables.

    (void) x;


    // Variables.

    ao_async_any_t *    const   async_a     = &ao_uart_async_a_5;

    ao_async_all_t *    const   async_b     = &ao_uart_async_b_5;

    uint8_t *           const   b           = &ao_uart_out_store_5[0];

    ao_cond_t *         const   cond        = &ao_uart_cond_5;

    ao_cond_wait_t *    const   cond_wait   = &ao_uart_cond_wait_5;

    size_t                      i;

    size_t                      n;

    ao_recv_t *         const   out         = &ao_uart_out_5;

    ao_uart_reg_t *     const   r           = ao_uart_reg_5();

    ao_sem_take_t *     const   sem_take    = &ao_uart_sem_take_5;

    bool                        started;


    // Ready.

    while (1)
    {
        // Start.

        r->sta.bits.utxisel = 1;
        r->sta.bits.utxen   = 1;

        ao_ir_u5tx_enable();


        // Start.

        started = true;

        do
        {
            // Await.

            ao_cond_wait_begin(     cond_wait);

            ao_recv_begin(          out);

            ao_async_all_begin(     async_b);

            ao_sem_take_begin(      sem_take);

            ao_await_any_forever(   async_a);

            ao_sem_take_end(        sem_take);

            ao_async_all_end(       async_b);

            ao_recv_end(            out);

            ao_cond_wait_end(       cond_wait);


            // Stop.

            if (sem_take->result)
            {
                started = false;
            }


            // Transmit.

            else if
            (
                cond_wait->result &&
                out      ->result
            )
            {
                // DS60001107.

                // Section 21.5.2.

                // While the UxTXIF flag bit indicates the status of the
                // UxTXREG register, the UxSTA.TRMT bit indicates the status of
                // the UxTSR register.

                // The UxSTA.TRMT bit is a read-only bit and it is set when the
                // UxTSR register is empty.

                // No interrupt logic is tied to this bit, so the user has to
                // poll this bit to determine if the UxTSR register is empty.

                while (!r->sta.bits.trmt) { }

#if defined AO_SYS_XC32_PIC32MX_3XX                                     ||  \
    defined AO_SYS_XC32_PIC32MX_5XX

                // DS80000440.

                // DS80000480.

                // The TRMT bits is asserted during the stop bit generation,
                // not after the stop bit has been sent.

                // Workaround.

                // Add a half bit time delay after the TRMT bit is asserted.

                ao_spin(ao_nanoseconds(1000000000ULL / (AO_UART_BAUD_5)));

#endif

                ao_cond_clear(cond);

                // DS80000737.

				// In order to avoid a race condition, the interrupt flag
				// should be cleared before writing new data to the transmit
				// register.

                ao_ir_u5tx_reply();

                n = out->count;

                for (i = 0; i < n; i++)
                {
                    r->tx.reg = b[i];
                }

                ao_ir_u5tx_enable();
            }
        }
        while (started);


        // Stop.

        ao_ir_u5tx_disable();

        r->sta.bits.utxen = 0;


        // Stop.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_UART_6 && AO_UART_6

// ----------------------------------------------------------------------------

#if AO_UART_ERROR_6

static  ao_uart_error_info_t    ao_uart_error_info_6;

#endif

#if AO_UART_TX_6

static  ao_sem_t                ao_uart_sem_6;

#endif

// ----------------------------------------------------------------------------

__attribute__ ((weak))
void ao_uart_config_6()
{
    ao_uart_config_baud_6();

    ao_uart_config_frame_6();

    ao_uart_config_loopback_6();
}

__attribute__ ((weak))
void ao_uart_config_baud_6()
{
    ao_uart_baud_6(AO_UART_BAUD_6);
}

__attribute__ ((weak))
void ao_uart_config_frame_6()
{
    ao_uart_reg_t * r = ao_uart_reg_6();

    r->mode.bits.pdsel = AO_UART_DATA_BITS_PARITY_6;

    r->mode.bits.stsel = AO_UART_STOP_BITS_6;
}

__attribute__ ((weak))
void ao_uart_config_loopback_6()
{

#if AO_UART_LOOPBACK_6

    ao_uart_loopback_enable_6();

#else

    ao_uart_loopback_disable_6();

#endif

}

// ----------------------------------------------------------------------------

void ao_uart_start_6()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_6();


    // Ready.

    ao_uart_config_6();

#if AO_UART_RX_6

    // DS80000480.

    // The UxSTA.OERR bit does not get cleared on a module reset.

    // If the OERR bit is set and the module is disabled, the OERR bit retains
    // its status even after the UART module is reinitialized.

    // Workaround.

    // The user software must check this bit in the UART module initialization
    // routine and clear it if it is set.

    r->sta.bits.oerr    = 0;

    r->sta.bits.urxisel = 0;
    r->sta.bits.urxen   = 1;

    ao_ir_u6rx_enable();

#endif

#if AO_UART_TX_6

    ao_task_start(&ao_uart_task_6);

#endif

    r->mode.bits.on = 1;
}

void ao_uart_stop_6()
{
    // Variables.

    ao_uart_reg_t * r = ao_uart_reg_6();


    // Ready.

    r->mode.bits.on = 0;

#if AO_UART_TX_6

    ao_sem_give(&ao_uart_sem_6, 1);

#endif

#if AO_UART_RX_6

    ao_ir_u6rx_disable();

    r->sta.bits.urxen = 0;

#endif

}

// ----------------------------------------------------------------------------

#if AO_UART_RX_6

// ----------------------------------------------------------------------------

static  uint8_t     ao_uart_in_store_6[AO_UART_FIFO_CAPACITY];

        ao_send_t   ao_uart_in_6 =
{
        .ptr        = ao_uart_in_store_6
};

// ----------------------------------------------------------------------------

void ao_uart_ir_rx_6()
{
    // Variables.

    uint8_t                 c;

    size_t                  n;

    ao_uart_reg_t * const   r = ao_uart_reg_6();

    ao_send_t *     const   s = &ao_uart_in_6;

    uint32_t                t;


    // Ready.

#if AO_UART_ERROR_6

    t = r->sta.reg & AO_UART_ERROR_OVERRUN;

    if (t)
    {
        ao_uart_error_info_6.flags = (ao_uart_error_flags_t) t;

        ao_uart_error_6(&ao_uart_error_info_6);
    }

#endif


    n = 0;

    while (n < AO_UART_FIFO_CAPACITY && r->sta.bits.urxda)
    {
        t = r->sta.reg & (AO_UART_ERROR_FRAMING | AO_UART_ERROR_PARITY);

        c = r->rx.reg;

        if (t)
        {

#if AO_UART_ERROR_6

            ao_uart_error_info_6.flags = (ao_uart_error_flags_t) t;

            ao_uart_error_6(&ao_uart_error_info_6);

#endif

        }

        else
        {
            ao_uart_in_store_6[n] = c;

            n++;
        }
    }

    r->sta.bits.oerr = 0;

    ao_ir_u6rx_reply();

    s->count_max = n;
    s->count_min = n;

    ao_send_try(s);
}

// ----------------------------------------------------------------------------

#endif

#if AO_UART_TX_6

// ----------------------------------------------------------------------------

static  void            ao_uart_task_proc_6(    void * x);

// ----------------------------------------------------------------------------

static  ao_cond_t       ao_uart_cond_6;

static  ao_cond_wait_t  ao_uart_cond_wait_6 =
{
        .cond           = &ao_uart_cond_6
};

// ----------------------------------------------------------------------------

static  uint8_t         ao_uart_out_store_6     [AO_UART_FIFO_CAPACITY];

        ao_recv_t       ao_uart_out_6 =
{
        .count_max      = AO_UART_FIFO_CAPACITY,

        .count_min      = 1,

        .ptr            = ao_uart_out_store_6
};

// ----------------------------------------------------------------------------

static  ao_sem_take_t   ao_uart_sem_take_6 =
{
        .count          = 1,

        .sem            = &ao_uart_sem_6
};

// ----------------------------------------------------------------------------

        ao_task_t       ao_uart_task_6 =
{
        .proc           = ao_uart_task_proc_6
};

// ----------------------------------------------------------------------------

static  ao_async_t *    ao_uart_async_b_store_6 [2] =
{
                        &ao_uart_cond_wait_6.async,

                        &ao_uart_out_6.async
};

static  ao_async_all_t  ao_uart_async_b_6 =
{
        .store          = ao_uart_async_b_store_6,

        .count          = 2
};

static  ao_async_t *    ao_uart_async_a_store_6 [2] =
{
                        &ao_uart_sem_take_6.async,

                        &ao_uart_async_b_6.async
};

static  ao_async_any_t  ao_uart_async_a_6 =
{
        .store          = ao_uart_async_a_store_6,

        .count          = 2
};

// ----------------------------------------------------------------------------

void ao_uart_ir_tx_6()
{
    ao_cond_set(&ao_uart_cond_6);

    ao_ir_u6tx_disable();
}

// ----------------------------------------------------------------------------

void ao_uart_task_proc_6(void * x)
{
    // Variables.

    (void) x;


    // Variables.

    ao_async_any_t *    const   async_a     = &ao_uart_async_a_6;

    ao_async_all_t *    const   async_b     = &ao_uart_async_b_6;

    uint8_t *           const   b           = &ao_uart_out_store_6[0];

    ao_cond_t *         const   cond        = &ao_uart_cond_6;

    ao_cond_wait_t *    const   cond_wait   = &ao_uart_cond_wait_6;

    size_t                      i;

    size_t                      n;

    ao_recv_t *         const   out         = &ao_uart_out_6;

    ao_uart_reg_t *     const   r           = ao_uart_reg_6();

    ao_sem_take_t *     const   sem_take    = &ao_uart_sem_take_6;

    bool                        started;


    // Ready.

    while (1)
    {
        // Start.

        r->sta.bits.utxisel = 1;
        r->sta.bits.utxen   = 1;

        ao_ir_u6tx_enable();


        // Start.

        started = true;

        do
        {
            // Await.

            ao_cond_wait_begin(     cond_wait);

            ao_recv_begin(          out);

            ao_async_all_begin(     async_b);

            ao_sem_take_begin(      sem_take);

            ao_await_any_forever(   async_a);

            ao_sem_take_end(        sem_take);

            ao_async_all_end(       async_b);

            ao_recv_end(            out);

            ao_cond_wait_end(       cond_wait);


            // Stop.

            if (sem_take->result)
            {
                started = false;
            }


            // Transmit.

            else if
            (
                cond_wait->result &&
                out      ->result
            )
            {
                // DS60001107.

                // Section 21.5.2.

                // While the UxTXIF flag bit indicates the status of the
                // UxTXREG register, the UxSTA.TRMT bit indicates the status of
                // the UxTSR register.

                // The UxSTA.TRMT bit is a read-only bit and it is set when the
                // UxTSR register is empty.

                // No interrupt logic is tied to this bit, so the user has to
                // poll this bit to determine if the UxTSR register is empty.

                while (!r->sta.bits.trmt) { }

#if defined AO_SYS_XC32_PIC32MX_3XX                                     ||  \
    defined AO_SYS_XC32_PIC32MX_5XX

                // DS80000440.

                // DS80000480.

                // The TRMT bits is asserted during the stop bit generation,
                // not after the stop bit has been sent.

                // Workaround.

                // Add a half bit time delay after the TRMT bit is asserted.

                ao_spin(ao_nanoseconds(1000000000ULL / (AO_UART_BAUD_6)));

#endif

                ao_cond_clear(cond);

                // DS80000737.

				// In order to avoid a race condition, the interrupt flag
				// should be cleared before writing new data to the transmit
				// register.

                ao_ir_u6tx_reply();

                n = out->count;

                for (i = 0; i < n; i++)
                {
                    r->tx.reg = b[i];
                }

                ao_ir_u6tx_enable();
            }
        }
        while (started);


        // Stop.

        ao_ir_u6tx_disable();

        r->sta.bits.utxen = 0;


        // Stop.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#endif

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32MK

#if defined AO_UART_1 && AO_UART_1 && AO_UART_RX_1

// ----------------------------------------------------------------------------

AO_IR_U1RX_ATTRIBUTE
void ao_ir_u1rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_1);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_1 && AO_UART_1 && AO_UART_TX_1

// ----------------------------------------------------------------------------

AO_IR_U1TX_ATTRIBUTE
void ao_ir_u1tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_1);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_2 && AO_UART_2 && AO_UART_RX_2

// ----------------------------------------------------------------------------

AO_IR_U2RX_ATTRIBUTE
void ao_ir_u2rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_2);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_2 && AO_UART_2 && AO_UART_TX_2

// ----------------------------------------------------------------------------

AO_IR_U2TX_ATTRIBUTE
void ao_ir_u2tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_2);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_3 && AO_UART_3 && AO_UART_RX_3

// ----------------------------------------------------------------------------

AO_IR_U3RX_ATTRIBUTE
void ao_ir_u3rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_3);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_3 && AO_UART_3 && AO_UART_TX_3

// ----------------------------------------------------------------------------

AO_IR_U3TX_ATTRIBUTE
void ao_ir_u3tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_3);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_4 && AO_UART_4 && AO_UART_RX_4

// ----------------------------------------------------------------------------

AO_IR_U4RX_ATTRIBUTE
void ao_ir_u4rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_4);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_4 && AO_UART_4 && AO_UART_TX_4

// ----------------------------------------------------------------------------

AO_IR_U4TX_ATTRIBUTE
void ao_ir_u4tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_4);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_5 && AO_UART_5 && AO_UART_RX_5

// ----------------------------------------------------------------------------

AO_IR_U5RX_ATTRIBUTE
void ao_ir_u5rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_5);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_5 && AO_UART_5 && AO_UART_TX_5

// ----------------------------------------------------------------------------

AO_IR_U5TX_ATTRIBUTE
void ao_ir_u5tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_5);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_6 && AO_UART_6 && AO_UART_RX_6

// ----------------------------------------------------------------------------

AO_IR_U6RX_ATTRIBUTE
void ao_ir_u6rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_6);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_6 && AO_UART_6 && AO_UART_TX_6

// ----------------------------------------------------------------------------

AO_IR_U6TX_ATTRIBUTE
void ao_ir_u6tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_6);
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MX

#if defined AO_UART_1 && AO_UART_1

// ----------------------------------------------------------------------------

AO_IR_U1_ATTRIBUTE
void ao_ir_u1()
{

#if AO_UART_RX_1

    if (ao_ir_u1rx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_1);
    }

#endif

#if AO_UART_TX_1

    if (ao_ir_u1tx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_1);
    }

#endif

}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_2 && AO_UART_2

// ----------------------------------------------------------------------------

AO_IR_U2_ATTRIBUTE
void ao_ir_u2()
{

#if AO_UART_RX_2

    if (ao_ir_u2rx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_2);
    }

#endif

#if AO_UART_TX_2

    if (ao_ir_u2tx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_2);
    }

#endif

}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_3 && AO_UART_3

// ----------------------------------------------------------------------------

AO_IR_U3_ATTRIBUTE
void ao_ir_u3()
{

#if AO_UART_RX_3

    if (ao_ir_u3rx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_3);
    }

#endif

#if AO_UART_TX_3

    if (ao_ir_u3tx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_3);
    }

#endif

}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_4 && AO_UART_4

// ----------------------------------------------------------------------------

AO_IR_U4_ATTRIBUTE
void ao_ir_u4()
{

#if AO_UART_RX_4

    if (ao_ir_u4rx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_4);
    }

#endif

#if AO_UART_TX_4

    if (ao_ir_u4tx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_4);
    }

#endif

}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_5 && AO_UART_5

// ----------------------------------------------------------------------------

AO_IR_U5_ATTRIBUTE
void ao_ir_u5()
{

#if AO_UART_RX_5

    if (ao_ir_u5rx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_5);
    }

#endif

#if AO_UART_TX_5

    if (ao_ir_u5tx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_5);
    }

#endif

}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_6 && AO_UART_6

// ----------------------------------------------------------------------------

AO_IR_U6_ATTRIBUTE
void ao_ir_u6()
{

#if AO_UART_RX_6

    if (ao_ir_u6rx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_6);
    }

#endif

#if AO_UART_TX_6

    if (ao_ir_u6tx_is_pending())
    {
        ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_6);
    }

#endif

}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32MZ

#if defined AO_UART_1 && AO_UART_1 && AO_UART_RX_1

// ----------------------------------------------------------------------------

AO_IR_U1RX_ATTRIBUTE
void ao_ir_u1rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_1);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_1 && AO_UART_1 && AO_UART_TX_1

// ----------------------------------------------------------------------------

AO_IR_U1TX_ATTRIBUTE
void ao_ir_u1tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_1);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_2 && AO_UART_2 && AO_UART_RX_2

// ----------------------------------------------------------------------------

AO_IR_U2RX_ATTRIBUTE
void ao_ir_u2rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_2);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_2 && AO_UART_2 && AO_UART_TX_2

// ----------------------------------------------------------------------------

AO_IR_U2TX_ATTRIBUTE
void ao_ir_u2tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_2);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_3 && AO_UART_3 && AO_UART_RX_3

// ----------------------------------------------------------------------------

AO_IR_U3RX_ATTRIBUTE
void ao_ir_u3rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_3);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_3 && AO_UART_3 && AO_UART_TX_3

// ----------------------------------------------------------------------------

AO_IR_U3TX_ATTRIBUTE
void ao_ir_u3tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_3);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_4 && AO_UART_4 && AO_UART_RX_4

// ----------------------------------------------------------------------------

AO_IR_U4RX_ATTRIBUTE
void ao_ir_u4rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_4);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_4 && AO_UART_4 && AO_UART_TX_4

// ----------------------------------------------------------------------------

AO_IR_U4TX_ATTRIBUTE
void ao_ir_u4tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_4);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_5 && AO_UART_5 && AO_UART_RX_5

// ----------------------------------------------------------------------------

AO_IR_U5RX_ATTRIBUTE
void ao_ir_u5rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_5);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_5 && AO_UART_5 && AO_UART_TX_5

// ----------------------------------------------------------------------------

AO_IR_U5TX_ATTRIBUTE
void ao_ir_u5tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_5);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_6 && AO_UART_6 && AO_UART_RX_6

// ----------------------------------------------------------------------------

AO_IR_U6RX_ATTRIBUTE
void ao_ir_u6rx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_rx_6);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_UART_6 && AO_UART_6 && AO_UART_TX_6

// ----------------------------------------------------------------------------

AO_IR_U6TX_ATTRIBUTE
void ao_ir_u6tx()
{
    ao_ir_stack_func0((ao_func0_t) ao_uart_ir_tx_6);
}

// ----------------------------------------------------------------------------

#endif

#endif

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_XC32_PIC32_WDT

#if defined AO_WDT

// ----------------------------------------------------------------------------

#if defined AO_SYS_XC32_PIC32MX

// ----------------------------------------------------------------------------

void ao_wdt_reset()
{
    WDTCONSET = _WDTCON_WDTCLR_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_XC32_PIC32MK || defined AO_SYS_XC32_PIC32MZ

// ----------------------------------------------------------------------------

void ao_wdt_reset()
{
    volatile uint16_t * key;

    key = (volatile uint16_t *) &WDTCON;

    key = key + (_WDTCON_WDTCLRKEY_POSITION >> 4);

    *key = 0x5743;
}

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#endif

#endif

// ----------------------------------------------------------------------------
