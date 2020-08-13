Modular Arithmetic Properties

  In this module you will be learning five major properties.

  1.Properties of addition        in modular arithmetic:
  2.Properties of subtraction     in modular arithmetic:
  3.Properties of multliplication in modular arithmetic:
  4.Properties of exponentiation  in modular arithmetic:
  5.Properties of division        in modular arithmetic:


  (1) Addition

    ( A + B ) % m = [( A%m ) + ( B%m )] % m           (here % stands for modulas operation)

    example:

        (100 + 150) % 7 = ?
     => [(100 % 7) + (150 % 7)] % 7
     => [ 2 + 3] % 7
     =  5


  (2) Subtraction

    ( A - B ) % m = [ ( A%m ) - ( B%m ) + m ] % m           (here % stands for modulas operation)

    example:

        (148 - 100) % 7 = ?
     => [ (148 % 7) - (100 % 7) + 7] % 7
     => [ 1 - 2 + 7] % 7
     =  6


    (3) Multiplication

       ( A * B ) % m = [( A%m ) * ( B%m )] % m           (here % stands for modulas operation)

       example:

        (150 * 100) % 7 = ?
     => [ (150 % 7) * (100 % 7) ] % 7
     => [ 3 * 2 ] % 7
     =  6


    (4) Exponentiation

        (A ^ B) % m = ( [ A % m]^ B ) % m            (here ^ stands for power and % stands for molulas operation)

        example:

        (18 ^ 5) % 7 = ?
     => ( [ (18 % 7) ]^ 5 ) % 7
     => [ 4^5 ] % 7
     =  2


    (5) Division

    Note: We can not always do modular division.
    Modular division is defined when modular inverse of the divisor exist.
    The inverse of an integer X is an another integer y such that
    ( X * Y ) % m = 1

    In simple words:
        Inverse Modular of a number exist under modulo m if the number and m are Co-Prime
        i.e- GCD of them is 1.


    ( A/B ) % m = [ ( A % m) * ( ( {B}^-1) % m ) ] % m
      provided GCD (B,m) =1
      To calculate inverse modulo, you can use EXTENDED EUCLID'S ALGORITHM

      Example:

          (1/15) % 11 = ?
        => inverse modular is aplicable because GCD(15,11) = 1

         = (15^-1) % 11
         it means
         => ( 15 * X ) % 11 = 1
         we need to find the value of X which when multiplied by 15 and after modulas operation with 11 should give remainder 1

         For instance - put X = 3
          (15 * 3) % 11 = 1
          hence inverse molular of it is 3.
