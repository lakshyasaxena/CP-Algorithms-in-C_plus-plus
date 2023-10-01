from collections import defaultdict
 
def print_anagram(store):
    for key, value in store.items():
        print(*value)
 
def store_in_map(arr):
    store = defaultdict(list)
    for string in arr:
        char_count = [0] * 26
        for c in string:
          #count the frequency of each character in the string
            char_count[ord(c) - ord('a')] += 1
        hash_str = '#'.join(map(str, char_count))
        store[hash_str].append(string)
        # print all the anagrams
    print_anagram(store)
 
if __name__ == '__main__':
    arr = ["geeksquiz", "geeksforgeeks", "abcd", "forgeeksgeeks", "zuiqkeegs", "cat", "act", "tca"]
    store_in_map(arr)
