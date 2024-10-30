#include "PolyNode.h"

class Solution {
public:
    PolyNode *addPoly(PolyNode *poly1, PolyNode *poly2) {
        auto dummy = new PolyNode();
        auto p = dummy;
        while (poly1 || poly2) {
            if (!poly2 || (poly1 && poly1->power > poly2->power)) {
                p->next = poly1;
                poly1 = poly1->next;
                p = p->next;
            } else if (!poly1 || (poly2 && poly2->power > poly1->power)) {
                p->next = poly2;
                poly2 = poly2->next;
                p = p->next;
            } else {
                int c = poly1->coefficient + poly2->coefficient;
                if (c) {
                    p->next = new PolyNode(c, poly1->power);
                    p = p->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        p->next = nullptr;
        return dummy->next;
    }
};