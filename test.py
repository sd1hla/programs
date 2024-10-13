import unittest
from zamena import zamena

class TestZamena(unittest.TestCase):
    def setUp(self):
        self.replacements = [
            ('a', 'z'), ('b', 'y'), ('c', 'x'), ('d', 'w'), ('e', 'v'),
            ('f', 'u'), ('g', 't'), ('h', 's'), ('i', 'r'), ('j', 'q'),
            ('k', 'p'), ('l', 'o'), ('m', 'n'), ('n', 'm'), ('o', 'l'),
            ('p', 'k'), ('q', 'j'), ('r', 'i'), ('s', 'h'), ('t', 'g'),
            ('u', 'f'), ('v', 'e'), ('w', 'd'), ('x', 'c'), ('y', 'b'),
            ('z', 'a'), 
            ('A', 'Z'), ('B', 'Y'), ('C', 'X'), ('D', 'W'), ('E', 'V'),
            ('F', 'U'), ('G', 'T'), ('H', 'S'), ('I', 'R'), ('J', 'Q'),
            ('K', 'P'), ('L', 'O'), ('M', 'N'), ('N', 'M'), ('O', 'L'),
            ('P', 'K'), ('Q', 'J'), ('R', 'I'), ('S', 'H'), ('T', 'G'),
            ('U', 'F'), ('V', 'E'), ('W', 'D'), ('X', 'C'), ('Y', 'B'),
            ('Z', 'A')
        ]

    def test_letter(self):
        self.assertEqual(zamena("abc", self.replacements), "zyx")
        self.assertEqual(zamena("xyz", self.replacements), "cba")
        
    def test_number(self):
        self.assertEqual(zamena("12345", self.replacements), "12345")

    def test_mix(self):
        self.assertEqual(zamena("Hi1984", self.replacements), "Sr1984")

if __name__ == '__main__':
    unittest.main()

