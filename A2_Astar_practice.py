# import copy
# class Node:
#     def __init__(self,data,level,f_score):
#         self.data=data
#         self.level=level
#         self.f_score=f_score
    
#     def find_tile(self,puzzle,tile):
#         for i in range(len(self.data)):
#             for j in range(len(self.data)):
#                 if(puzzle[i][j]==tile):
#                     return i,j
    
#     def shuffle(self,puzzle,x0,y0,x1,y1):
#         if(x1>=0 and x1<len(self.data) and y1>=0 and y1<len(self.data)):
#             new_one=copy.deepcopy(puzzle)
#             new_one[x1][y1],new_one[x0][y0]=new_one[x0][y0],new_one[x1][y1]
#             return new_one
#         return None
    
#     def generate_child(self):
#         x,y=self.find_tile(self.data,"_")
#         pos_set=[[x,y+1],[x,y-1],[x-1,y],[x+1,y]]
#         children=[]
#         for pos in pos_set:
#             child=self.shuffle(self.data,x,y,pos[0],pos[1])
#             if(child is not None):
#                 children.append(Node(child,self.level+1,0))
#         return children

# class Puzzle:
#     def __init__(self,size):
#         self.size=size
#         self.open=[]
#         self.close=[]
#         self.cnt=0

#     def read_puzzle(self):
#         puzzle=[]
#         for i in range(self.size):
        
#                 row=input().split(" ")
#                 puzzle.append(row)
#         return puzzle

#     # def find_pos(self,val,goal):
#     #     for i in range(self.size):
#     #         for j in range(self.size):
#     #             if(goal[i][j]==val):
#     #                 return i,j

#     def calc_h_score(self,start,goal):
#         h_score=0
#         for i in range(self.size):
#             for j in range(self.size):
#                 if(start[i][j]!=goal[i][j] and start[i][j]!="_"):
#                     # x,y=self.find_pos(start[i][j],goal)
#                     h_score+=1
#         return h_score
#     def calc_f_score(self,start,goal):
#         return self.calc_h_score(start.data,goal)+start.level
    
#     def process(self):
#         print("Enter the starting node: ")
#         start=self.read_puzzle()
#         print("Enter the goal node: ")
#         goal=self.read_puzzle()

#         start=Node(start,0,0)
#         start.f_score=self.calc_f_score(start,goal)
#         self.open.append(start)
#         while(self.open):
#             curr=self.open[0]
#             for i in curr.data:
#                 for j in i:
#                     print(j,end=" ")
#                 print()
#             self.cnt+=1
#             print("------------------------------")

#             if(self.calc_h_score(curr.data, goal) == 0):
#                 break
#             childs=curr.generate_child()
#             for child in childs:
#                 child.f_score=self.calc_f_score(child,goal)
#                 flag=True
#                 for c in self.open:
#                     if(c.data==child.data and c.f_score<child.f_score):
#                         flag=False
#                         break
#                 for c in self.close:
#                     if(c.data==child.data and c.f_score<child.f_score):
#                         flag=False
#                         break
#                 if(flag):
#                     self.open.append(child)
                
#             self.close.append(curr)
#             del self.open[0]
#             self.open.sort(key=lambda x: x.f_score)
# puzzle=Puzzle(3)
# puzzle.process()
# print(puzzle.cnt)
# print("Successful")

# import copy
# class Node:
#     def __init__(self,data,level,f_score):
#         self.data=data
#         self.level=level
#         self.f_score=f_score
    
#     def find_tile(self,tile):
#         for i in range(len(self.data)):
#             for j in range(len(self.data)):
#                 if(self.data[i][j]==tile):
#                     return i,j

#     def exchange(self,x0,y0,x1,y1):
#         if(x1>=0 and x1<len(self.data) and y1>=0 and y1<len(self.data)):
#             new_grid=copy.deepcopy(self.data)
#             new_grid[x0][y0],new_grid[x1][y1]=new_grid[x1][y1],new_grid[x0][y0]
#             return new_grid
#         return None
    

#     def generate_child(self):
#         x,y=self.find_tile("_")
#         pos_set=[[x,y-1],[x,y+1],[x-1,y],[x+1,y]]
#         children=[]
#         for pos in pos_set:
#             child=self.exchange(x,y,pos[0],pos[1])
#             if(child is not None):
#                 children.append(Node(child,self.level+1,0))
#         return children

# class Puzzle:
#     def __init__(self,size):
#         self.size=size
#         self.open=[]
#         self.close=[]
#         self.cnt=0
    
