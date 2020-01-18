# 105torus

Drawing circles, cylinders and cones is a good start for an image synthesis software, but one have to admit
it is not fully satisfying. . . This project is the continuation of the previous one, and should allow you to draw
more complex forms, such as a torus, which do not emerge from 2nd degree equations, but from superior
degree equations (4th degree in the torus case).

The objective of this project is to solve a 4th degree equation: a4x⁴ + a3x³ + a2x² +a1x1 +a0 = 0. A direct
resolution method does exist (Ferrari’s method), but does not generalize to higher degrees. Thus, we will
rather compare 3 iterative algorithms:

• The bisection method,     
• Newton’s method,     
• The secant method.     

    Equations to be solved here will all have one and only one solution, in the [0, 1] interval.
    This is the solution we are looking for. The initial value for Newton’s method will be 0.5,
    those for the 2 other methods will be 0 and 1.      

    Just in case you would need it, the derivative of the polynomial function x → a4x⁴ +
    a3x³ + a2x² + a1x + a0 is the function x → 4a4x³ + 3a3x² + 2a2x + a1
