class Automaton(object):

    def __init__(self):
        self.state = "q1"

    def read_commands(self, commands):
        for x in commands:
            self.edit_state(x)

        if self.state == "q2":
            return True

        return False

    def edit_state(self, input):
        if self.state == "q1":
            if input == "1":
                self.state = "q2"
            return

        if self.state == "q2":
            if input == "0":
                self.state = "q3"
            return

        if self.state == "q3":
            self.state = "q2"


my_automaton = Automaton()

print(my_automaton.read_commands(["1", "0", "0", "1"]))
