#python2.7
# found email

import re,pyperclip

emailregex = re.compile(r'''(
[a-zA-Z0-9_]+    #username
@                   
[a-zA-Z0-9.]+       #domain name
                    #(\.[a-zA-Z0-9]{2,4})?
)''',re.VERBOSE)

text = pyperclip.paste()
group=emailregex.findall(text)
for i in group:
    print i
