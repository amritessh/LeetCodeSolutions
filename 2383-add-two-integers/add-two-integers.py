class Solution:
    def sum(self, a: int, b: int) -> int:
        """
        The official requirement:
        Return the sum of two integers a and b (LeetCode #2235).
        
        But we also do some checks with the custom Int class:
          - Check a+b in normal Python,
          - Check comparisons,
          - Use our Int-based addition,
          - Verify they match.
        """
        c = a + b
        relation = [
            a < b,
            a <= b,
            a > b,
            a >= b,
            a == b,
            a != b
        ]
        # Now test with custom Int class
        ma = Int(a)
        ma1 = Int(a)
        mb = Int(b)
        mb1 = Int(b)
        madd = Int()
        mrelation = []
        # Use the Exam constructor to compute madd and fill mrelation
        s = Exam(ma, mb, madd, mrelation)
        # Make sure original ma, mb are unchanged
        assert ma == ma1
        assert mb == mb1
        # Check that madd.int() == (a+b)
        assert c == madd.int()
 
        # Compare list of booleans
        for i in range(len(relation)):
            assert relation[i] == mrelation[i]
 
        # Return the plain Python sum to solve LeetCode
        return c
 
 
############################################################
# WRITE CODE BELOW
###########################################################
class Exam:
    def __init__(self, a:'Int', b:'Int', add:'Int', relation:'list[bool]') -> None:
        """
        (1) add = a + b using our ripple-carry logic from Int.
        (2) relation = 6 comparisons of (a, b):
           [a<b, a<=b, a>b, a>=b, a==b, a!=b]
        """
        s = a + b        # uses Int.__add__
        add._a = s._a[:] # copy list of digits
        add._positive = s._positive
 
        # Fill out the relation array with the 6 comparisons
        relation.append(a < b)
        relation.append(a <= b)
        relation.append(a > b)
        relation.append(a >= b)
        relation.append(a == b)
        relation.append(a != b)
 
 
############################################################
# Int.py (If in a separate file)
# Implements Int object
# Author: Jagadeesh Vasudevamurthy
# Copyright:
############################################################
 
class Int:
    def __init__(self, n=0):
        """
        The data structure is:
          self._a: list[int], each digit
          self._positive: bool for sign
        """
        self._a = []
        self._positive = True
 
        if isinstance(n, int):
            # from built-in int
            if n < 0:
                self._positive = False
                n = -n
            if n == 0:
                # represent 0 as [0]
                self._a = [0]
            else:
                digits = []
                while n > 0:
                    digits.append(n % 10)
                    n //=10
                digits.reverse()
                self._a = digits
        elif isinstance(n, Int):
            # copy constructor
            self._a = n._a[:]
            self._positive = n._positive
        else:
            raise TypeError("Cannot construct Int from that type")
 
    def __str__(self):
        if not self._a:
            return "0"
        val = "".join(str(d) for d in self._a)
        return "-" + val if not self._positive else val
 
    def int(self):
        """ Convert to Python int for convenience (may overflow for huge numbers). """
        if not self._a:
            return 0
        val = 0
        for d in self._a:
            val = val * 10 + d
        return val if self._positive else -val
 
    def __len__(self):
        return len(self._a)
 
    def __getitem__(self, index):
        return self._a[index]
 
    def __eq__(self, other):
        if not isinstance(other, Int):
            return False
        return self._positive == other._positive and self._a == other._a
 
    def __lt__(self, other):
        if self._positive != other._positive:
            return not self._positive  # negative < positive
        # same sign
        if len(self._a) != len(other._a):
            if self._positive:
                return len(self._a) < len(other._a)
            else:
                return len(self._a) > len(other._a)
        # same length, same sign => compare lexicographically
        for i in range(len(self._a)):
            if self._a[i] != other._a[i]:
                if self._positive:
                    return self._a[i] < other._a[i]
                else:
                    return self._a[i] > other._a[i]
        # all digits equal => they are equal
        return False
 
    def __le__(self, other):
        return self < other or self == other
 
    def __gt__(self, other):
        return not (self <= other)
 
    def __ge__(self, other):
        return not (self < other)
 
    def __ne__(self, other):
        return not (self == other)
 
    def _ripple_carry_adder(self, b:'Int') -> 'Int':
        """
        Helper that adds two *positive* Ints digit-by-digit
        and returns a new positive Int result.
        """
        pa = len(self._a) - 1
        pb = len(b._a) - 1
        carry = 0
        out = []
        while pa >= 0 or pb >= 0 or carry > 0:
            va = self._a[pa] if pa >= 0 else 0
            vb = b._a[pb] if pb >= 0 else 0
            s = va + vb + carry
            carry = s // 10
            out.append(s % 10)
            pa -= 1
            pb -= 1
        out.reverse()
        c = Int()
        c._a = out
        c._positive = True
        return c
 
    def _ripple_carry_subtractor(self, b:'Int') -> 'Int':
        """
        Helper that subtracts b from self,
        assuming both are positive and self >= b in magnitude.
        Returns a new positive Int = (self - b).
        """
        pa = len(self._a) - 1
        pb = len(b._a) - 1
        borrow = 0
        out = []
        while pa >= 0 or pb >= 0:
            va = self._a[pa] if pa >= 0 else 0
            vb = b._a[pb] if pb >= 0 else 0
            diff = va - vb - borrow
            if diff < 0:
                diff += 10
                borrow = 1
            else:
                borrow = 0
            out.append(diff)
            pa -= 1
            pb -= 1
        out.reverse()
        # remove leading zeros
        while len(out) > 1 and out[0] == 0:
            out.pop(0)
        c = Int()
        c._a = out
        c._positive = True
        return c
 
    def __add__(self, b:'Int') -> 'Int':
        """
        Implementation of self + b, considering sign:
         - If same sign => add magnitudes
         - If different sign => subtract smaller from bigger, keep bigger's sign
        """
        # same sign => add
        if self._positive == b._positive:
            s = self._ripple_carry_adder(b)
            s._positive = self._positive
            return s
        else:
            # different sign => we do magnitude-based subtraction
            # figure out which is bigger in absolute value
            a_val = abs(self.int())
            b_val = abs(b.int())
            if a_val == b_val:
                return Int(0)  # +5 + -5 => 0
            elif a_val > b_val:
                diff = self._ripple_carry_subtractor(b)
                diff._positive = self._positive
                return diff
            else:
                diff = b._ripple_carry_subtractor(self)
                diff._positive = b._positive
                return diff