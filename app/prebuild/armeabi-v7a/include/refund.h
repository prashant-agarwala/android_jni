#ifndef __APAYI_REFUND_H__
#define __APAYI_REFUND_H__

#include <string>
#include <ostream>

namespace apayi
{
using std::string;
using std::ostream;

class refund
{
public:
	refund(
		const string& amount,
		const int created_at,
		const string& currency,
		const string& entity,
		const string& notes,
		const string& payment_id,
		const string& id
	);

private:
	string amount_;
	int created_at_;
	string currency_;
	string entity_;
	string notes_;
	string payment_id_;
	string id_;

public:
	string amount() const { return amount_;}
	int created_at() const { return created_at_;}
	string currency() const { return currency_;}
	string entity() const { return entity_;}
	string notes() const { return notes_;}
	string payment_id() const { return payment_id_;}
	string id() const { return id_;}
};

ostream& operator<< (ostream& os, const refund &p);

}

#endif
