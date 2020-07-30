                                                   
st = input("pls enter student details: ")  
student_db = {}
while(st != "end"):
    ind = st.find(' ') 
    student_db[st[:ind]] = st[ind + 1:]     
    st = input("pls enter student details: ")

roll = input("psl enter roll no : ")
while(roll != 'X'):
    print(student_db[roll])    
    roll = input("psl enter roll no : ")


#     MEMORY

# st = "end"
# student_db = {'200' : 'nehu', '201' : 'gandalf', '20' : '10gandalf'}
# ind = 2
# roll = "X"
