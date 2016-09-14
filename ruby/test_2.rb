# Q1
def mask(s, is_front, no_chars, is_positive)
  return 'string is too short' if s.size < no_chars
  s_size = s.size
  split_position = is_front ? no_chars : s.size - no_chars
  first = s[0...split_position]
  last = s[split_position..s_size]
  return first + '*' * last.size if is_front == is_positive
  '*' * first.size + last
end

# Q2
def freq(string)
  result = {}
  string.each_char { |s| result[s] = result[s] ? result[s] + 1 : 1 }
  result.sort_by { |_, v| v }.reverse.join
end

# Q3
def play(n, m)
  player = 1.upto(n).to_a
  loser = 0
  old_player_count = 0
  loop do
    player_count = player.count
    return player.join if player_count == 1
    start_position = loser + m - old_player_count
    loser = start_position % player_count
    player.delete_at(loser)
    old_player_count = player_count
  end
end

def play2(n, m)
  a = n.times.to_a

  i = 0
  (n - 1).times do
    i = (i + m) % a.size
    a.delete_at(i)
    i -= 1
  end

  a[0] + 1
end

def play3(n, m)
  players = 1.upto(n).to_a

  start_position = 0
  (n - 1).times do
    loser = (start_position + m) % players.count
    players.delete_at(loser)
    start_position = loser - 1
  end

  players[0]
end
