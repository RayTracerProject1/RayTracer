// Add two vectors and return the resulting vector
vector vectorAdd(vector *v1, vector *v2){
        vector result = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z };
        return result;
}

// Subtract two vectors and return the resulting vector
vector vectorSub(vector *v1, vector *v2){
        vector result = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z };
        return result;
}

// Multiply two vectors and return the resulting scalar (dot product)
double vectorDot(vector *v1, vector *v2){
        return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

// Calculate Vector x Scalar and return resulting Vector
vector vectorScale(double c, vector *v){
        vector result = {v->x * c, v->y * c, v->z * c };
        return result;
}

// Calculate vector cross product and return resulting vector
vector vectorCross(vector *v1, vector *v2){
	vector result;

	result.x = (v1->y * v2->z) - (v1->z * v2->y);
	result.y = (v1->z * v2->x) - (v1->x * v2->z);
	result.z = (v1->x * v2->y) - (v1->y * v2->x);

	return result;
}
