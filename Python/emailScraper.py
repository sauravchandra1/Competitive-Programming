#! usr/bin/python3

import re, pyperclip

emailRegex = re.compile(r'''
[a-zA-Z0-9_.+]+
@
[a-zA-Z0-9_.+]+
	''', re.VERBOSE)

text = pyperclip.paste()

extractText = emailRegex.findall(text)
emails = []

ans = '\n'.join(extractText)
pyperclip.copy(ans)