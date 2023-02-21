def total_fruit(fruits)
  frequency = {}
  baskets = 2
  fruits_picked = []
  largest_pickup = 0
  for fruit in fruits do
    fruits_picked << fruit
    frequency.key?(fruit) ? frequency[fruit]+=1 : frequency[fruit]=1
    while frequency.keys.length > baskets
      frequency[fruits_picked[0]] -= 1
      frequency.delete(fruits_picked[0]) if frequency[fruits_picked[0]] == 0
      fruits_picked = fruits_picked.slice(1..-1)
    end
    largest_pickup = fruits_picked.length if fruits_picked.length > largest_pickup
  end
  largest_pickup
end
