#chatbot project -> source code from chat gpt -> "python3 project.py"

def simple_chatbot(user_input):
    # Dictionary of predefined responses
    responses = {
        "hello": "Hi there! How can I help you?",
        "how are you": "I'm a bot, so I don't have feelings, but thanks for asking!",
        "bye": "Goodbye! Have a great day.",
        "let's get baron?": "nah bro, it's way too early for that i gotta farm",
        "default": "I'm not sure how to respond to that. Can you ask me something else?"
    }

    # Convert user input to lowercase for case-insensitive matching
    user_input_lower = user_input.lower()

    # Check if the user input matches any predefined responses
    bot_response = responses.get(user_input_lower, responses["default"])

    return bot_response

# Main loop for interacting with the chatbot
def main():
    print("Simple Chatbot: Type 'bye' to exit.")
    
    while True:
        user_input = input("You: ")
        
        if user_input.lower() == 'bye':
            print("Simple Chatbot: Goodbye!")
            break

        bot_response = simple_chatbot(user_input)
        print("Simple Chatbot:", bot_response)

if __name__ == "__main__":
    main()
