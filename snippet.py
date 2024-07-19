# Generates cpp.json with snippets for VSCode

import os
import json
import sys

snippets = {}

path = '/Users/cola/acm/cpbook'
for subdir in os.walk(path):
  if subdir[0] == '.' or subdir[0][2] == '.':
    continue
  if '.git' in subdir[0]:
    continue
  for filename in subdir[2]:
    name, extension = filename.split('.')
    if extension != 'hpp':
      continue
    if name in snippets:
      print(f'error: duplicate snippet {name}', file=sys.stderr)
      exit(0)

    path = subdir[0] + '/' + filename
    with open(path, 'r') as f:
      snippet = {
        "prefix": name,
        "body": [line.rstrip() for line in f.readlines()],
        "description": name
      }
      snippets[name] = snippet

    print(f'generated snippet {name}', file=sys.stderr)

with open('/Users/cola/Library/Application Support/Code/User/snippets/cpp.json', 'w') as f:
  f.write(json.dumps(snippets, indent=2))

print('done', file=sys.stderr)