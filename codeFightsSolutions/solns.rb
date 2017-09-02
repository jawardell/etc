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

