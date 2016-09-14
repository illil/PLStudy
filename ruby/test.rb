class FiboSequence
  def memorize_recursion(n)
    clear_memory
    memorize_recursion_calculate(n)
  end

  def recursion(n)
    recursion_calculate(n)
  end

  def looping(n)
    looping_calculate(n)
  end

  def check_time(n)
    print_time_stemp(n)
  end

  private

  attr_accessor :memory
  def clear_memory
    @memory = {}
  end

  def looping_calculate(n)
    pre = pre_pre = 1
    val = 0
    if n == 0 || n == 1
      val = 1
    else
      (n - 1).times do
        val = pre + pre_pre
        pre_pre = pre
        pre = val
      end
    end
    val
  end

  def memorize_recursion_calculate(n)
    return 1 if n == 0 || n == 1
    memory[n - 1] ||= memorize_recursion_calculate(n - 1)
    memory[n - 2] ||= memorize_recursion_calculate(n - 2)
    memory[n] ||= memory[n - 1] + memory[n - 2]
  end

  def recursion_calculate(n)
    return 1 if n == 0 || n == 1
    recursion_calculate(n - 1) + recursion_calculate(n - 2)
  end

  def print_time_stemp(n)
    puts "input: #{n}"
    puts "looping: #{time_by_type(& -> (*_args) { looping(n) })}"
    puts "memorize_recursion: #{time_by_type(& -> (*_args) { memorize_recursion(n) })}"
    puts "recursion: #{time_by_type(& -> (*_args) { recursion(n) })}"
  end

  def time_by_type(&_block)
    time = Time.now
    yield
    time_diff(time, Time.now)
  end

  def time_diff(start, finish)
    (finish - start) * 1000
  end
end

# f = FiboSequence.new
# f.recursion(6)
# f.memorize_recursion(6)
# f.looping(6)
# f.check_time(4)
# f.check_time(8)
# f.check_time(16)
# f.check_time(32)


class UnidirectionalLinkedList
  def initialize
    @list_size = 0
  end

  def push(value)
    push_node(Node.new(value))
  end

  def values
    return unless first
    current = first
    val = []
    list_size.times do
      val << current.value
      current = current.next_node
    end
    val
  end

  def reverse
    return unless first
    current = first
    last_temp = last
    prev = nil
    list_size.times do
      if current == last_temp
        current.next_node = prev
        @first = current
      else
        after = current.next_node
        current.next_node = prev
        prev = current
        current = after
        @last = prev if prev == first
      end
    end

    def pop
      return unless first
      @list_size -= 1
      if list_size == 0
        value = first.value
        @first = @last = nil
      else
        new_last = first
        (list_size - 1).times do
          new_last = new_last.next_node
        end
        value = last.value
        new_last.next_node = nil
        @last = new_last
      end
      value
    end

    def pop_front
      return unless first
      @list_size -= 1
      value = first.value
      @first = first.next_node
      @next = nil if first.nil?
      value
    end

    def size
      list_size
    end
  end

  private

  attr_accessor :first, :last, :list_size

  class Node
    attr_accessor :value, :next_node
    def initialize(value = nil, next_node = nil)
      @value = value
      @next_node = next_node
    end
  end

  def push_node(node)
    @list_size += 1
    if last
      last.next_node = node
      @last = node
    else
      @first = @last = node
    end
  end
end

# list = UnidirectionalLinkedList.new
# list.push(1)
# list.push(2)
# list.push(3)
# list.values
# list.reverse
# list.values
# list.push(4)
# list.push(8)
# list.values
# list.reverse
# list.values
# list.size
# list.pop
# list.size
# list.pop_front
# list.push(4)
# list.values
# list.pop
# list.pop
# list.pop
# list.pop

class TriEaterFirst
  def initialize
    reset
  end

  def new_game
    reset
  end

  def r
    rock
  end

  def s
    scissors
  end

  def p
    paper
  end

  def score
    display_status
    true
  end

  private

  attr_accessor :game, :win, :lose, :history

  def display_status
    puts "YOU WIN #{win}GAMES"
    puts "game: #{game}, lose: #{lose}, draw: #{game - win - lose}"
    puts "-------------------------------------"
    puts "result::"
    history.each do |h|
      puts h
    end
  end

  def rock
    status.push('rock')
    case app_action
    when 'rock'
      draw_game
    when 'paper'
      lose_game
    when 'scissors'
      win_game
    end
  end

  def paper
    status.push('paper')
    case app_action
    when 'rock'
      win_game
    when 'paper'
      draw_game
    when 'scissors'
      lose_game
    end
  end

  def scissors
    status.push('scissors')
    case app_action
    when 'rock'
      lose_game
    when 'paper'
      win_game
    when 'scissors'
      draw_game
    end
  end

  def status
    @status_temp ||= []
  end

  def reset_status
    @status_temp  = nil
  end

  def reset
    @game = 0
    @win = 0
    @lose = 0
    @history = []
  end

  def end_game
    @game += 1
    puts history.last
    reset_status
  end

  def draw_game
    mark_result('draw')
    end_game
  end

  def lose_game
    @lose += 1
    mark_result('lose')
    end_game
  end

  def win_game
    @win += 1
    mark_result('win')
    end_game
  end

  def mark_result(result)
    history.push("game_#{game + 1}:: you: #{status.first}, app: #{status.last}, result: #{result}")
  end

  def app_action
    action = action_name(rand(3))
    status.push(action)
    action
  end

  def action_name(action)
    case action
    when 0
      'rock'
    when 1
      'paper'
    when 2
      'scissors'
    end
  end
