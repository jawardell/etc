require 'digest'

puts "hi there. what's your name?"

name = gets.chomp
sha = Digest::SHA256.new
sha.digest name
puts name
puts sha
