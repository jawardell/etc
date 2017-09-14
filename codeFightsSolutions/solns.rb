def add(param1, param2)
    return param1  + param2
end



def centuryFromYear(year)
    if year % 100 == 0
        return year / 100
    end
    return year / 100 + 1
end



def checkPalindrome(inputString)
    array = inputString.chars
    high = array.length-1
    low = 0
    for i in 0..array.length
        if low > high
            return true
        end
        if array[high] != array[low]
            return false
        end
        high -= 1
        low += 1
    end
        
end




def adjacentElementsProduct(inputArray)
    max = -999999999;
    for i in 0..inputArray.length-2
        if inputArray[i] * inputArray[i+1] > max
            max = inputArray[i] * inputArray[i+1]
        end
    end
    return max;
end



def allLongestStrings(inputArray)
    count = 0
    max = 0
    inputArray.each do |n|
         if n.length > max
            max = n.length
        end
    end
    array = Array.new()
    inputArray.each do |n|
        if n.length == max
            array << n
        end
    end
    return array
end



def makeArrayConsecutive2(statues)
    count = 0
    for i in 0..statues.length-1
        if statues[i+1] - statues[i]
            count += statues[i+1] - statues[i]
        end
    end
    return count
end



def areSimilar(a, b)
    for i in (a.length-1).downto(0)
        if a[i] == b[i]
            a.delete_at(i)
            b.delete_at(i)
        end
    end
    if a.length > 2
        return false
    end
    return a.sort == b.sort
    
end



