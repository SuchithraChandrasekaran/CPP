1. std::set

Properties: Stores unique elements in sorted order.
Internals: Implemented using a balanced binary search tree (e.g., Red-Black Tree).
Key Features: Fast search, insertion, and deletion (O(log n)).

When to Use:

When you need a collection of unique elements.
When you require elements to be stored in sorted order for efficient range-based queries.
When you need fast lookups or modifications with logarithmic complexity.

Use Cases:

Maintaining a Leaderboard:
    Store unique player scores in sorted order for easy ranking.
Processing Unique Values:
    Remove duplicates from a collection and keep the result sorted.
Efficient Range Queries:
    Use lower and upper bound to find elements within a specific range.

2. std::multiset

Properties: Allows duplicate elements, still maintains sorted order.
Internals: Similar to std::set but permits duplicates.
Key Features: Useful for frequency counting or when duplicates are needed.

When to Use:

When duplicates are allowed and you need elements in sorted order.
When you need frequency tracking of sorted elements.
When you want efficient logarithmic complexity for insertion, deletion, and searching.

Use Cases:

Inventory Management:
    Store multiple identical items in a sorted manner.
Frequency Count:
    Use to count occurrences of elements while maintaining sorted order.
Custom Comparisons:
    Use a custom comparator to sort by specific criteria (e.g., descending order).

3. std::unordered_set
Properties: Stores unique elements, but in no particular order.
Internals: Implemented using a hash table.
Key Features: Fast average-time search, insertion, and deletion (O(1) average, O(n) worst case).

When to Use:

When order doesn’t matter.
When you only care about unique elements and need faster average constant-time operations.
When performance is critical for lookups or inserts.

Use Cases:

Set Membership Tests:
    Quickly check if an element exists (e.g., word filtering in a dictionary).
Large Data Deduplication:
    Handle large collections of unique values with fast insertion.
Hash-based Applications:
    Use as a backing data structure for hash-based algorithms.

4. std::unordered_multiset

Properties: Allows duplicate elements, elements are unordered.
Internals: Similar to std::unordered_set but permits duplicates.
Key Features: Fast average-time operations and allows duplicates.

When to Use:

When order doesn’t matter and duplicates are allowed.
When you need efficient average constant-time operations for insertion and lookup.

Use Cases:

Counting Elements in Unordered Data:
    Count duplicates without worrying about sorting (e.g., word frequencies in text).
Grouping Elements:
    Use for grouping and hashing items that can appear multiple times.
Bag Data Structures:
    Useful for modeling bag-like collections where duplicates matter but order doesn’t.

Summary of Differences:

Type                        Duplicates         Order           Time Complexity 			Key Use Case

std::set                    No                 Sorted          O(log n)  					Unique elements in sorted order, range-based queries.
std::multiset               Yes                Sorted          O(log n) 					Handling duplicates in sorted order, frequency tracking.
std::unordered_set          No                 Unordered       O(1) average, O(n) worst 	Unique elements with fast lookups, no order needed.
std::unordered_multiset     Yes                Unordered       O(1) average, O(n) worst 	Handling duplicates with fast lookups, no order needed.
