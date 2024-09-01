def build_message(**info):
    key_and_value = []
    for key, value in info.items():
        key_and_value.append(f"{key}: {value}")
    return ', '.join(key_and_value)

message = build_message(name="Alice", age=30, city="New York", profession="Engineer")
print(message)
