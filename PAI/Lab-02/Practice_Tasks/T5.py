def centre_print(text):
    print(text.center(40))

name = input('Enter your name: ')
print(f"Hello! {name}")

more = input('I hope you are fine, let me know how I can help you! ')

if more == 'yes':
    prob = input('Share your problem with us: ')
    print('Thanks for your feedback, we will resolve your problem.')
else:
    centre_print('Okay! Good to see you, stay connected.')
