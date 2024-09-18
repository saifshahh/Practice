import re

text = "The concert is scheduled for 28/09/2024 at 7:30 PM. Tickets went on sale on 2024-08-1 and sold out within hours. The band's last album was released on January 12, 2023. The concert venue is the famous Xyz Arena, which was built in 11/07/1998. Fans from all over the country are eagerly anticipating the event, which is expected to be a night to remember."

extract_dates = r"\b(\d{1,2}/\d{1,2}/\d{4}|\d{4}-\d{1,2}-\d{1,2}|[A-Za-z]{3,} \d{1,2}, \d{4})\b"

x = re.findall(extract_dates, text)

for date in x:
    print(date)
