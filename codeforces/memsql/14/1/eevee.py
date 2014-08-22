import re
input()
print(next(filter(re.compile(input()[:-3] + '$').match, ['vapor', 'jolt', 'flar', 'esp', 'umbr', 'leaf', 'glac', 'sylv'])) + 'eon')
