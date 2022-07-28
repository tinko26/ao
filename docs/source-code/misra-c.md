---
author: "Stefan Wagner"
description: "MISRA C compliance of the ao real-time operating system (RTOS)."
permalink: /source-code/misra-c/
title: "MISRA C"
---

# MISRA C

## MISRA C compliance

### Unused code

**2.1** A project shall not contain unreachable code

**2.2** There shall be no dead code

**2.3** A project should not contain unused ty pe declarations

**2.4** A project should not contain unused ta g declarations

**2.5** A project should not contain unused ma cro declarations

**2.6** A function should not contain unused l abel declarations

**2.7** There should be no unused parameters i n functions

### Comments

**3.1** The character sequences /* and // shall not be used within a comment

**3.2** Line-splicing shall n ot be used in // comments

### Characters sets and lexical conventions

**4.1** Octal and hex adecimal escape sequences shall be term inated

**4.2** Tr igraphs should not be used

### Identifiers

**5.1** External identifiers shall be distinct

**5.2** Identifiers declared in the same scope and namespace shall be distinct

**5.3** An identifier declared in an inner scope shall not hide an identifier declared in an outer scope

**5.4** Macro identifi er s shall be distinct

**5.5** Identifiers shall be distinct from macro names

**5.6** A typedef name shall be a unique identifier

**5.7** A tag name shall be a unique identifier

For 5.6 and 5.7, the exception statet in 5.7 applies:

The tag name may be the same as the typedef name with which it is associated.

**5.8** Identifi ers that defi ne objects or functions with external linkage shall
be unique

**5.9** Identifi ers that defi ne objects or functions with internal linkage should
be unique

### Types

**6.1** Bit-fields shall only be declared with an appropriate type

**6.2** Single-bit named bit fi elds shall not be of a signed type

### Literals and constants

**7.1** Octal constants shall not be used

**7.4** A string liter al shall not be assigned to an object unless the object’s
type is “pointer to const-qualifi ed char”

### Declarations and definitions

**8.1** Types shall be explicitly specifi ed

**8.2** Function types shall be in prototype form with named parameters

**8.3** All declarations of an object or function shall use the same names and
type qualifi ers

**8.4** A compatible declaration shall be visible when an object or function
with external linkage is d efi ned

**8.5** An external object or function shall be declared once in one and only
one fi le

**8.6** An identifi er with external linkage shall have exactly one external
defi nition

**8.7** Functions and objects should not be defi ned with external linkage if
they are referenced in only one translation unit

**8.8** The static storage class specifi er shall be used in all declarations of
objects and functions that have internal linkage

**8.9** An object should be defi ned at block scope if its identifi er only
appears in a single function

**8.10** An inline function shall be declared with the static storage class

**8.11** When an array with external linkage is declared, its size should be
explicitly specifi ed

**8.12** Within a n enumerator list, the value of an implicitly-specifi ed
enumeration constant shall be unique

**8.13** A pointe r should point to a const-qualifi ed type whenever possible

**8.14** The rest rict type qualifi er shall not be used

### Initialization

**9.1** The value of an object with automatic storage duration shall not be
read before it has been set

**9.2** The initializer for an aggregate or uni on shall be enclosed in braces

**9.3** Arrays shall not be partially initializ ed

**9.4** An element of an object shall not be in itialized more than once

**9.5** Where designated initializers are used t o initialize an array object the
size of the array shall be specifi ed explicitly

### Operators

**12.1** The precedence of operators withi n expression s should be made
explicit

**12.2** The right hand operand of a shift operator shall lie in the range zero
to one less than the width in bits of the essential type of the left hand
operand

**12.3** The comma operato r should not be used

**12.4** Evaluation of constant expressions should not lead to unsigned integer
wrap-around

### Side effects

**13.1** Initi alizer lists shall not contain persistent side eff ects

**13.2** The value of an expression and its persistent side eff ects shall be the
same under all permitted evaluation orders

**13.3** A full expression containing an increment (++) or decrement (--)
operator should hav e no other potential side eff ects other than that
caused by the increment or decrement operator

**13.4** The result of an assignment operator should not be used

**13.5** The right hand operand of a logical && or || operator shall not
contain persistent side eff ect s

**13.6** The operand of the sizeof operator shall not contain any expression
which has potential side eff ects

### Control statements

**14.1** A loop counter shall not have essentially fl oating type

**14.2** A for loop shall be well-form ed

**14.3** Controlling expressions shall not be invariant

**14.4** The controlling expression of an if statement a nd the controlling
expression of an iteration- statement shall have essentially Boolean type

### Control flow

**15.1** The goto statement should not be used

**15.2** The goto statement shall jump to a label declared later in the same
function

**15.3** Any label referenced by a goto statement shall be declared in the
same block, or in any block enclosing the goto statement

**15.4** There should be no more than one break or goto statement used to
terminate any iteration statement

???

**15.5** A function should have a single point of exit at the end

**15.6** The body of an iteration-statement or a selection-statement shall be a
compound-statement

**15.7** All if … else if constructs shall be terminated with an else statement

### Switch statements

**16.1** All switch s tatements shall be well-formed

**16.2** A switch label shall only be used when the most closely-enclos ing
compound statement is the body of a switch statement

**16.3** An unconditional break statement shall terminate every switch-clause

**16.4** Every switch statement shall have a default label

**16.5** A default label shall appear as either the fi rst or the last switch label of
a switch statement

**16.6** Every switch statement shall have at least two switch-clauses

**16.7** A switch-expression shall not have essentially Boolean type

### Functions

**17.1** The features of <stdarg.h> shall not be used

**17.2** Functions shall not call themselves, either directly or indirectly

Only exception: \*_assert\*() functions of binary trees (AVL, RB, Heap).

**17.3** A function shall not be declared implicitly

**17.4** All exit paths from a function with non-void return type shall have an
explicit return statement with an expression

**17.5** The function argument corresponding to a parameter declared to
have an array type shall have an appropriate number of elements

**17.6** The declaration of an array parameter shall not contain the static
keyword between the [ ]
C99

**17.7** The value returned by a function having non-void return type shall be
used

???

**17.8** A function parameter should not be modifi ed

???

### Pointers and arrays

**18.1** A pointer resulting from arithmetic on a pointer operand shall address
an element of the same array as that pointer operand

**18.2** Subtraction between pointers shall only be applied to pointers that
address elements of the same array

**18.3** The re lational operators >, >=, < and <= shall not be applied to objects
of pointer type except where they point into the same object

Disobeyed e.g. in alarm queue comparison.

**18.4** The +, -, += and -= operators sho uld not be applied to an expression
of pointer type

**18.5** Declarations should contain no more than two le vels of pointer
nesting

**18.6** The address of an object with automatic storage shall not be copied to
another object that persists after the fi rst object has ceased to exist

**18.7** Flexible array members shall not be declared

**18.8** Variable-length array types shall not be used

### Overlapping storage

**19.1** An object shall not b e assigned or copied to an overlapping object

**19.2** The union keyword should not be used

Disobeyed primarily in the port, because embedded. 

### Preprocessing directives

**20.1** \#include directiv es should only be preceded by preprocessor
directives or comments

**20.2** The ', " or \ cha racters and the /* or // character sequences shall
not occur in a header fi le name

**20.3** The #include dire ctive shall be followed by either a \<filename\> or
"filename" sequence

**20.4** A macro shall not be defi ned with the same name as a keyword

**20.5** #undef should not be used

**20.6** Tokens that look like a pr eprocessing directive shall not occur within a
macro argument

**20.7** Expressions resulting from the expansion of macro parameters shall
be enclosed in parentheses

**20.8** The contro lling expression of a #i f or #elif preprocessing directive shall
evaluate to 0 or 1

???

**20.9** All identifi ers used in the controlling exp ression of #if or #elif
preprocessing directives shall be #defi ne’d before evaluation

**20.10** The # and ## preprocessor operators should not be used

**20.11** A macro parameter immediately fol lowing a # operator shall not
immediately be followed by a ## operator

**20.12** A macro parameter used as an operand to the # or ## o perators,
which is itself subj ect to further macro replacement, shall only be
used as an operand to these operators

**20.13** A line whose fi rst token is # shall be a valid preprocessing directive

**20.14** All #else, #elif and #endif preprocessor directives shall reside in the
same fi le a s the #if, #ifdef or #ifndef directive to which they are related

### Standard libraries

**21.1** #defi ne and #undef shall not be used on a reserved identifi er or
reserved macro nam e

**21.2** A reserved identifi er or macro name shall not be declared

**21.3** The memory allocation and deallocation functions of <stdlib.h>
shall not be used

**21.4** The standard header fi le <setjmp.h> shall not be used

**21.5** The standard header fi le <signal.h> shall not be used

**21.6** The Standard Library input/output functions shall n ot be used

**21.7** The atof, atoi, atol and atoll functions of <stdlib.h> shall not be
used

**21.8** The library functions abort, exit, getenv and system of <stdlib.h>
shall not be used

**21.9** The lib rary functions bsearch and qsort of <stdlib.h> shall not be
used

**21.10** The Standard Library time and date functions shall not be used

**21.11** The standard header fi le <tgmath.h> shall not be used

**21.12** The exception handling features of <fenv.h> should not be used

### Resources

**22.1** All resources obtained dynamically by means of Standard Library
functions shall be explicitly released

**22.2** A block of memory shall only be freed if it was allocated by means o f a
Standard Library function

**22.3** The same fi le shall not be open for read and write access at the same
time on diff erent streams

**22.4** There shall be no attempt to write to a stream which has been opened
as read-only

**22.5** A pointer to a FILE object shall not be dereferenced

**22.6** The value of a pointer to a FILE shall not be used after the associated
stream has been closed



## MISRA C deviation

### A standard C environment

**1.1** The program shall contain no violations of the standard C syntax and
constraints, and shall not exceed the implementation’s translation
limits

**1.2** Language extensions should not be used

necessarily, because embedded

**1.3** There shall be no occurrence of undefi ned or critical unspecifi ed
behaviour

???

### Literals and constants

**7.2** A “u” or “U” suffi x shall be applied to all integer constants that are
represented in an unsigned type

**7.3** The lowercase character “l” shall not be used in a literal suffix

???

### Essential types

**10.1** Operands shall not be of an inappropriate essential type

**10.2** Expressions of essentially character type shall not be used
inappropriately in addition and subtraction operations

**10.3** The value of an exp ression shall not be assigned to an object with a
narrower essential type or of a diff erent essential type category

**10.4** Both operands of a n operator in which the usual arithmetic conversions
are performed s hall have the same essential type category

**10.5** The value of an expression should not be cast to an inappropriate
essential ty pe

**10.6** The value of a composite expression shall not be assigned to an object
with wider essential type

**10.7** If a c omposite expression is used as one operand of an operator in
which the u sual arithmetic conversions are performed then the other
operand shall not have wider essential type

**10.8** The value of a composite expression shal l not be cast to a diff erent
essential type category or a wider essentia l type

???

These rules may have been disobeyed, but not intentionally.

### Pointers

**11.1** Conversions shall not be performed between a pointer to a function
and any other type

**11.2** Conversions shall not be performed between a pointer to an
incomplete type and any other type

**11.3** A cast shall not be performed between a pointer to object type and a
pointer to a diff erent object type

**11.4** A conversion should not be performed between a pointer to object
and an integer type

**11.5** A conversion should not be performed from pointer to void into
pointer to object

**11.6** A cast shall not b e performed between pointer to void and an
arithmetic type

**11.7** A cast shall not b e performed between pointer to object and a noninteger
arithmetic type

**11.8** A cast shall not remove any const or volatile qualifi cation from the type
pointed to by a pointer

**11.9** The macr o NULL shall be the only per mitted form of integer null
pointer constant

Function pointers are very useful when using callbacks. Void pointers are very useful when sharing memory. Also, some pointer manipulations cannot be avoided when dealing with stack pointers and the like.

Therefore, some of these rules cannot be obeyed, because embedded, because kernel.
