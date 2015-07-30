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
