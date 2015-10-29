#ifndef __APAYI_PAYMENT__
#define __APAYI_PAYMENT__

#include <string>
#include <ostream>
#include <vector>
#include "refund.h"

namespace apayi
{
using std::string;
using std::ostream;
using std::vector;

class payment
{
public:
	payment(
		const string& amount,
		const int created_at,
		const string& currency,
		const string& description,
		const string& entity,
		const string& order_id,
		const string& payment_mode,
		const string& status,
		const string& id,
		vector<refund> refunds
	);

private:
	string amount_;
	int created_at_;
	string currency_;
	string description_;
	string entity_;
	string order_id_;
	string payment_mode_;
	string status_;
	string id_;
	vector<refund> refunds_;

public:
	string amount() const { return amount_;}
	int created_at() const { return created_at_;}
	string currency() const { return currency_;}
	string description() const { return description_;}
	string entity() const { return entity_;}
	string order_id() const { return order_id_;}
	string payment_mode() const { return payment_mode_;}
	string status() const { return status_;}
	string id() const { return id_;}
	vector<refund> refunds() const { return refunds_; }
};

ostream& operator<< (ostream& os, const payment &p);

}
#endif
