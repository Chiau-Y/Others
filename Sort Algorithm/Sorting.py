# ------------------------------------ Check Answer ---------------------------------- #
def Check_Answer(test):
    if test == [2, 3, 3, 3, 4, 5, 5, 7, 8, 15, 17, 20]:
        pass
    else:
        print("Wrong...")
        
# ------------------------------------ Swap ---------------------------------- #
def swap(a, b):
    return b, a

# ------------------------------------ Bubble Sort ---------------------------------- #
def Bubble_Sort(test_list):
    
    for i in range (len(test_list)):
        for j in range (1,len(test)):
            if test_list[j-1] > test_list[j] :
                test_list[j-1], test_list[j] = swap(test_list[j-1], test_list[j])
                
    Check_Answer(test_list)
    print("After Bubble Sort = ", test_list)
    
# ------------------------------------ Insertion Sort ---------------------------------- #
def Insertion_Sort(test_list):
    
    for i in range (1,len(test_list)):
        temp = test_list[i]
        for j in range (i, 0, -1):   # from i to 1
            if test_list[j] < test_list[j-1]:
                test_list[j-1], test_list[j] = swap(test_list[j-1], test_list[j])
    
    Check_Answer(test_list)
    print("After Insertion Sort = ", test_list)
    
# ------------------------------------ Selection Sort ---------------------------------- #
def Selection_Sort(test_list):
    
    for i in range (len(test)):
        index_min = i # record the index of the min number
        for j in range (i+1, len(test)):
            if test_list[j] < test_list[index_min]:
                index_min = j
        test_list[i], test_list[index_min] = swap(test_list[i], test_list[index_min])
    
    Check_Answer(test_list)
    print("After Selection Sort = ", test_list)
    
# ------------------------------------ Main ---------------------------------- #
if __name__ == '__main__':    
    
    # Should be [2, 3, 3, 3, 4, 5, 5, 7, 8, 15, 17, 20]
    test = [3, 8, 7, 5, 17, 3, 2, 20, 15, 4, 3, 5]
    
    print("Before Sorting = ", test)
    
    # Bubble_Sort(test)
    # Insertion_Sort(test)
    Selection_Sort(test)