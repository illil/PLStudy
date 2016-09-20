# Q1
def mask(s, is_front, no_chars, is_positive)
  no_mask_chars = is_positive ? s.size - no_chars : no_chars
  reg = is_front == is_positive ? ".{#{no_mask_chars}}$" : ".{#{no_mask_chars}}"
  s.sub(/#{reg}/, '*' * no_mask_chars)
end

# Q2
def freq(s)
  freq_count = {}
  s.each_char.with_index {|c, i| freq_count[c] ? freq_count[c][0] += 1 : freq_count[c] = [1, -i]}
  freq_count.sort_by {|k, v| v}.reverse.map {|k, v| k + v[0].to_s}.join
end

# Q3
def play(n, m)
  players = 1.upto(n).to_a
  start_position = 0
  loop do
    loser = (start_position + m) % players.count
    players.delete_at(loser)
    return players[0] if players.count == 1
    start_position = loser - 1
  end
end
