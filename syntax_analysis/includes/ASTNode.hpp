class ExpressionNode {
  private:
    char c;
    ExpressionNode n1;
    ExpressionNode n2;

  public:
    ExpressionNode(char number){
      this->c = number;
      this->n1 = this->n2 = nullptr;
    }
};
