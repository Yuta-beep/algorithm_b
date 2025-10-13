# STcountNode Notes

- **Recursive structure**  
  Each call solves the same shape: current node plus its left and right subtrees. This repetition lets the algorithm walk down to the leaves with one rule set.

- **Sentinel `z` handling**  
  The sentinel represents an empty subtree, so return immediately when `h == z`. A guard like `if (h == z) return 0;` keeps the count limited to real nodes.

- **Aggregating the totals**  
  Start from `ct = 1` for the current node, then fold in the child results via `ct += STcountNode(h->r);` and `ct += STcountNode(h->l);`. The subtree size is built entirely from recursive returns.

- **Overall pattern**  
  1. Guard against the empty case.  
  2. Initialise with the current node’s contribution.  
  3. Recurse on children and add their totals.  
  4. Return the accumulated count.  
  This template works for counting nodes, summing weights, and other bottom-up tree aggregations.

- **Practice tips**  
  Trace `ct` by hand on a tiny tree, compare with a NULL-pointer version, then adapt the pattern to compute height or leaf counts to cement the idea.
