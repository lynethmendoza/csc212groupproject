# CSC 212 Term Project: Group 5 – Recursive Graphics
Our project uses recursion to create three different fractals: Hilbert Curve, Koch Snowflake, and Sierpinski Triangle. We also use L-System to make the commands, and we use Python Turtle to draw the fractals that we are given.

## Compiling and Running
Since we are using L-Systems, it is important to use the L-System Plotter Python code in this repo. 
Ensure all files are in the same directory for this to work.
You have to download the matplotlib library onto your computer since the L-System code uses it.

### For Each Fractal C++ File:

You'll need to run and compile the C++ fractal files before plotting whichever fractal you like with the L-System Plotter code. 
To do this, you should run the following cpp files with this:

``g++ [chosenfractal].cpp  && ./a.out [filename].txt [order of fractal]``

### For the L-System Plotter Python File:

The Python file should take in your command file name (that was edited in the C++ file), the name for your output PNG file, and the degree for turns:

``python3 "l-system-plotter.py" "[filename].txt" "[outputname].png" [degree]``

## Degrees for Each Fractal
Hilbert Curve: 90

Koch Snowflake: 60

Sierpinski Triangle: 120
