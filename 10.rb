# 1. Function rand(n+1) returns a random integer between 0 and n. 
# Write a function that creates an array of 100 random numbers between 0 and 10 
# [slide 143]
def arrayManip
	Array.new(100) {rand(10+1)}
end

# 2. Make a function show(v) that displays the array v 
# [slides 137, 143].
def show (v)
	v.each do  |element|
		print " #{element} "
	end
end

=begin
3. Make a function hist(v) that plots a histogram of values stored in array v. For example:
0 **********
1 ********
2 *********
3 ***********
4 *******
5 ************
6 ***********
7 *********
8 *************
9 ***********
10 *********
=end
def hist(v)
	i=0
	v.each do |val|
		print "\n#{i} (#{val})\t "
		count = 0
		while count < val do
			print "*"
			count+=1
		end
		i+=1
	end
end

# 4.Write a function mean(v) that returns the mean value of 
# numbers stored in the array v.
def mean(v)
	count = 0
	i = 0
	avg=0
	
	v.each do |val|
		count += val
		i += 1
	end
	
	return avg = count / i

end

# 5. Write a function sigma(v) that returns the standard 
# deviation of numbers stored in the array v.
def sigma(v)
	count = 0
	i = 0
	avg=0
	
	v.each do |val|
		count += val
		i += 1
	end
	
	avg = count / i
	newAvg=0
	v.each do |val|
		val = val-avg	#replace value with old one
		val = val * val	#square values
		newAvg += val	#add the positive values
	end
	newAvg = newAvg / (i-1)	# divide new avg by size-1
	sigma = Math.sqrt(newAvg)

	return sigma
end

# 6. Write a function mean_sigma(v) that returns two values: the mean value 
# and the standard deviation of numbers stored in the array v 
# [Slide 141 shows how to return two values]

def mean_sigma(v)
	count = 0
	i = 0
	mean=0
	
	v.each do |val|
		count += val
		i += 1
	end
	
	mean = count / i
	newAvg=0
	v.each do |val|
		val = val-mean	#replace value with old one
		val = val * val	#square values
		newAvg += val	#add the positive values
	end
	newAvg = newAvg / (i-1)	# divide new avg by size-1
	sigma = Math.sqrt(newAvg)
	return mean, sigma
end

# 7. Write a function sort(v) that returns the sorted array v. 
# Do not use Ruby sort methods; write your own sort. 
# Array v must remain unchanged. [Slide 137 shows how to return an array]
def sort(v)
	a=v	#make a copy so original is unchanged.
   return a if a.size <= 1 # already sorted

  0.upto(a.length-2) do |i|
    min = i # smallest value
    (i+1).upto(a.length-1) { |j| min = j if a[j] < a[min] } # find new smallest
    a[i], a[min] = a[min], a[i] if i != min #swap values
  end

  return a
end

=begin
8. Write a function binarysearch(v, x) that returns the index i of the 
sorted array v where v[i]=x. 
Return -1 if x does not belong to v.
(using the iterative search method)
=end
def binarysearch(v,x)
	newmin=0
	newmax=v.length
	newmid=0
	
	if x > v.length
		return -1	# key not in array.
	else
		while newmin <= newmax do
			newmid = (newmin+newmax)/2
			if v[newmid] < x
				newmin = newmid+1
			elsif v[newmid] > x
				newmax = newmid - 1
			else	# key is found 
					return newmid
			end
		end
	end
end

# 9. Write function minmax(v) that returns minimum and maximum 
# value of the array v. [Slide 141]
def minmax(v)
	min = v[0].to_s.to_i
	max = v[0].to_s.to_i
	
	for i in v do
		if v[i].to_s.to_i > max.to_s.to_i
			max = v[i]
		end
		if v[i].to_s.to_i <= min.to_s.to_i
			min = v[i]
		end
	end
	return min, max
end

# 10. Write a main program that illustrates the work of all the above functions.
puts "1. Array creation"
print array = arrayManip
puts;puts 

puts "2. Showing array"
print show(array)
puts;puts 

puts "3. Histogram of array"
hist(array)
puts;puts 

puts "4. Mean of array"
print mean(array)
puts;puts 

puts "5. Sigma of array"
print sigma(array)
puts;puts 

puts "6. Mean AND Sigma of array"
print mean_sigma(array)
puts;puts 

puts "7. Unsorted array"
show(array)
puts;puts 
puts "   Sorted Array"
print sort(array)
puts;puts 

puts "8. Binary search of array, key = 3"
print binarysearch(array, 3)
puts;puts 

puts "9. Min & Max of array"
print minmax(array)
puts;puts 