#     def read_puzzle(self):
#         puzzle=[]
#         for i in range(self.size):
#             row=input().split(" ")
#             puzzle.append(row)
#         return puzzle

#     def calc_h_score(self,start,goal):
#         h_score=0
#         for i in range(self.size):
#             for j in range(self.size):
#                 if(start[i][j]!=goal[i][j] and start[i][j]!="_"):
#                     h_score+=1
#         return h_score

#     def calc_f_score(self,start,goal):
#         return self.calc_h_score(start.data,goal)+start.level
    
#     def process(self):
#         start=self.read_puzzle()
#         goal=self.read_puzzle()
#         start=Node(start,0,0)
#         start.f_score=self.calc_f_score(start,goal)
#         self.open.append(start)
#         while(self.open):
#             curr=self.open[0]
#             for i in curr.data:
#                 for j in i:
#                     print(j,end=" ")
#                 print()
#             self.cnt+=1
#             print("-----------------")
#             if(self.calc_h_score(curr.data, goal) == 0):
#                 break
#             childs=curr.generate_child()
#             for child in childs:
#                 child.f_score=self.calc_f_score(child,goal)
#                 flag=True
#                 for c in self.open:
#                     if(c.data==child.data and c.data<child.data):
#                         flag=False
#                         break
#                 for c in self.close:
#                     if(c.data==child.data and c.data<child.data):
#                         flag=False
#                         break
#                 if(flag):
#                     self.open.append(child)
#             self.close.append(curr)
#             del self.open[0]
#             self.open.sort(key=lambda x:x.f_score)
# p=Puzzle(3)
# p.process()
# print(p.cnt)
# print("Successful")

import copy

class Node:
    def __init__(self,data,level,f_score):
        self.data=data
        self.level=level
        self.f_score=f_score

    def shuffle(self,puzzle,x0,y0,x1,y1):
        if(x1>=0 and x1<len(self.data) and y1>=0 and y1<len(self.data)):
            puzz=copy.deepcopy(puzzle)
            puzz[x0][y0],puzz[x1][y1]=puzz[x1][y1],puzz[x0][y0]
            return puzz
        return None

    def find_tile(self,puzzle,tile):
        for i in range(len(self.data)):
            for j in range(len(self.data)):
                if(puzzle[i][j]==tile):
                    return i,j

    def generate_child(self) :
        x,y=self.find_tile(self.data,"_")
        children=[]
        all_pos=[[x,y-1],[x,y+1],[x-1,y],[x+1,y]]
        for i in all_pos:
            puzz=self.shuffle(self.data,x,y,i[0],i[1])
            if(puzz is not None):
                children.append(Node(puzz,self.level+1,0))
        return children  

class Puzzle:
    def __init__(self,size):
        self.size=size
        self.open=[]
        self.close=[]
    
    def input(self):
        puzz=[]
        for i in range(self.size):
            row=input().split(" ")
            puzz.append(row)
        return puzz
    
    def find_pos(self,val,goal):
        for i in range(self.size):
            for j in range(self.size):
                if(goal[i][j]==val):
                    return i,j

    def calc_h_score(self,start,goal):
        h_score=0
        for i in range(len(start)):
            for j in range(len(start)):
                if start[i][j] != goal[i][j] and start[i][j] != '_':
                    x,y=self.find_pos(start[i][j],goal)
                    h_score+=(abs(i-x)+abs(j-y))
        return h_score
    
    def calc_f_score(self,start,goal):
        return self.calc_h_score(start.data,goal)+start.level
    
    def process(self):
        print("Enter the start matrix: " )
        start=self.input()
        print("Enter the goal matrix: ")
        goal=self.input()

        start=Node(start,0,0)
        start.f_score=self.calc_f_score(start,goal)
        self.open.append(start)
        print()
        while(self.open):
            curr=self.open[0]
            for i in curr.data:
                for j in i:
                    print(j,end=" ")
                print()
            print("-------------------")

            if(self.calc_h_score(curr.data,goal)==0):
                print("Execution Successful")
                break
            
            childs=curr.generate_child()
            for c in childs:
                c.f_score=self.calc_f_score(c,goal)
                flag=True
                for i in self.open:
                    if(c.data==i.data and i.f_score>c.f_score):
                        flag=False
                        break
                for i in self.close:
                    if(c.data==i.data and i.f_score>c.f_score):
                        flag=False
                        break
                
                if(flag):
                    self.open.append(c)
            self.close.append(curr)
            del self.open[0]
            self.open.sort(key=lambda x:x.f_score)
p=Puzzle(3)
p.process()
