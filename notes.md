# Notes

### VSTips 

- Hover over hex to see its decimal value

**Shortcuts**

- CTRL+SHIFT+B -> Build
- F5 -> Debug
- SHIFT+F5 -> Stop debug
- F9 -> breakpoint
- F10 -> Step over

**Disassembly**
- Right click > Go to dissasembly
- right click > Check byte codes > See byte codes

**Debug**
- F5 -> Debug
- SHIFT+F5 -> Stop debug
- Debug > Windows > Watch -> open debug watch window- 
- Debug > Windows > Registers -> Open registers
- Debug > Windows > Memory -> Memory window


---
Day 2
---

I need to study algebra
C is s low lever language
ASM mathes the C. You can read this
How things really work is worth knowing
I WANT TO KNOW WHATS GOING ON

### What is a variable "really"?

- Put the variable in the watch window

### Number types

```
char Small;
short Medium;
int Large;
```

### Binary

Computer work with bits (1 and 0)

```
char SmallS; // 8 bits - 256 different values [-128,127]
char unsigned SmallU; // 8 bits - 256 different values [0,255]

short MediumS; // 16 bits - 65536
short unsigned MediumU;

int LargeS; // 32 bits - 4 billion
int unsigned LargeU;
```

### Assembly

- Is really good to know how to ready assembly

**Registers**

- Representation of the registers of the CPU
- Code instructions to the CPU

  Gets some memory > pull in to an register > as command that can operate to change the values > as commands to put does values again in mmemory (GB RAM)

**Instructions**

mov -> move - move memory from one place to another


---
Day 3
---

**ALL IS ABOUT MEMORY**

Programming == Modifying Memory

Understand whats CPU is doing and how memory is being managed

Importing debugging

We will never know everything but its important to have an ideia on whats going on in the memory

**Where are the bits?**

With pointers

char unsigned *TestPointer;

- In C memory is a first class citizen

- C allows us to manipulate memory whatever we want with pointers that holds the address of 
number in memory

- Unlike other languages that dont allow to manipulate memory

Systax of Pointers: * and &

`&` -> address operator

`&Test` -> i want to know were Test is in memory

We can put the `TestPointer` in the watch window and we can see the HEX value. To see an int value we put the (int unsigned) value

e.g:
(int unsigned)TestPointer	3471833140	unsigned int
                                |
                    isto antes apontava para o                             physical address na maquina

### Virtual Memory

Hoje em dia os pcs usam **Virtual Memory** -> lets all the system processes cooperate with each other 

Virtal Memory allows the code that is running in the machine to see what appears to be te memory of the machine.

It divides the memory into pages (chunks) that represent a part of the "page" in the physical memory.

#### Looking at memory in the watch window

- Normaly they show as a hexadecimal value;
- Raramente não temos de ler pointers;


- We can click the plus to see what is in the memory location - in this case pointing to the value that we assinged previously (TestPointer = &Test). The pointer is pointing to the same actual memory as the Test; Every time that Test changes the TestPointer is going to do the same; **THEY ARE IN THE SAME PIECE IN THE MEMORY**

### Changing memory manually via the debugger

To do that we use the Memory window and changing the value in the watch will reflet the changes in the Memory window. We just need to grab the Pointer value in the Watch window and put it in the Memory window;

(address)           (value)
0x000000FDCEEFF834  00 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc c

In the memory window we see everything as hexadecimals so, for example, when we change the value of Test to 16we can see that its memory value changes to 10 ....;

(address)           (value)
0x000000FDCEEFF834  10 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc c

we can right click and check "unsigned display" it like this.

(address)           (value)
0x000000FDCEEFF834   16 204 204 204 204 204 204 204 204 204 204 204 204 204 204 204 204 204 204 204 204 204 204 204

We can even add a new watch line with "C" code:
(TestPointer + 1) -> points to the next byte

we can do everything but poke into the memory that we havent told to the operating system that we are using to

Getting close to the metal is awesome!!


### Where did this initial memory come from?

* We didnt ask for any memory in the initial code, how that worked?
    * Thats because we write to the **STACK** -> we dont need to ask for this because the C compiler does that job for us. Se estivessemos a usar uma linguagem mais low level isso nao aconteceria. Its built in the C compiler.
    
    * The way that it happens: When we enter a function and we ask for memory in a way that its just declaring a variable, what happens is that is going to grab memory from the END of the Stack and the Stack grows a litte bit. 
    
    This happens in a function scope like:


    ```
        int foo(void)
        {
            // Pede alguma memoria do FIM da Stack
            // A Stack cresce
            char foo = "A"
            
            // Volta para a main
        }


        int main() // Entra aqui
        {
            // Pede alguma memoria do FIM da Stack
            // A Stack cresce
            char unsigned Test;
            char unsigned *TestPoitner;

            TestPointer = &Test;

            Test = 255;
            Test = Test + 1;

            // Vai a funcao foo()
            foo();

            // Remove os espaços usados anteriormente
            // Porque ja nao precisa deles
        }

    ```

    * IMPORTANT TO UNDERSTAND: The middle of the Stack never goes away becuase of the CALL and RETURN flow;

    CALL CALL CALL RETURN RETURN RETURN
 
### Why memory moving arround?

- Security reasons
- Address Randomization (different address locations)


MEMORY CONTROL == SUPER POWERS

We can go to the disassembly, go to a piece of code, grab the hex address and check it in memory.

### Motherboard picture

- O CPU vai a Memoria buscar os bits atravez do BUS

#### Why does speed matters?

CPUs have clocks = ticks

The CPU can do 1 operation per clock

That means that the CPU can do at least 2.90ghz speed times per second;

    * Clock speed / 2.90ghz = 10.3cm


Na foto da CPU à Memoria são 10cm (em linha reta), ou seja, ele no maximo só consegue ir à memoria num clock.

THIS IS EXPENSIVEEE!!! We have better solutions like the eDRAM

Same thing for the graphics card

Two important things to study:

1. Latency
2. Throughput

1. Latency
    - Memory latency → how fast the CPU or GPU can get data from RAM
    - CPU latency → how fast the CPU processes instructions.
    - GPU latency → often less critical because GPUs hide latency with parallelism.

    Example:

    - CPU asks RAM for data. If RAM is slow (high latency), CPU waits → CPU is idle.

3. Throughput

    - Memory throughput → how much data can flow per second between CPU/GPU and RAM.

    - High throughput is crucial for big data or parallel workloads.

    Example:

    - GPU rendering a 4K frame: needs hundreds of GB/s → high throughput memory like HBM helps.
    - CPU running office apps: needs much less throughput, DDR5 is fine.

---
Day 4
---

So see the disassembly address in the memory windows we prefix it with 0xADDRESS

### Code bytes

we can see the code bytes by right clicking and checking then

                                            (translation)
(memory address) (byte codes)     (memonics)
00007FF760C818E1 C6 45 04 FF          mov         byte ptr [Test],0FFh

### Looking at memory in more detail















