class Commands():
    def __init__(self):
        self.cmds = []
        self.cmdsData = []
        self.alias = []
        self.aliasData = []
    
    def get(self, cmd: str):
        return self.cmdsData[self.cmds.index(cmd)]

    def getAlias(self, alias: str):
        return self.get(self.aliasData[self.alias.index(alias)])

    def has(self, cmd: str):
        if cmd in self.cmds:
            return True
        else:
            return False

    def hasAlias(self, alias: str):
        if alias in self.alias:
            return True
        else:
            return False
    
    def add(self, cmd: str, module):
        if not self.has(cmd):
            self.cmds.append(cmd)
            self.cmdsData.append(module)
            return True
        return False
    
    def addAlias(self, alias: list, cmd: str):
        if not self.hasAlias(alias[0]):
            for alia in alias:
                self.alias.append(alia)
                self.aliasData.append(cmd)
            return True
        return False