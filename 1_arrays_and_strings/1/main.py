# Grayson Pike, 2016
# Implement an algorithm to determine if a string has all unique characters.
# What if you cannot use additional data structures?


# Using no additional data structures
# very slow for large strings, exponential runtime
def is_unique(s):
    for i in range(len(s)):
        for j in range(len(s)):
            if s[i] == s[j] and i != j:
                return False
    return True


# using an array, assuming that ascii goes from 0-127
# linear runtime
def is_unique2(s):
    used = []
    for i in range(128):
        used.append(False)
    for c in s:
        if used[ord(c)]:
            return False
        else:
            used[ord(c)] = True
    return True


def main():
    s1 = "grayson"
    s2 = "riddhi"

    print("Using is_unique:")
    print("s1 is unique: " + str(is_unique(s1)))
    print("s2 is unique: " + str(is_unique(s2)))

    print("Using is_unique2:")
    print("s1 is unique: " + str(is_unique2(s1)))
    print("s2 is unique: " + str(is_unique2(s2)))

main()
