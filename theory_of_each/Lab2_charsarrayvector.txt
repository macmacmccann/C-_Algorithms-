You built the BST from this sorted vector:
A B C D E F G H I J K L
Your recursive rule was:
Middle becomes root
Left half → left subtree
Right half → right subtree
🌳 Step-by-Step Construction
1️⃣ First call
Range: A–L
Middle = F
So F becomes the root
2️⃣ Left side of F
Range: A–E
Middle = C
So C becomes left child of F
3️⃣ Right side of F
Range: G–L
Middle = I
So I becomes right child of F
Now it keeps splitting the same way.
✅ Final Tree Structure
Here is the full tree:
                F
           /          \
          C            I
        /   \        /   \
       A     D      G     K
        \     \      \     \
         B     E      H     L
🔍 Why It Looks Like That
Each level is built by picking the middle of the remaining range:
Subarray
Middle
Position
A–L
F
Root
A–E
C
F left
G–L
I
F right
A–B
A
C left
D–E
D
C right
G–H
G
I left
J–L
K
I right
And so on.
📈 Why Inorder Prints Alphabetical Order
Remember:
Inorder = Left → Root → Right
So it visits:
A B C D E F G H I J K L
Which is sorted order ✅
🧠 Important Concept
Because we always choose the middle element:
The tree is balanced
Search time is O(log n)
Height is minimal
If you inserted A–L one at a time in order, you’d get a tall skinny tree instead.
If you want, I can also draw how it would look if you inserted A–L one by one so you can see the difference (this is usually tested on exams 👀).