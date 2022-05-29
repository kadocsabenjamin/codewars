import string


class FSM():
    def __init__(self) -> None:
        self.state = "CLOSED"
        self.term = False

    def entry(self, events) -> string:
        for x in events:
            if self.term == True:
                return "ERROR"
            if self.state == "CLOSED":
                self.closed(x)
            elif self.state == "LISTEN":
                self.listen(x)
            elif self.state == "SYN_RCVD":
                self.syn_rcvd(x)
            elif self.state == "SYN_SENT":
                self.syn_sent(x)
            elif self.state == "ESTABLISHED":
                self.established(x)
            elif self.state == "FIN_WAIT_1":
                self.fin_wait_1(x)
            elif self.state == "FIN_WAIT_2":
                self.fin_wait_2(x)
            elif self.state == "CLOSING":
                self.closing(x)
            elif self.state == "TIME_WAIT":
                self.time_wait(x)
            elif self.state == "CLOSE_WAIT":
                self.close_wait(x)
            elif self.state == "LAST_ACK":
                self.last_ack(x)
            else:
                return "ERROR"

        if self.term == True:
            return "ERROR"

        return self.state

    def closed(self, input) -> None:
        if input == "APP_PASSIVE_OPEN":
            self.state = "LISTEN"
        elif input == "APP_ACTIVE_OPEN":
            self.state = "SYN_SENT"
        else:
            self.term = True

    def listen(self, input) -> None:
        if input == "RCV_SYN":
            self.state = "SYN_RCVD"
        elif input == "APP_SEND":
            self.state = "SYN_SENT"
        elif input == "APP_CLOSE":
            self.state = "CLOSED"
        else:
            self.term = True

    def syn_rcvd(self, input) -> None:
        if input == "APP_CLOSE":
            self.state = "FIN_WAIT_1"
        elif input == "RCV_ACK":
            self.state = "ESTABLISHED"
        else:
            self.term = True

    def syn_sent(self, input) -> None:
        if input == "RCV_SYN":
            self.state = "SYN_RCVD"
        elif input == "RCV_SYN_ACK":
            self.state = "ESTABLISHED"
        elif input == "APP_CLOSE":
            self.state = "CLOSED"
        else:
            self.term = True

    def established(self, input) -> None:
        if input == "APP_CLOSE":
            self.state = "FIN_WAIT_1"
        elif input == "RCV_FIN":
            self.state = "CLOSE_WAIT"
        else:
            self.term = True

    def fin_wait_1(self, input) -> None:
        if input == "RCV_FIN":
            self.state = "CLOSING"
        elif input == "RCV_FIN_ACK":
            self.state = "TIME_WAIT"
        elif input == "RCV_ACK":
            self.state = "FIN_WAIT_2"
        else:
            self.term = True

    def fin_wait_2(self, input) -> None:
        if input == "RCV_FIN":
            self.state = "TIME_WAIT"
        else:
            self.term = True

    def closing(self, input) -> None:
        if input == "RCV_ACK":
            self.state = "TIME_WAIT"
        else:
            self.term = True

    def time_wait(self, input) -> None:
        if input == "APP_TIMEOUT":
            self.state = "CLOSED"
        else:
            self.term = True

    def close_wait(self, input) -> None:
        if input == "APP_CLOSE":
            self.state = "LAST_ACK"
        else:
            self.term = True

    def last_ack(self, input) -> None:
        if input == "RCV_ACK":
            self.state = "CLOSED"
        else:
            self.term = True


def traverse_TCP_states(events):

    fsm = FSM()

    return fsm.entry(events)
