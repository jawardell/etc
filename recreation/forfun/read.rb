File.open("file", "r") do |f|
	f.each_line do |line|
		nums = line.split().map(&:to_i).each do |n|	
			print "#{n.to_s(16)} "
		end
		puts "\n"
	end
end
