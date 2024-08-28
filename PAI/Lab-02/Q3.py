def checker(url):
    if (url.startswith('http://www.')):

        user_url = url[len('http://www.'):]
        return user_url
    else:
        return "Invalid URL"


url = input("Enter your URL: ")

print(checker(url))
