import re
txt = '''Please send your resume to contactus@gmail.com for the open position. The meeting is scheduled for next Tuesday at 2 PM. Please RSVP to rsvp@gmail.com. If you have any questions, please feel free to contact me at help@gmail.com. The password for the online course is onlinecourse@gmail.com. The new address for the company is companyname@gmail.com'''

list = re.split(" ", txt)
emails = []

for word in list:
    if re.search(".com", word):
        emails.append(word)
        
print(emails)