end

class TriEaterSeconde
  def initialize
    preset
  end

  def new_game
    reset
  end

  def score
    display_score
  end

  def rule
    show_rules
  end

  def r
    play_game(rock)
  end

  def s
    play_game(scissors)
  end

  def p
    play_game(paper)
  end

  private

  attr_accessor :game, :win, :lose, :history, :action_status
  attr_reader :rock, :paper, :scissors

  def preset
    @rock = 0
    @paper = 1
    @scissors = 2
    show_rules
    reset
  end

  def reset
    @game = 0
    @win = 0
    @lose = 0
    @history = []
    puts "START NEW GAME!!"
  end

  def play_game(action)
    app_action = rand(3)
    actions(action, app_action)
    result = action - app_action
    if result == 0
      draw_game
    elsif result == 1 || result == -2
      win_game
    else
      lose_game
    end
  end

  def actions(player_action, app_action)
    @action_status = [player_action, app_action]
  end

  def end_game
    @game += 1
    puts history.last
  end

  def draw_game
    mark_result('DRAW')
    end_game
  end

  def lose_game
    @lose += 1
    mark_result('LOSE')
    end_game
  end

  def win_game
    @win += 1
    mark_result('WIN')
    end_game
  end

  def mark_result(result)
    history.push("GAME #{game + 1}: #{result}!!! (you: #{action_name(action_status.first)}, app: #{action_name(action_status.last)})")
  end

  def action_name(action)
    case action
    when 0
      'rock'
    when 1
      'paper'
    when 2
      'scissors'
    end
  end

  def display_hline
    puts '------------------------------------------------'
  end

  def show_rules
    display_hline
    puts "WELCOME to 'Rock - Scissors - Paper'  GAME !!!"
    display_hline
    puts ':HOW TO PLAY ->'
    puts "ROCK IS 'instance.r'"
    puts "SCISSORS IS 'instance.s'"
    puts "PAPER IS 'instance.p'"
    puts "CHECK GAMES RESULT IS 'instance.score'"
    puts "RESET GAME RESULT IS 'instance.new_game'"
    puts "VIEW THIS MESSAGE AGAIN IS 'instance.rule'"
    display_hline
    puts 'LETS ROLL!! HAVE A GOOD TIME'
  end

  def display_score
    display_hline
    puts 'RESULT'
    display_hline
    history.each do |h|
      puts h
    end
    display_hline
    puts "game: #{game}, lose: #{lose}, draw: #{game - win - lose}"
    puts "YOU WIN #{win} GAMES"
  end
end

class TriEater
  def initialize
    preset
  end

  def new_game
    reset
  end

  def score
    display_score
  end

  def rule
    show_rules
  end

  def r
    play_game(rock)
  end

  def s
    play_game(scissors)
  end

  def p
    play_game(paper)
  end

  private

  attr_accessor :game, :win, :lose, :history, :action_status
  attr_reader :rock, :paper, :scissors, :win_game, :lose_game

  def preset
    @rock = 0
    @paper = 1
    @scissors = 2
    @win_game = 1
    @lose_game = 2
    show_rules
    reset
  end

  def reset
    @game = 0
    @win = 0
    @lose = 0
    @history = []
    puts 'START NEW GAME!!'
  end

  def play_game(player_action)
    update_result(player_action, app_action)
    display_result(history.last)
  end

  def app_action
    rand(3)
  end

  def game_result(player, app)
    result = player - app
    if result == 1 || result == -2
      win_game
    elsif result != 0
      lose_game
    end
  end

  def update_result(player, app)
    case game_result(player, app)
    when win_game
      @win += 1
    when lose_game
      @lose += 1
    end
    @game += 1
    history.push([player, app])
  end

  def result_name(player, app)
    case game_result(player, app)
    when win_game
      'WIN'
    when lose_game
      'LOSE'
    else
      'DRAW'
    end
  end

  def action_name(action)
    case action
    when rock
      'rock'
    when paper
      'paper'
    when scissors
      'scissors'
    end
  end

  def display_hline
    puts '------------------------------------------------'
  end

  def display_result(status, index = game)
    puts "GAME #{index}: #{result_name(status.first, status.last)} (you: #{action_name(status.first)}, app:#{action_name(status.last)})"
  end

  def show_rules
    display_hline
    puts "WELCOME to 'Rock - Scissors - Paper'  GAME !!!"
    display_hline
    puts ':HOW TO PLAY ->'
    puts "ROCK IS 'instance.r'"
    puts "SCISSORS IS 'instance.s'"
    puts "PAPER IS 'instance.p'"
    puts "CHECK GAMES RESULT IS 'instance.score'"
    puts "RESET GAME RESULT IS 'instance.new_game'"
    puts "VIEW THIS MESSAGE AGAIN IS 'instance.rule'"
    display_hline
    puts 'LETS ROLL!! HAVE A GOOD TIME'
  end

  def display_score
    display_hline
    puts 'RESULT'
    display_hline
    history.each.with_index(1) { |s, i| display_result(s, i) }
    display_hline
    puts "game: #{game}, lose: #{lose}, draw: #{game - win - lose}"
    puts "YOU WIN #{win} GAMES"
  end
end
