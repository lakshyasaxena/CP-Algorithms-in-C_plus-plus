Euler Totient function
Also called as Phi function

This function counts the positive integers less then N, which are Co-Prime to N.
Two numbers are Co-Prime if their GCD = 1.

Example:
    Phi(7) = {1,2,3,4,5,6}
           => Phi(7)=6
    Phi(10) = {1,3,7,9}
           => Phi(10)=4
    Phi(100) =40

Note : If N is a prime number then, Phi(N) = (N-1)

Application:

Euler's Theorem

If asked:

         (A^B) % C = ?
         =>(A to the power B) modulo C = ?

         Provided GCD(A,C)=1
         then

         [A^phi(C)] % c =1
         =>(A to the power phi function of C modulo C equals to one)

Example:

    (15^21) % 8 = ?

       GCD(15,8) = 1
       phi(8) = 4

    Hence by euler's theorem
    15^4 %8 = 1

    Hence the above problem can be reduced as follow:

        (15^4).(15^4).(15^4).(15^4).15 % 8 = ?
        => 15 % 8 = ?
        =7

Note: When C is a Prime Number
      Euler's Theorem turns into Fermat's Little Theorem
      A^B % C = ?
      where c is prime
    =>A^(C-1) % C =1

