def zamena(word, replace):
    replace_dict = {replace[i][0]: replace[i][1] for i in range(len(replace))}
    reverse = ''.join(replace_dict.get(char, char) for char in word)

    return reverse
