class Servers():
    def __init__(self):
        self.servers = []
        self.data = []
    
    
    def get(self, server: str):
        return self.data[self.servers.index(server)]

    def has(self, server: str):
        if server in self.servers:
            return True
        else:
            return False
    
    def add(self, server: str):
        if not self.has(server):
            self.servers.append(server)
            self.data.append({
                'queue': [],
                'connection': False
            })
            return True
        return False